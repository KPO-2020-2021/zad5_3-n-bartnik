#include "Scene.hh"
using namespace std;

/*!
    \brief
    *Funkcja Rysuj
    Rysuje scene przy pomocy łącza.
    * 
*/
void Scene::Rysuj()
{
    Lacze.Rysuj();
}

/*!
    \brief
    *Konstruktor sceny
    *Ustawia zakres sceny (-300 - 300). Następnie tworzy płaszczyzne w postaci siatki na przestrzeni OX x OY. Później ustawia przeszkody w losowo wygenerowanym miejscu. Ustawia też zmienną dla kolizji. 
    *Po ustawieniu 3 przeszkód, funkcja sprawdza dostępność miejsca dla przeszkody. Jeśli miejsca nie ma - za pomocą funkcji erase usuwa element z listy i przesuwa go w lewo po wektorze. 
    *Następnie zapisuje każdy element obiektu i płaszczyznę. Później za pomocą funckji push_front na początek wysyłane są nowe drony w dowolnej pozycji i sprawdzane jest dostępne miejsce. Jeśli miejsca nie ma - za pomocą funkcji erase usuwa element z listy i przesuwa go w lewo po wektorze. 
    *Jeśli miejsce jest - dron wstawiany jest na początek listy i zapisywany.
    *
    * 
*/
Scene::Scene()
{
    Vector<3> srod;
    numer_przeszkody = 0;
    nr_drona = 0;
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresY(-300, 300);
    Lacze.UstawZakresX(-300, 300);
    Lacze.UstawZakresZ(-300, 300);

    double tab_wymiary[3] = {600, 600, 0}; //wymiary plaszczyzny
    Vector<3> kwadrat(tab_wymiary);
    plaszczyzna = new Ground(kwadrat, 20);
    bool miejsce = false; //dostepne miejsce (początkowo dostępne)

    for (int i = 0; i < 4; i++)
    {

        /*ustawianie przeszkód*/
        if (numer_przeszkody == 0)
        {
            /*ustalanie losowanej pozycji klasy Hill*/
            srod[0] = rand() % 400 - 200;
            srod[1] = rand() % 400 - 200;
            srod[2] = 50;
            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Hill>(srod, 100, 50, 100, "../datasets/blok1.dat"));

            // /*ustalanie losowanej pozycji klasy Pyramid*/
            srod[0] = rand() % 400 - 200;
            srod[1] = rand() % 400 - 200;
            srod[2] = 50;

            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "../datasets/blok2.dat"));

            // /*ustalanie losowanej pozycji klasy Prism2*/
            srod[0] = rand() % 400 - 200;
            srod[1] = rand() % 400 - 200;
            srod[2] = 50;

            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Prism2>(srod, 100, 50, 100, "../datasets/blok3.dat"));
            numer_przeszkody++;
        }

        /*sprawdzanie miejsca, w ktorym ma wyladowac dron poprzez przejscie po całej liście wskażnikóœ bryl
jesli miejsce == true, to nastepuje kolizja
jesli miejsce == false, kolizja nie nastepuje*/
        for (std::list<std::shared_ptr<Object>>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            if ((*lista.begin())->sprawdzaj_miejsce(*i)==true)
            {
                miejsce = true;
            }
        }
        if (miejsce == true)
        {
            i--;
            lista.erase(lista.begin());
        }
        miejsce = false;
    }
    /*Zwracanie wskaźnika do peirwszego elementu listy. Dzięki inkrementacji możliwe jest przejście po wszystkich elementach*/
    for (std::list<std::shared_ptr<Object>>::const_iterator i = lista.begin(); i != lista.end(); i++)
    {
        Lacze.DodajNazwePliku((*i)->wez_nazwe().c_str());
        (*i)->zapisz();
        //cout << "Napotkana przeszkoda: "<<(*i)->wez_nazwe() << " " << (*i)->promien() << endl;
    }
    /*Plaszczyzna zapisywana do pliku, zamiana na łańcuch znaków*/
    Lacze.DodajNazwePliku(plaszczyzna->wez_nazwe().c_str());
    plaszczyzna->zapisz();

    /*zmienna miejsce - wskazuje na to, czy dron moze wyladować czy nie*/
    miejsce = false;
    for (int i = 0; i < 4; i++)
    {
        double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        ListaDronow.push_front(std::make_shared<Drone>(i, Lacze, Vector3D(pozycja))); //tworzenie drona

        for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
        {
            if ((*ListaDronow.begin())->sprawdzaj_miejsce(*a)==true)
            {
                miejsce = true;
            }
        }
        if (miejsce == true) //jeśli brak miejsca
        {
            i--;
            ListaDronow.erase(ListaDronow.begin());
        }
        else
        {
            lista.push_front(*ListaDronow.begin());
            (*ListaDronow.begin())->zapisz();
            nr_drona++;
        }
        miejsce = false;
    }
    Lacze.Rysuj();
}

/*!
    \brief
    *Funkja menu -  odpowiada za wybór użytkownika
    *Gdy użytkownik wybierze opcję a - ma do wyboru jednego z dwóch aktywnych dronów (0,1). Dla numerów 1,2 - program umożliwia sterowanie dronem za pomocą funkcji sterowanie
    *Gdy użytkownik wybierze opcję b - może on dodać dowolną przeszkodę z zaproponowanych  - prostopadłościan, ostrosłup lub graniastosłup. Po wybraniu odpowiedniej opcji funckja sprawdza dostępne miejsce i dodaje przeszkodę.
    *Analogicznie postępuje dla drona.
*/

bool Scene::menu()
{
    cout << "a - wybierz aktywnego drona" << endl;
    cout << "b - dodaj przeszkodę lub nowego drona" << endl;
    cout << "Inny numer konczy program" << endl;
    char opcja;
    cin >> opcja;
    switch (opcja)
    {
    case 'a':
    {
        cout << "Wybierz aktywnego drona (0 lub 1)" << endl;
        int nr;
        cin >> nr;
        if (nr < 2)
        {
            std::list<std::shared_ptr<Drone>>::const_iterator a;
            for (int i = 0; i < nr; i++)
            {
                ListaDronow.begin()++;
            }

            (*ListaDronow.begin())->sterowanie(lista);
        }
        else
        {
            return false;
        }
    }
    break;
    case 'b':
    {
        cout << "Wybierz element, który chcesz dodać" << endl;
        cout << "1 - prostopadloscian" << endl;
        cout << "2 - ostrosłup" << endl;
        cout << "3 - graniastosłup" << endl;
        cout << "4 - nowy dron" << endl;

        int nr;
        cin >> nr;
        Vector3D srod;

        if (nr != 4)
        {
            for (int i = 0; i < 50; i++)
            {
                bool miejsce = false;
                srod[0] = rand() % 400 - 200;
                srod[1] = rand() % 400 - 200;
                srod[2] = 50;
                /*wybór przeszkody do dodania*/
                if (nr == 1)
                {

                    lista.push_front(std::make_shared<Hill>(srod, 100, 50, 100, "../datasets/blok" + std::to_string(numer_przeszkody) + ".dat"));
                }
                if (nr == 2)
                {

                    lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "..datasets/blok" + std::to_string(numer_przeszkody) + ".dat"));
                }
                if (nr == 3)
                {

                    lista.push_front(std::make_shared<Prism2>(srod, 100, 50, 100, "..datasets/blok" + std::to_string(numer_przeszkody) + ".dat"));
                }
                numer_przeszkody++;

                /*sprawdza dostępne miejsce dla nowej przeszkody*/
                for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
                {
                    if ((*lista.begin())->sprawdzaj_miejsce(*a)==true)
                    {
                        miejsce = true;
                    }
                }
                if (miejsce==true)
                {
                    i--;
                    lista.erase(lista.begin()); //obiekt usuwany z listy
                }
                else
                {
                    break;
                }
            } 
            
            (*lista.begin())->zapisz();
            Lacze.DodajNazwePliku((*lista.begin())->wez_nazwe().c_str());
        }
        else
        {
            bool miejsce = false;
            for (int i = 0; i < 50; i++)
            {
                double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

                ListaDronow.push_front(std::make_shared<Drone>(nr_drona, Lacze, Vector3D(pozycja)));
/*przechodzi po całej liście obiektów*/
                for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
                {
                    if ((*lista.begin())->sprawdzaj_miejsce(*a)==true)
                    {
                        miejsce = true;
                    }
                }
                if (miejsce==true)
                {

                    ListaDronow.erase(ListaDronow.begin());//obiekt usuwany z listy
                }
                else
                {
                    lista.push_front(*ListaDronow.begin());
                    (*ListaDronow.begin())->zapisz();
                    nr_drona++;
                    break;
                }
                miejsce = false;
            }
        }
        if (nr > 4)
        {
            cout << "Błędna opcja" << endl;
        }

    }

    break;

    default:
    {
        cout << "Podana opcja niepoprawna" << endl;
    }
    break;
    }
    return true;
}
