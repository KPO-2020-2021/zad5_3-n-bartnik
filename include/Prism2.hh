#pragma once
#include "GeoSolid.hh"
class Prism2 : public GeoSolid
{

public:

Prism2(Vector3D srodek=Vector3D(), double x=50,double y=50, double z=50,std::string nazwa="../datasets/blok3.dat");
Prism2( Prism2& pr );
 ~Prism2(){free(  wymiary);}
};

