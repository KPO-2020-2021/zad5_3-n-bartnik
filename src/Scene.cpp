#include "Scene.hh"
using namespace std;


void Scene::Rysuj()
{
    Lacze.Rysuj();
}

Scene::Scene()
{
    Vector<3> srod;
    numer_przeszkody = 0;
    nr_drona=0;
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
        if (numer_przeszkody==0){
        /*ustalanie losowanej pozycji klasy Hill*/
        srod[0] = rand() % 400 - 200;
        srod[1] = rand() % 400 - 200;
        srod[2] = 50;
        // int nr_p = rand() % 3;
        // if (nr_p == 0)
            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Hill>(srod, 100, 50, 100, "../datasets/blok1.dat"));

        // /*ustalanie losowanej pozycji klasy Pyramid*/
        srod[0] = rand() % 400 - 200;
        srod[1] = rand() % 400 - 200;
        srod[2] = 50;
        //else if (nr_p == 1)
            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "../datasets/blok2.dat"));

        // /*ustalanie losowanej pozycji klasy Prism2*/
        srod[0] = rand() % 400 - 200;
        srod[1] = rand() % 400 - 200;
        srod[2] = 50;
        //else if (nr_p == 2)
            /*dzięki funkcji push_front obiekt jest wypychany na pocżatek listy bloków*/
            lista.push_front(std::make_shared<Pyramid>(srod, 100, 50, 100, "../datasets/blok3.dat"));
        numer_przeszkody++;
        }


/*sprawdzanie miejsca, w ktorym ma wyladowac dron poprzez przejscie po całej liście wskażnikóœ bryl
jesli miejsce == true, to nastepuje kolizja
jesli miejsce == false, kolizja nie nastepuje*/
        for (std::list<std::shared_ptr<Object>>::const_iterator i = lista.begin(); i != lista.end(); i++)
        {
            if ((*lista.begin())->sprawdzaj_miejsce(*i))
            {
                miejsce = true;
            }
        }
        if (miejsce==true)
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
        cout << "Napotkana przeszkoda: "<<(*i)->wez_nazwe() << " " << (*i)->promien() << endl;
    }
/*Plaszczyzna zapisywana do pliku, zamiana na łańcuch znaków*/
    Lacze.DodajNazwePliku(plaszczyzna->wez_nazwe().c_str());
    plaszczyzna->zapisz();


    /*zmienna miejsce - wskazuje na to, czy dron moze wyladować czy nie*/
    miejsce = false;
    for (int i = 0; i < 4; i++)
    {
        double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};

        ListaDronow.push_front(std::make_shared<Drone>(i, Lacze, Vector3D(pozycja)));

        for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
        {
            if ((*ListaDronow.begin())->sprawdzaj_miejsce(*a))
            {
                miejsce = true;
            }
        }
        if (miejsce==true)
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

bool Scene::menu()
{
    cout << "a - wybierz aktywnego drona" << endl;
    cout << "b - dodaj przeszkodę" << endl;
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
            a = ListaDronow.begin();
            for (int i = 0; i < nr; i++)
            {
                a++;
            }

            (*a)->sterowanie(lista);
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
        cout << "3 - nieregularny" << endl;

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
                for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
                {
                    if ((*lista.begin())->sprawdzaj_miejsce(*a))
                    {
                        miejsce = true;
                    }
                }
                if (miejsce)
                {
                    i--;
                    lista.erase(lista.begin());
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

                for (std::list<std::shared_ptr<Object>>::const_iterator a = lista.begin(); a != lista.end(); a++)
                {
                    if ((*lista.begin())->sprawdzaj_miejsce(*a))
                    {
                        miejsce = true;
                    }
                }
                if (miejsce)
                {

                    ListaDronow.erase(ListaDronow.begin());
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
        // (*lista.begin())->zapisz();
        // Lacze.DodajNazwePliku((*lista.begin())->wez_nazwe().c_str());
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
