#include "Pyramid.hh"

/*!
    \brief
/Konstruktor bryły ostrosłupu oparty na konstruktorze prostopadłościanu. Przyjmuje wektor środka, współrzędne X, Y, Z oraz nazwę pliku do zapisu. Na podstawie środka tworzy kolejne wierzchołki i za pomocą
* funkcji push_back wysyła punkty do kontenera wektora*/
Pyramid::Pyramid(Vector3D srodek, double x,double y, double z,std::string NazwaPlikuPis)
{
    double tab[]={x,y,z};
    wymiary= make_shared<Vector3D>(tab);
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
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);


  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  pkt1.push_back(punkt);
}



/*!
    \brief
    KOnstruktor kopiujący Pyramid. Przyjmuje pr i przypisuje do niego każdą składową klasy*/
Pyramid::Pyramid( Pyramid& pr )
{
   wymiary=pr.wymiary;
 pkt1=pr.pkt1;
  srodek=pr.srodek;
  NazwaPlikuPis=pr.NazwaPlikuPis;
}