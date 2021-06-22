
#pragma once
using namespace std;
#include <vector>
#include <fstream>
#include <string>

#include "Matrix3x3.hh"
#include "vector3D.hh"

class GeoSolid
{
protected:
Vector3D *wymiary;
 std::vector<Vector3D> pkt1;
 Vector3D srodek;
 std::string NazwaPlikuPis;
 public:

  Vector3D &operator[](int index)
  {
    return pkt1[index];
}
  Vector3D operator[](int index)const{
    return pkt1[index];
}

 void ustaw_srodek(Vector3D srodek){
    this->srodek = srodek;
}
 void ustaw_nazwe(std::string NazwaPlikuPis){
    this->NazwaPlikuPis = NazwaPlikuPis;
}
 Vector3D wez_srodek() const{
    return srodek;
}

 std::string wez_nazwe() const{
    return NazwaPlikuPis;
}

 void przesun(Vector3D translacja);
 void obrot(Matrix3x3 mac);

 void zapisz();
 ~GeoSolid(){free(wymiary);}
};