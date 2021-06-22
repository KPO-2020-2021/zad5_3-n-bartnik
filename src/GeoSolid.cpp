#include "GeoSolid.hh"



void GeoSolid::przesun(Vector3D translacja)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = pkt1[i] + translacja;
    }
    srodek = srodek + translacja;
}

void GeoSolid::obrot(Matrix3x3 mac)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (mac * pkt1[i]);
    }
    srodek=mac*srodek;
}

void GeoSolid::zapisz()
{
    std::fstream plik;
    double tab[] = {0, 0, (*wymiary)[2] / 2};
    Vector3D translacja(tab);

    plik.open(NazwaPlikuPis, std::ios::out);

    for (int i = 0; i < (int)pkt1.size(); i += 2)
    {
        plik << srodek + translacja << std::endl;
        for (int j = 0; j < 2; j++)
        {
            plik << pkt1[j + i] << std::endl;
        }
        plik << srodek - translacja << std::endl
             << std::endl;
    }

    plik << srodek + translacja << std::endl;
    for (int j = 0; j < 2; j++)
    {
        plik << pkt1[j] << std::endl;
    }
    plik << srodek - translacja << std::endl
         << std::endl;
    plik.close();
}