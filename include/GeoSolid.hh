
#pragma once
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include "Object.hh"
#include "Matrix3x3.hh"
#include "vector3D.hh"

class GeoSolid : public Object, public std::enable_shared_from_this<GeoSolid>
{
protected:
  std::shared_ptr<Vector3D> wymiary;
  std::vector<Vector3D> pkt1;
  Vector3D srodek;
  std::string NazwaPlikuPis;

public:

bool sprawdzaj_miejsce(shared_ptr<Object> ob);
double promien(){return sqrt(pow(srodek[0]-pkt1[0][0],2) + pow(srodek[1]-pkt1[0][1],2)+pow(srodek[2]-pkt1[0][2],2));}

  Vector3D &operator[](int index)
  {
    return pkt1[index];
  }
  Vector3D operator[](int index) const
  {
    return pkt1[index];
  }

  void ustaw_srodek(Vector3D srodek)
  {
    this->srodek = srodek;
  }
  void ustaw_nazwe(std::string NazwaPlikuPis)
  {
    this->NazwaPlikuPis = NazwaPlikuPis;
  }
  Vector3D wez_srodek() const
  {
    return srodek;
  }

  std::string wez_nazwe() const
  {
    return NazwaPlikuPis;
  }

  void przesun(Vector3D translacja);
  void obrot(Matrix3x3 mac);

  void zapisz();
  // ~GeoSolid() { free(wymiary); }
};