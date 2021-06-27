#include "GeoSolid.hh"

/*!
    \brief
    *Funkcja przesun.
    *W pętli do każdej współrzędne wierzchołka pkt1 dodaje wektor translacji.
    *Do środka bryły również dodaje wektor translacji */

void GeoSolid::przesun(Vector3D translacja)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = pkt1[i] + translacja;
    }
    srodek = srodek + translacja;
}


/*!
    \brief
    *Funkcja obrot.
    *W pętli każdą współrzędną wierzchołka pkt1 mnoży przez macierz mac.
    *To samo robi z środkiem bryły */


void GeoSolid::obrot(Matrix3x3 mac)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (mac * pkt1[i]);
    }
    srodek=mac*srodek;
}


/*!
    \brief
    *Funkcja zapisz.
    *Tworzy zmienną plik typu fstream, którą otwiera i w pętli po wierzchołkach wypisuje środek były i dodaną do niego translację.
    *W drugiej pętli wewnątrz do pliku wypisywane są współrzędne punktu, a następnie jeszcze raz wypisywane są współrzędne 1. punktu.
    *Później plik jest zamykany*/


void GeoSolid::zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*wymiary)[2] / 2};
    Vector3D translacja(tab);

    plik.open(NazwaPlikuPis, std::ios::out);

    for (int i = 0; i < (int)pkt1.size(); i += 2) //wierzchołki
    {
        plik << srodek + translacja << std::endl;
        for (int j = 0; j < 2; j++) //współrzędne
        {
            plik << pkt1[j + i] << std::endl;
        }
        plik << srodek - translacja << std::endl
             << std::endl;
    }

    plik << srodek + translacja << std::endl;
    for (int j = 0; j < 2; j++) //współrzędne
    {
        plik << pkt1[j] << std::endl;
    }
    plik << srodek - translacja << std::endl
         << std::endl;
    plik.close();
}

/*!
    \brief
    *Funkcja sprawdzaj_miejsce.
    *Pzyjmuje shared pionter Object i tworzy shared pointer dla drona. Jesli geosolid i object są różne (czyli obiekt nie jest bryłą) pobieramy ich środki i liczymy odległość length 
    *w zależności od której wycznaczamy, czy dron ma się dalej przesunąć, czy nie.
*/


bool GeoSolid::sprawdzaj_miejsce(shared_ptr<Object> object)
{
    std::shared_ptr<GeoSolid> geosolid = shared_from_this();

    if (object != geosolid)
    {

        Vector3D srodek_bryly= wez_srodek();
        Vector3D srodek_obiektu = object->wez_srodek();
        double length = sqrt(pow(srodek_bryly[0] - srodek_obiektu[0], 2) + pow(srodek_bryly[1] - srodek_obiektu[1], 2) + pow(srodek_bryly[2] - srodek_obiektu[2], 2));
        if (promien() + object->promien() >= length)
        {
            return true;
        }
    }
    return false;
}