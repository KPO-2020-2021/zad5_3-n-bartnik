#pragma once
using namespace std;
#include <string>
#include <memory>
#include "vector3D.hh"

class Object
{
public:
    virtual std::string wez_nazwe() const=0;
    virtual void zapisz()=0;
    virtual Vector3D wez_srodek() const=0;
    virtual bool sprawdzaj_miejsce(shared_ptr<Object> object) = 0;
    virtual double promien()=0;
};