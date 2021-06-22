#include "Prism2.hh"


/*KOnstruktor bryły ostrosłupu oparty na konstruktorze ostrosłupa???*/
Prism2::Prism2(Vector3D srodek, double x,double y, double z,std::string NazwaPlikuPis)
{
    this->NazwaPlikuPis=NazwaPlikuPis;
  this->srodek=srodek;

Vector3D punkt;

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);


  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
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

  this->srodek[0]=srodek[0];
  this->srodek[1]=srodek[1];
  this->srodek[2]=srodek[2]-(z/2);
}

Prism2::Prism2( Prism2& pr )
{
   wymiary=pr.wymiary;
 pkt1=pr.pkt1;
  srodek=pr.srodek;
  NazwaPlikuPis=pr.NazwaPlikuPis;
}