#pragma once

#include "GeoSolid.hh"



#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
class Prism : public GeoSolid
{


public:

    Prism(Vector3D srodek=Vector3D(), double d=10, double r=15, string NazwaPlikuPis = "..datasets/Rotor.dat");
    // ~Prism() { free(wymiary); };
    
};
