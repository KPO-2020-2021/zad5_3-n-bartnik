#pragma once
#include "GeoSolid.hh"

class Pyramid: public GeoSolid
{

public:
double promien(){return (*wymiary)[2];}
Pyramid(Vector3D srodek=Vector3D(), double x=60,double y=100, double z=50,std::string nazwa="../datasets/blok2.dat");
Pyramid( Pyramid& pr );
 Pyramid &operator=(const Pyramid &other)
    {
     wymiary=other.wymiary;
 pkt1=other.pkt1;
  srodek=other.srodek;
  NazwaPlikuPis=other.NazwaPlikuPis;
        return *this;
    }
};
