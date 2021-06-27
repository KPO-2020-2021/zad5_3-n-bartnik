#include "Prism.hh"

Prism ::Prism(Vector<3> srodek, double z, double r, string nazwa)
{
  
    double tab[] = {0, 0, z};
    wymiary = make_shared< Vector3D>(tab);
    this->NazwaPlikuPis = nazwa;
    this->srodek = srodek;
    Vector3D pkt;
    for (int i = 0; i < 360; i += 60)
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