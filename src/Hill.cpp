#include "Hill.hh"
using namespace std;
/*!
    \brief
*Fuckja buduje wzniesienie na podstawie konstruktora cuboida. Przyjmuje wektor zawierający współrzędne srodka
*A następnie wysokość, długość przekatnej i długość wzniesienia. 
*Za pomoca funkcji push_back nowy element, czyli wierzcholek jest dodawany do kontenera wektora*/
Hill::Hill(Vector3D srodek, double x,double y, double z,std::string NazwaPlikuPis)
{
    double tab[]={x,y,z};
    wymiary= make_shared<Vector3D>(tab);
    this->NazwaPlikuPis=NazwaPlikuPis;
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
/*!
    \brief
    Konstruktor kopiujący HIll. Przyjmuje pr i przypisuje do niego każdą składową klasy*/
Hill::Hill( Hill& pr )
{
   wymiary=pr.wymiary;
 pkt1=pr.pkt1;
  srodek=pr.srodek;
  NazwaPlikuPis=pr.NazwaPlikuPis;
}
