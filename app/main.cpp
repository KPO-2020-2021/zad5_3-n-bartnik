// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "Scene.hh"
//#include "../include/lacze_do_gnuplota.hh"



int main()
{

     srand(time(NULL));
     Vector3D wektor;
   Scene scena;
   wektor.zliczanie();
       while (scena.menu())
       {
            scena.Rysuj();
            wektor.zliczanie();
       }
       return 0;
}
