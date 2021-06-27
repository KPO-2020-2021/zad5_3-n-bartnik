
#include "Drone.hh"

Drone::Drone(int index, PzG::LaczeDoGNUPlota &Lacze, Vector3D pozycja) : Lacze(Lacze)
{
    kat = 0;
   // this->index = index;
    orginal.ustaw_nazwe("../datasets/korpus" + std::to_string(index) + ".dat");

    for (int i = 0; i < 4; i++)
        orginal_wirnika[i].ustaw_nazwe("../datasets/wirnik" + std::to_string(i) + std::to_string(index) + ".dat");

    Lacze.DodajNazwePliku(orginal.wez_nazwe().c_str(), PzG::RR_Ciagly, 2);
    for (int i = 0; i < 4; i++)
        Lacze.DodajNazwePliku(orginal_wirnika[i].wez_nazwe().c_str(), PzG::RR_Ciagly, 2);

        /*do kopii przypisywany jest orginał, żeby nie musieć pracować na orygnałach*/
    kopia = orginal;

    promien_kopia = kopia.promien();

    kopia.przesun(pozycja);
    for (int i = 0; i < 4; i++)
        kopia_wirnika[i] = orginal_wirnika[i];

    for (int i = 0; i < 4; i++)
        kopia_wirnika[i].przesun(orginal[i * 2] + pozycja);

    this->droga = this->droga + pozycja;
}


/*!
    \brief
    *Animacja lotu drona. 
    *Do funkcje wysyłamy wektor drogi, a w nim tworzymy drogę wypadkową, do której współrzędniej z przypisujemy drogę włąściwą.
    *Następnie przesuwamy i obracamy drona (wstępny obrót o 0 stopni)

*/
void Drone::animacja(double droga)
{
    Vector3D droga_pom;
    droga_pom[2] = droga;

    this->droga = this->droga + droga_pom;
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}


/*!
    \brief
    *Funkcja przesunięcia - przesun. 
    *Do funkcje wysyłamy wektor drogi, a w nim tworzymy drogę wypadkową, do której współrzędniej z przypisujemy drogę włąściwą przemnożoną przez funkcję trygonometryczną zgodnie z instrukcją do zadania.
    *Następnie przesuwamy drona poprzez dodanie drogi i drogi_pom do siebie i obracamy drona (wstępny obrót o 0 stopni)

*/
void Drone::przesun(double droga)
{
    Vector3D droga_pom;
    droga_pom[0] = droga * cos(kat * M_PI / 180);
    droga_pom[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_pom;
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}


/*!
    \brief
    *Funkcja obrotu - obrot. 
    *Do funkcje wysyłamy kat, a w nim tworzymy macierz wypadkową, do której przypisujemy macierz pomocniczą przemnożoną przez funkcję macierz_obrot_z (o zadany kąt wokół osi OZ).
    *Następnie przesuwamy drona o wektor zerowy i obracamy drona (o wyliczony kąt obr)

*/
void Drone::obrot(double kat)
{
    this->kat += kat;
    Matrix3x3 mac_pom;
    obr = mac_pom * macierz_obrot_z(this->kat);
    kopia.obrot(obr);
    kopia.przesun(this->droga);
}



/*!
    \brief
    *Funkcja obrotu rotorów - obrot_rotorow. 
    *W funkcji deklarowany jest kąt początkowy, do którego dodawana jest 2. Następnie tworzona jest macierz pomocnicza. Po wymnożeniu jej wokół osi OZ w pętli każdy rotor jest obracany
    *za pomocą funkcji obrot o zadaną macierz i przesuwany.

*/
void Drone::obrot_rotrow()
{
    static int kat = 0;
 kat += 2; //obrot poczatkowy
    if (kat == 360){
        kat = 0;
        //360==0
        }

    Matrix3x3 mac_pom;
    mac_pom = mac_pom * macierz_obrot_z(kat); //wokół osi OZ
    for (int i = 0; i < 4; i++)
    {
        kopia_wirnika[i].obrot(mac_pom);
    }

    for (int i = 0; i < 4; i++)
    {
        kopia_wirnika[i].przesun(kopia[i * 2]);
    }
}

/*!
        Lacze.UsunOstatniaNazwe();
        break;
    }

*/

void Drone::zapisz()
{
    kopia.zapisz();
    for (int i = 0; i < 4; i++)
        kopia_wirnika[i].zapisz();
}


/*!
    \brief
    *Funkcja sterowanie
    *Umożliwia sterowanie dronem oraz zapewnia użytkownikowi menu 
    *Umożliwia wybranie obrotu lub przesunięcia drona. Po wybraniu odpowiedniej opcji, realizuje ją.
    *Gdy użytkownik wybierze opcję p, musi podać drogę przesunięcia, rysuje drogę w gnuplocie za pomocą funkcji prosta, a następnie przypisuje oryginał korpusu i wirników do kopii. Za pomocą funkcji animacja przesuwa drona o 1 do góry w czasie (usesleep) 100 razy i obraca rotory.
    *Następnie funkcja wykonuje zadany ruch i sprawdza, czy jest miejsce do lądowania. Jeśli nie - dron porusza się dalej o drogę równą 50. Jeżeli jest miejsce - dron ląduje.
    *Gdy użytkownik wybierze opcję o - obrót, musi podać kąt obrotu w stopniach. W zależności od podanego kąta, dron obraca się o 1 lub o -1 tyle razy, ile jednostek zmieści się w zadanym kącie. 
    *Do kopii przypisywany jest oryginał korpusu i rotorów, rotory obracają się też. Wszystko to w czasie (usleep)
    * 
*/
void Drone::sterowanie(std::list<std::shared_ptr<Object>> &lista)
{
    lista = lista; //pom
    double droga;
    double kat;
    char opcja;

    zapisz();
    cout << "Wybierz opcje :" << endl;
    cout << "p - przesun drona o zadany wektor" << endl;
    cout << "o - obroc drona o zadany kat (w stopniach)" << endl;
    cin >> opcja;
    switch (opcja)
    {
    case 'p':
    {
        cout << "Podaj wektor przelotu :" << endl;
        cin >> droga;
        /*rysuje droge przelotu*/
        prosta(droga);
        Lacze.DodajNazwePliku("../datasets/droga.dat", PzG::RR_Ciagly, 2);
        /*Wykonuje 100 małych ruchów*/
        for (int i = 0; i < 100; i++)
        {
            /*praca na kopiach*/
            kopia = orginal;
            for (int j = 0; j < 4; j++)
            {
                kopia_wirnika[j] = orginal_wirnika[j];
            }
            animacja(1); //przesunięcie o 1
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS); //Zapewnia przesunięcie nie natychmiastowe
        }

        bool miejsce = false; //wartość początkowa
        while (true)
        {

            for (int i = 0; i < droga; i++)
            {
                kopia = orginal;
                for (int j = 0; j < 4; j++)
                {
                    kopia_wirnika[j] = orginal_wirnika[j];
                }
                przesun(1); //przesuniecie o 1 == animacja o 1
                obrot_rotrow();
                zapisz();
                Lacze.Rysuj();
                usleep(CZAS);
            }

            for (std::list<std::shared_ptr<Object>>::const_iterator i = lista.begin(); i != lista.end(); i++)
            {
                kopia = orginal;
                animacja(-100);
                if (sprawdzaj_miejsce(*i) == true)
                {
                    cout << "Napotkana przeszkoda: " << (*i)->wez_nazwe() << endl;  //wypisuje przeszkodę, którą napotkał dron
                    miejsce = true;
                }
                kopia = orginal;
                animacja(100);
            }

            if (miejsce == false)
            {
                break;
            }
            miejsce = false;
            droga = 50; //przesuwa sie o 50
            prosta(droga); //rysuje dodatkową drogę
        }

        /*opadanie*/
        for (int i = 0; i < 100; i++)
        {
            kopia = orginal;
            for (int j = 0; j < 4; j++)
            {
                kopia_wirnika[j] = orginal_wirnika[j];
            }
            animacja(-1);
            obrot_rotrow();
            zapisz();
            Lacze.Rysuj();
            usleep(CZAS);
        }
        Lacze.UsunOstatniaNazwe();
        break;
    }
    case 'o':
    {
        cout << "Podaj kat obrotu:";
        cin >> kat;
        if (kat > 0)
        /*obrót o 1 lub -1 powtarzany tyle razy ile 1 zmieści się w kat*/
        {
            for (int i = 0; i < kat; i++)
            {
                kopia = orginal;
                for (int i = 0; i < 4; i++)
                {
                    kopia_wirnika[i] = orginal_wirnika[i];
                }
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
    }
    }
}


/*!
    \brief
    *Funkcja sprawdzaj_miejsce. 
    *Do funkcje wysyłamy shared pointer typu Object i tworzymy shared pointer dla drona. Jesli dron i object są różne (czyli obiekt nie jest dronem) pobieramy ich środki i liczymy odległość length w zależności od której wycznaczamy, czy dron ma się dalej przesunąć, czy nie.

*/
bool Drone::sprawdzaj_miejsce(shared_ptr<Object> object)
{

    /*tworzenie shared pointera Drone bez koniecznosci tworzenia duplikatu*/
    std::shared_ptr<Drone> drone = shared_from_this();

    if (object != drone)
    {

        Vector3D srodek_drona = kopia.wez_srodek();
        Vector3D srodek_obiektu = object->wez_srodek();

        /*tworzenie zmiennej dlugosci, ktora dodaje do siebie kwadraty odległości poszczególnych zmiennych x,y,z ([1], [2], [3])*/
        double length = sqrt(pow(srodek_drona[0] - srodek_obiektu[0], 2) + pow(srodek_drona[1] - srodek_obiektu[1], 2) + pow(srodek_drona[2] - srodek_obiektu[2], 2));

        /*jesli suma promieni drona i obiektu jest wieksza od wyznaczonej wartosci, nie przesuwa dalej drona; w przeciwnym wypadku -  przesuwa*/
        if (promien_kopia + object->promien() >= length)
        {
            cout<<"123";
            return true;
        }
    }
    return false;
}

/*!
    \brief
    *Funkcja prosta
    *Tworzy prostą -  drogę drona na podstawie dostarczonej do niej drogi.
    *Do współrzędniej Z przypisuje wartość 150 i wstawia tę współrzędną na koniec listy. Współrzędne X, Y oblicza na podstawie wzoru podanego w treści zadania i również wstawia na koniec listy. Następnie zeruje współrzędną Z i wstawia ją na koniec listy
    *Później otwiera plik drogi i zapisuje do niej każdą obliczoną współrzędną w pętli
*/

void Drone::prosta(double droga)
{
    Vector3D pomocniczy = kopia.wez_srodek();
    pomocniczy[2] = 150;
    droga_drona.push_back(pomocniczy);
    pomocniczy[0] += droga * cos(kat * M_PI / 180);
    pomocniczy[1] += droga * sin(kat * M_PI / 180);
    droga_drona.push_back(pomocniczy);
    pomocniczy[2] = 0;
    droga_drona.push_back(pomocniczy);

    std::fstream plik;

    plik.open("../datasets/droga.dat", std::ios::out);
    for (int i = 0; i < (int)droga_drona.size(); i++)
    {

        plik << droga_drona[i] << std::endl;
    }
    plik.close();
}