
#include "Ground.hh"


Ground::Ground(Vector3D wymiary, int gestosc_siatki, std::string nazwa)
{
    this->nazwa = nazwa;
    double tab[3];
    licz_prostych=0;
    for (int i = -wymiary[0] / 2; i < wymiary[0] / 2; i += gestosc_siatki)
    {
        for (int j = -wymiary[1] / 2; j < wymiary[1] / 2; j += gestosc_siatki)
        {
            tab[0] = i;
            tab[1] = j;

            wierz.push_back(tab);
        }
        licz_prostych++;
    }
}



void Ground::ustaw_nazwe(std::string nazwa)
{
    this->nazwa = nazwa;
}

std::string Ground::wez_nazwe() const
{
    return nazwa;
}

void Ground::zapisz()
{
      std::fstream plik;

    plik.open(nazwa, std::ios::out);
 for (int i = 0; i < (int)wierz.size(); i ++)
 {
   if(i%licz_prostych==0)
   plik<<std::endl;
   plik<<wierz[i]<<std::endl;
 }
   
    plik.close();
}