#pragma once
#include "lacze_do_gnuplota.hh"
#include "Cuboid.hh"
#include "Prism.hh"
#include "Object.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 10000


class Drone: public Object, public std::enable_shared_from_this< Drone >
{
   std::vector<Vector3D> droga_drona;
    PzG::LaczeDoGNUPlota &Lacze;
    Cuboid orginal;
    Cuboid kopia;
    Matrix3x3 obr;
    Vector3D droga;
    double kat;
    int index; 
      Prism orginal_wirnika[4];
    Prism kopia_wirnika[4];
    double promien_kopia;
public:

  
  Drone(int index,PzG::LaczeDoGNUPlota &LaczeVector3D, Vector3D pozycja);
  void animacja(double droga);
  void przesun(double droga);
  void obrot(double kat);
  void zapisz();
  double promien(){return kopia.promien();}
  void sterowanie(std::list<std::shared_ptr<Object>> &lista);
  void prosta(double droga);
  void obrot_rotrow(); 
bool sprawdzaj_miejsce(shared_ptr <Object> object);
  Vector3D wez_srodek() const {
    return kopia.wez_srodek();
}
  //int wez_index(){return index; }
  std::string wez_nazwe()const{return "Napotkana przeszkoda: dron";}
  //void usun();
};
