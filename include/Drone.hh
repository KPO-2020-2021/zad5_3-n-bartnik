#pragma once
#include "lacze_do_gnuplota.hh"
#include "Cuboid.hh"
#include "Prism.hh"
#include <unistd.h> // biblioteka dla usleep
#define CZAS 20000


class Drone
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
public:

  
  Drone(int index,PzG::LaczeDoGNUPlota &LaczeVector3D, Vector3D pozycja);
  void animacja(double droga);
  void przesun(double droga);
  void obrot(double kat);
  void zapisz();
  void sterowanie();
  void prosta(double droga);
  void obrot_rotrow(); 
};
