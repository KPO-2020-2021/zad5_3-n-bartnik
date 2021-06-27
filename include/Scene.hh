#pragma once
#include <list>
#include <memory>
#include "Hill.hh"
#include "Pyramid.hh"
#include "Prism2.hh"

#include "Prism.hh"

#include "lacze_do_gnuplota.hh"
#include "Drone.hh"
#include "Ground.hh"

#include "Object.hh"

class Scene
{


protected:
int numer_przeszkody;
std::list<shared_ptr<Object>> lista; //lista elementow przechowujaca inteligentne wskazniki typu geosolid
    PzG::LaczeDoGNUPlota Lacze;
    std::list<std::shared_ptr<Drone>>ListaDronow;
    Ground *plaszczyzna;
     int nr_drona;

    int k = 0;
public:
    Scene();
    void Rysuj();
    bool menu();
    //~Scene();
    // {
    //     free(plaszczyzna);
    //     for (int i = 0; i < 2; i++)
    //         free(TabDronow[i]);
    // }
};
