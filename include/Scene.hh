#pragma once

#include "Drone.hh"
#include "Prism.hh"
#include "Hill.hh"
#include "Pyramid.hh"
#include "Prism2.hh"
#include "lacze_do_gnuplota.hh"
#include "Ground.hh"
#include <list>
#include <memory>

class Scene
{


protected:
int numer_przeszkody;
std::list<shared_ptr<GeoSolid>> lista; //lista elementow przechowujaca inteligentne wskazniki typu bryla
    PzG::LaczeDoGNUPlota Lacze;
    Drone *TabDronow[2];
    Ground *plaszczyzna;

    int k = 0;
public:
    Scene();
    void Rysuj();
    bool menu();
    ~Scene()
    {
        free(plaszczyzna);
        for (int i = 0; i < 2; i++)
            free(TabDronow[i]);
    }
};
