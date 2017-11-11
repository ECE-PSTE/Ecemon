#include "../include/Profil.h"

Profil::Profil() : m_nom("Default")
{
}

Profil::Profil(std::string nom) : m_nom(nom)
{

}

Profil::~Profil()
{
  for(auto elem :  *getpCollectionDeck())
  {
    elem->~Deck();
    delete elem;
  }
}

bool Profil::deleteDeck(std::string name)
{
  for(auto elem : *getpCollectionDeck())
  {
    if(elem->getNom() == name)
    {
      elem->~Deck();
      delete elem;
      return true;
    }
  }

  return false;
}
