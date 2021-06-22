
#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>
using namespace std;
template <int SIZE>
class Vector {

private:
static int suma;
static int aktualnie;

    double size[SIZE];     //Tablica wektora

public:

    Vector();
Vector( Vector<SIZE>& wek){
    for(int i=0; i<SIZE; i++)
    size[i]=wek.size[i];
    aktualnie++;}

constexpr Vector(const Vector &other)
    {
        for (int i = 0; i < SIZE; i++)
            size[i] = other.size[i];
        aktualnie++;
    }

    Vector<3>& operator=(const Vector<3>& wek){
    for(int i=0; i<SIZE; i++)
    size[i]=wek.size[i];
    return *this;
    }

Vector &operator=(const float &other)
    {
        for (int i = 0; i < SIZE; i++)
            size[i] = other;
        return *this;
    }

    Vector(double tmp[SIZE]);

~Vector();
    Vector<SIZE> operator + (const Vector<SIZE> &v);

    Vector<SIZE> operator - (const Vector<SIZE> &v);

    Vector<SIZE> operator * (const double &tmp);

    Vector<SIZE> operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);
    bool operator==(Vector<SIZE> wek) const;

    void zliczanie();

};
template <int SIZE>
int Vector<SIZE>::suma=0;
template <int SIZE>
int Vector<SIZE>::aktualnie=0;


/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector<SIZE>::Vector()
{
    for (int i = 0; i < SIZE; ++i)
    {
        aktualnie++;
        suma++;
        size[i] = 0;
    }
}



/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Vector<SIZE>::Vector(double size[SIZE])
{
     for (int i = 0; i < SIZE; ++i)
    {
        aktualnie++;
        suma++;
        this->size[i] = size[i];
    }
}

template <int SIZE>
Vector<SIZE>::~Vector(){
    aktualnie--;
}

/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator+(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] + v[i];
    }
    return result;
}
template <int SIZE>
void Vector<SIZE>::zliczanie(){
        cout<<"Aktualna liczba wektorów: "<< aktualnie<<endl;
        cout<<"Wszystkie wektory: "<<suma<<endl;
    }

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator-(const Vector<SIZE> &v)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator*(const double &tmp)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator/(const double &tmp)
{
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }

    return result;
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Vector<SIZE>::operator[](int index) const
{
    if (index < 0 || index >= SIZE)
    {
        throw "Error: Wektor jest poza zasiegiem!";

    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return size[index];
}

/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index)
{
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Vector<SIZE> const &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        out << tmp[i] << " ";
    }
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Vector<SIZE> &tmp)
{
    for (int i = 0; i < SIZE; ++i)
    {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/*Funkcja porównuje ze sobą dwa wektory - wektor oryginalny i wektor podany do funkcji
Argumenty:
size - wektor oryginalny
wek - wektor podany do funkcji
Zwraca:
True - jeśli każda komórka wektora oryginalnego jest równa komórce wektora podanego do funckji
Falce - jeśli chociaz jedna komórka wektora oryginalnego nei jest równa komórce wektora podanego do funckji*/
template <int SIZE>
bool Vector<SIZE>::operator==(Vector<SIZE> wek) const
{
        for (int i = 0; i < SIZE; ++i)
    if (wek[i] != size[i] )
        return false;

    return true;
}

