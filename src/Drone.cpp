
#include "Drone.hh"

Drone::Drone(int index, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja) : Lacze(Lacze)
{
    kat = 0;
    this->index = index;
    orginal.ustaw_nazwe("../datasets/korpus" + std::to_string(index) + ".dat");

    for (int i = 0; i < 4; i++)
        orginal_wirnika[i].ustaw_nazwe("../datasets/wirnik" + std::to_string(i) + std::to_string(index) + ".dat");

    Lacze.DodajNazwePliku(orginal.wez_nazwe().c_str(), PzG::RR_Ciagly, 2);
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(orginal_wirnika[i].wez_nazwe().c_str(), PzG::RR_Ciagly, 2);
    kopia = orginal;

    kopia.przesun(pozycja);
    for (int i = 0; i < 4; i++)
        kopia_wirnika[i] = orginal_wirnika[i];

    for (int i = 0; i < 4; i++)
        kopia_wirnika[i].przesun(orginal[i * 2] + pozycja);

    this->droga = this->droga + pozycja;
}

void Drone::animacja(double droga)
{
    Vector3D droga_o;
    droga_o[2] = droga;

    this->droga = this->droga + droga_o;
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}

void Drone::przesun(double droga)
{
    Vector3D droga_o;
    droga_o[0] = droga * cos(kat * M_PI / 180);
    droga_o[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_o;
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}

void Drone::obrot(double kat)
{
    this->kat += kat;
    Matrix3x3 nowa;
    obr = nowa * macierz_obrot_z(this->kat);
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}
void Drone::obrot_rotrow()
{
    static int kat = 0;
    kat += 3;
    if (kat == 360)
        kat = 0;

    Matrix3x3 nowa;
    nowa = nowa * macierz_obrot_z(kat);
    for (int i = 0; i < 4; i++)
    {
        kopia_wirnika[i].obrot(nowa);
    }

    for (int i = 0; i < 4; i++)
    {
        kopia_wirnika[i].przesun(kopia[i * 2]);
    }
}

void Drone::zapisz()
{
    kopia.zapisz();
    for (int i = 0; i < 4; i++)
        kopia_wirnika[i].zapisz();
}

void Drone::sterowanie()
{
    double droga;
    double kat;
    char opcja;

    zapisz();
    cout << "Wybierz opcje :" <<endl;
    cout << "p - przesun drona o zadany wektor"<<endl;
    cout << "o - obroc drona o zadany kat (w stopniach)"<<endl;
    cout << "m - menu" <<endl;
    cout << "d - dodaj element" <<endl;
    cout << "k - koniec" <<endl;
    cin >> opcja;
    switch (opcja)
    {
    case 'p':
        cout << "Podaj wektor przelotu :" <<endl;
        cin >> droga;
        prosta(droga);
        Lacze.DodajNazwePliku("../datasets/droga.dat", PzG::RR_Ciagly, 2);
        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wirnika[j] = orginal_wirnika[j];
            animacja(1);
           obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }

        for (int i = 0; i < droga; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wirnika[j] = orginal_wirnika[j];
            przesun(1);
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }

        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
                kopia_wirnika[j] = orginal_wirnika[j];
            animacja(-1);
          obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
        Lacze.UsunOstatniaNazwe();
        break;
    case 'o':
        cout << "Podaj kat obrotu:";
        cin >> kat;
        if (kat > 0)
        {
            for (int i = 0; i < kat; i++)
            {
                kopia = orginal;
                for (int i = 0; i < 4; i++)
            kopia_wirnika[i] = orginal_wirnika[i];
                obrot(1);
            obrot_rotrow();
                zapisz();
                Lacze.Rysuj();
                usleep(CZAS);
            }
        }
        else
        {
            for (int i = 0; i > kat; i--)
            {
                kopia = orginal;
                obrot(-1);
               obrot_rotrow();
                zapisz();
                Lacze.Rysuj();
                usleep(CZAS);
            }
        }

        break;
        case 'm':
        {

        } break;
        case 'd':
        {

        } break;
        case 'k':
        break;
    default:
    {
    cout<<"Bledna opcja"<<endl;}
        break;
    }
}

void Drone::prosta(double droga)
{
    Vector3D nastepny = kopia.wez_srodek();
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);
    nastepny[2] = 100;
    droga_drona.push_back(nastepny);
    nastepny[0] += droga * cos(kat * M_PI / 180);
    nastepny[1] += droga * sin(kat * M_PI / 180);
    droga_drona.push_back(nastepny);
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);

    std::fstream plik;

    plik.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)droga_drona.size(); i++)
    {

        plik << droga_drona[i] << std::endl;
    }
    plik.close();
}