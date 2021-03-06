#pragma once 
#include "vector3D.hh"
#include "Matrix3x3.hh"
#include <fstream>
#include <vector>

class Ground
{
protected:
    std::vector<Vector3D> pkt1;
    std::string nazwa;
   int licz_prostych;
public:
    std::string wez_nazwe() const;
    Ground(Vector3D wymiary=Vector3D(),int gestosc_siatki=10, std::string nazwa="../datasets/plaszczyzna.dat");

    Vector3D &operator[](int index)
{
    return pkt1[index];
}
    Vector3D operator[](int index) const {
    return pkt1[index];
}

    void ustaw_nazwe(std::string nazwa);
    void zapisz();
};