#include "Cuboid.hh"
using namespace std;
/*!
    \brief
    
*Fuckja buduje prostopadłościan. Przyjmuje wektor zawierający współrzędne wektora środka.
*A następnie wysokość, długość przekatnej i długość prostopadłościanu
*Na podstawie tych danych oblicza współrzędne pozostałych wierzchołków*/
Cuboid::Cuboid(Vector3D srodek, double x,double y, double z,std::string nazwa)
{
    double tab[]={x,y,z};
    wymiary= make_shared< Vector3D>(tab);
    this->NazwaPlikuPis=nazwa;
  this->srodek=srodek;
  Vector3D punkt;

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]+(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);


  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]+(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);

   punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]+(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);


  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]+(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);

}
