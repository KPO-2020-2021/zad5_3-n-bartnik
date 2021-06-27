#include "Prism.hh"



/*!
    \brief
    Konstruktor klasy Prism - klasy dla rotora. 
    *Przyjmuje wektor środka, zmeinne z (dla wymiaru z) i promień r oraz zmienną nazwa -  pliku do zapisu.
    *Następnie funkcja tworzy punkty zgodnie ze wzorem z insrukcji oraz za pomocą funkcji push_back wysyła je do kontenera wektora
    */
Prism ::Prism(Vector<3> srodek, double z, double r, string nazwa)
{
  
    double tab[] = {0, 0, z};
    wymiary = make_shared< Vector3D>(tab);
    this->NazwaPlikuPis = nazwa;
    this->srodek = srodek;
    Vector3D pkt;
    for (int i = 0; i < 360; i += 60) //po całym kole, co 60 stopni, żeby utworzyć podstawę sześciokąta
    {
        pkt[0] = r * cos(i * M_PI / 180);
        pkt[1] = r * sin(i * M_PI / 180);
        pkt[2] = srodek[2] + (z / 2);
        pkt1.push_back(pkt);


        pkt[0] = r * cos(i * M_PI / 180);
        pkt[1] = r * sin(i * M_PI / 180);
        pkt[2] = srodek[2] - (z / 2);
        pkt1.push_back(pkt);
    }
}