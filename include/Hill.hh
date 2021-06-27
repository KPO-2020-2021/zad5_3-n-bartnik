

#pragma once
#include "GeoSolid.hh"



using namespace std;
class Hill : public GeoSolid
{

public:


    Hill(Vector<3> srodek=Vector3D(), double h=100, double w=50, double d=50, string NazwaPlikuPis="../datasets/blok1.dat");
     Hill(Hill& pr);
     Hill &operator=(const Hill &other)
    {
     wymiary=other.wymiary;
 pkt1=other.pkt1;
  srodek=other.srodek;
  NazwaPlikuPis=other.NazwaPlikuPis;
        return *this;
    }
 //~Hill(){free(wymiary);}
};

