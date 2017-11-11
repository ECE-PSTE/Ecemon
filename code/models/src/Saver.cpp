#include "..\include\Saver.h"

Saver::Saver()
{
  //loadSauvegarde();

}


Saver::~Saver()
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

void Saver::loadSauvegarde()
{

}

void Saver::saveSauvegarde()
{
  saveDataCard();
}

void Saver::saveDataCard()
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
