
#include "Ground.hh"

/*!
    \brief
    *Konstruktor parametryczny Ground.
    *Przyjmuje wektor wymiarów, zmienną gęstości siatki i nazwe pliku.
    *Przechodzi przez 2 wymiary siatki płaszczyzny w dwóch pętlach */
Ground::Ground(Vector3D wymiary, int gestosc_siatki, std::string nazwa)
{
    this->nazwa = nazwa;
    double tab[3];
    licz_prostych=0; //licznik prostych
    for (int i = -wymiary[0] / 2; i < wymiary[0] / 2; i += gestosc_siatki)
    {
        for (int j = -wymiary[1] / 2; j < wymiary[1] / 2; j += gestosc_siatki)
        {
            tab[0] = i;
            tab[1] = j;

            pkt1.push_back(tab); //dokłada do kontenera wektora
        }
        licz_prostych++;
    }
}

/*!
    \brief
    *Funkcja ustaw_nazwe.
    *Przyjmuje zmienną nazwa (typu string).
    *Do skłądowej nazwa klasy przypisuje podaną zmienną nazwa*/

void Ground::ustaw_nazwe(std::string nazwa)
{
    this->nazwa = nazwa;
}


/*!
    \brief
    *Funkcja wez_nazwe.
    *Zwraca nazwę*/
std::string Ground::wez_nazwe() const
{
    return nazwa;
}


/*!
    \brief
    *Funkcja zapisz.
    *Tworzy zmeinna plik typu fstream, otwiera plik o danej nazwie. W pętli przechodzącej przez każdy wierzchołek, jeśli iloraz licznika pętli i licznika prostych się zerują - zapisuje wierzchołek do pliku.
    *Zamyka plik*/
void Ground::zapisz()
{
      std::fstream plik;

    plik.open(nazwa, std::ios::out);
 for (int i = 0; i < (int)pkt1.size(); i ++)//wszystkie wierzchołki
 {
   if(i%licz_prostych==0)
   plik<<std::endl;
   plik<<pkt1[i]<<std::endl;
 }
   
    plik.close();
}