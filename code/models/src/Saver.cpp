#include "..\include\Saver.h"

Sauvegarde::Sauvegarde()
{
  //loadSauvegarde();

}


Sauvegarde::~Sauvegarde()
{
  saveSauvegarde();

/*
  for(auto & elem : *getpDataProfil())
  {
    elem.~Profil();
    //delete elem;
  }
  for(auto & elem : *getpDataCard())
  {
    elem.second->~Card();
    //delete elem.second;
  }
*/
}

void Sauvegarde::loadSauvegarde()
{

}

void Sauvegarde::saveSauvegarde()
{
  saveDataCard();
}

void Sauvegarde::saveDataCard()
{
  getDataCard()[1] = new EnergyCard();

  std::ofstream filCard("DataSauvegarde/CardData.txt", std::ios::out | std::ios::trunc);

  if(filCard)
  {
    filCard << getpDataCard()->size() << std::endl;


    for(auto & elem : *getpDataCard())
    {
      filCard << elem.first << std::endl << "Coucou" << std::endl;
    }

    filCard.close();
  }
  else
  {
    std::cout<< "Error open " << std::endl;
  }
}
