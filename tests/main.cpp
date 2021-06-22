
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "../include/vector.hh"
#include "../include/Cuboid.hh"
#include "../include/matrix.hh"
#include "../include/size.hh"
#include "../include/GeoSolid.hh"

TEST_CASE("konstruktor parametryczny")
{
    double a = 1.0, b = 2.0, c = 3.0;
    Vector<3> wektor /*( a, b )*/;

    wektor[0] = a;
    wektor[1] = b;
    wektor[2] = c;

    CHECK(wektor[0] == 1);
    CHECK(wektor[1] == 2);
    CHECK(wektor[2] == 3);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Vector<3> wektor;

    CHECK(wektor[0] == 0);
    CHECK(wektor[1] == 0);
    CHECK(wektor[2] == 0);
}

TEST_CASE("Dodawanie wektorów")
{
    double tab1[3] = {1, 2, 3};
    double tab2[3] = {2, 1, 3};
    Vector<3> wektor1(tab1);
    Vector<3> wektor2(tab2);
    Vector<3> wynik;

    wynik = wektor1 + wektor2;
    CHECK(wynik[0] == 3);
    CHECK(wynik[1] == 3);
    CHECK(wynik[2] == 6);
}

TEST_CASE("Odejmowanie wektorów")
{
    double tab1[3] = {1, 2, 3};
    double tab2[3] = {2, 1, 3};
    Vector<3> wektor1(tab1);
    Vector<3> wektor2(tab2);
    Vector<3> wynik;

    wynik = wektor1 - wektor2;
    CHECK(wynik[0] == -1);
    CHECK(wynik[1] == 1);
    CHECK(wynik[2] == 0);
}

TEST_CASE("wektor * stała")
{
    double tab1[3] = {1, 2, 3};
    Vector<3> wektor1(tab1);
    double a = 2;
    Vector<3> wynik;

    wynik = wektor1 * a;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 4);
    CHECK(wynik[2] == 6);
}

TEST_CASE("wektor - wyświetlanie")
{
    double tab1[3] = {1, 2, 3};
    Vector<3> wektor1(tab1);
    // double a[2]={1,2};
    std::ostringstream StrmWyj;
    StrmWyj << wektor1;
    std::cout << StrmWyj.str();
    CHECK("1 2 3 " == StrmWyj.str());
}

TEST_CASE("wektor - wpisywanie")
{
    Vector<3> a;

    std::istringstream in("1 1 1");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("1 1 1 " == out.str());
}

TEST_CASE("operator porownania")
{
    double tab1[3] = {1, 2, 3};
    Vector<3> wektor1(tab1);
    Vector<3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("operator porownania")
{
    double tab1[3] = {1, 2, 3};
    Vector<3> wektor1(tab1);
    Vector<3> wektor2(tab1);

    CHECK(wektor1 == wektor2);
}



/********************MACIERZ**********************/

TEST_CASE("konstruktor parametryczny")
{

    double tab[3][3] = {{2, 2, 2}, {2, 2, 2}};
    Matrix3x3 macierz(tab);

    CHECK(macierz(0, 0) == 2);
    CHECK(macierz(0, 1) == 2);
    CHECK(macierz(0, 2) == 2);
    CHECK(macierz(1, 0) == 2);
    CHECK(macierz(1, 1) == 2);
    CHECK(macierz(1, 2) == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Matrix3x3 macierz;

    CHECK(macierz(0, 0) == 1);
    CHECK(macierz(0, 1) == 0);
    CHECK(macierz(0, 2) == 0);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 1);
    CHECK(macierz(1, 2) == 0);
}

TEST_CASE("macierz mnożenie * wektor")
{
    double tab1[3] = {1, 2, 3};
    double tab2[3] = {0, 0, 0};
    Vector<3> wektor1(tab1);
    Vector<3> wektor2(tab2);
    Matrix3x3 macierz;

    wektor1 = macierz * wektor2;
    CHECK(wektor1 == wektor2);
}
/****************************CUBOID****************************/

TEST_CASE("konstruktor parametryczny")
{
    string nazwa, nazwa1;
    double tab0[3]={0,0,0};
    double tab1[3] = {-5, 10, 15};
    double tab2[3] = {5, 10, 15};
    double tab3[3] = {5, 10, -15};
    double tab4[3] = {5, -10, 15};

    double tab5[3] = {5, -10, -15};
    double tab6[3] = {-5, -10, 15};
    double tab7[3] = {-5, -10, -15};
    double tab8[3] = {-5, 10, -15};

    Vector<3> wektor(tab0), wektor1(tab1), wektor2(tab2), wektor3(tab3);
    Vector<3> wektor4(tab4), wektor5(tab5), wektor6(tab6), wektor7(tab7), wektor9(tab8);
    double h = 10, w = 20, p = 30;
    Cuboid Pr(wektor, h, w, p);

    CHECK(Pr[0] == wektor1);
    CHECK(Pr[1] == wektor9);
    CHECK(Pr[2] == wektor2);
    CHECK(Pr[3] == wektor3);
    CHECK(Pr[4] == wektor4);
    CHECK(Pr[5] == wektor5);
    CHECK(Pr[6] == wektor6);
    CHECK(Pr[7] == wektor7);
}

// TEST_CASE("konstruktor bezparametryczny")
// {

//     Cuboid Pr;
//     Vector<3> wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }

// TEST_CASE("przesuniecie o wektor")
// {
//     double tab[3] = {20, 30, 40};
//     Cuboid Pr;
//     Vector<3> wektor(tab);
//     Pr = Pr + wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }



// TEST_CASE("obrot wokol osi OX")
// {

//     Cuboid Pr;
//     double kat = 90;
//     Matrix3x3 macierz;
//     macierz = macierz_obrot_x(kat) * macierz;
//     Pr.rot(macierz);
//     Vector<3> wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }

// TEST_CASE("obrot wokol Osi OY")
// {

//     Cuboid Pr;
//     double kat = 90;
//     Matrix3x3 macierz;
//     macierz_obrot_y(kat);
//     macierz = macierz_obrot_x(kat) * macierz;
//     Pr.rot(macierz);
//     Vector<3> wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }

//  TEST_CASE("obrot wokol Osi OZ")
// {

//     Cuboid Pr;
//     double kat = 90;
//     Matrix3x3 macierz;
//     macierz = macierz_obrot_z(kat) * macierz;
//     Pr.rot(macierz);
//     Vector<3> wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }

// TEST_CASE("prostopadloscian - wyświetlanie")
// {
//     Cuboid Pr;

//     std::ostringstream StrmWyj;
//     StrmWyj << Pr;
//     std::cout << StrmWyj.str();
//     CHECK("0 0 0 \n0 0 0 \n\n""0 0 0 \n0 0 0 \n\n""0 0 0 \n0 0 0 \n\n0 0 0 \n0 0 0 \n\n" == StrmWyj.str());
// }

/****************************DRONE****************************/

// TEST_CASE("dron - konstruktor parametryczny")
// {
//     string nazwa, nazwa1;
//     double tab0[3]={0,0,0};
//     double tab1[3] = {-5, -10, -15};
//     double tab2[3] = {-5, 10, -15};
//     double tab3[3] = {5, 10, -15};
//     double tab4[3] = {-5, 10, 15};

//     double tab5[3] = {5, 10, 15};
//     double tab6[3] = {-5, -10, 15};
//     double tab7[3] = {5, -10, 15};
//     double tab8[3] = {5, -10, -15};

//     Vector<3> wektor(tab0), wektor1(tab1), wektor2(tab2), wektor3(tab3);
//     Vector<3> wektor4(tab4), wektor5(tab5), wektor6(tab6), wektor7(tab7), wektor9(tab8);
//     double h = 10, w = 20, p = 30;
//     Cuboid Pr(wektor, h, w, p, nazwa, nazwa1);

//     CHECK(Pr[0] == wektor1);
//     CHECK(Pr[1] == wektor9);
//     CHECK(Pr[2] == wektor2);
//     CHECK(Pr[3] == wektor3);
//     CHECK(Pr[4] == wektor4);
//     CHECK(Pr[5] == wektor5);
//     CHECK(Pr[6] == wektor6);
//     CHECK(Pr[7] == wektor7);
// }

// TEST_CASE("przesuniecie o wektor")
// {
//     Vector<3> wek;
//     double tab[3] = {20, 30, 40}, h =10,w=10,d=10;
//     Cuboid Pr(wek, h, w, d);
//     Vector<3> wektor(tab);
//     Pr = Pr + wektor;
//     CHECK(Pr[0] == wektor);
//     CHECK(Pr[1] == wektor);
//     CHECK(Pr[2] == wektor);
//     CHECK(Pr[3] == wektor);
//     CHECK(Pr[4] == wektor);
//     CHECK(Pr[5] == wektor);
//     CHECK(Pr[6] == wektor);
//     CHECK(Pr[7] == wektor);
// }

/****************************GEOSOLID****************************/

// TEST_CASE("translacja")
// {
//     Vector<3> wektor;
//    cout << "1"<< endl;
//     wektor[0] =1;
//     cout << "2"<< endl;
//     wektor[1] =1;
//     cout << "3"<< endl;
//     wektor[2] =1;
//     cout << "4"<< endl;
//     GeoSolid Pr(Pr);
//     //Geosolid
//     cout << "5"<< endl;
//     Pr.przesun(wektor);
//     cout << "6"<< endl;
//     //CHECK(Pr[0] == wektor);
//     cout << "2"<< endl;
// }

