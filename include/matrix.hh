#pragma once

#include "size.hh"
#include "vector.hh"

#include <iostream>
#include <cstdlib>
template <int SIZE>
class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy
    double radian;

public:
    Matrix(double[SIZE][SIZE]);               // Konstruktor klasy
    Matrix();                                 // Konstruktor bezparametryczny klasy
    Vector<SIZE> operator*(Vector<SIZE> tmp); // Operator mnożenia przez wektor
    Matrix<SIZE> operator+(Matrix<SIZE> tmp);
    double &operator()(unsigned int row, unsigned int column);
    const double &operator()(unsigned int row, unsigned int column) const;
    Matrix(double kat);
    void Obroc();

    Matrix<SIZE> operator*(Matrix<SIZE> macierz);
};

/******************************************************************************
 |  Konstruktor klasy Matrix<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <int SIZE>
Matrix<SIZE>::Matrix()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if(i==j)
 value[i][j] = 1;
            else
            value[i][j] = 0;
        }
    }
    radian = 0;
}

/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix<SIZE>.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator*(Vector<SIZE> tmp)
{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column)
{

    if (row >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Funktor macierzy                                                ctor::odleglosc(Vector<SIZE> wek)
{      8          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <int SIZE>
const double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) const
{

    if (row >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE)
    {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator+(Matrix<SIZE> tmp)
{
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat)
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/*FUnkcja oblicza dla macierzy zadany kąt (ze stopni na radiany)
Argumenty:
kat - kat przypisany macierzy, potrzebny do obrotu
*/
template <int SIZE>
Matrix<SIZE>::Matrix(double kat)
{
    radian = kat * M_PI / 180;
}

/*Operator przeciążenia *. Mnoży macierz this i macierz dostarczoną, przypisuje
ją do macierzy wynik.
Argumenty:
this - macierz, czyli pierwszy skladnik mnożenia
macierz -  macierz mnożenia
Zwraca:
wymnożoną maceirz nikową (wynik)*/
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator*(Matrix<SIZE> macierz)
{
    Matrix<SIZE> wynik;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            wynik(i, j) = 0;
            for (int k = 0; k < SIZE; k++)
                wynik(i, j) += this->value[i][k] * macierz(k, j);
        }
    }
    return wynik;
}
