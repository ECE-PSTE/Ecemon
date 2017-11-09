#include "../include/Sauvegarde.h"

Sauvegarde::Sauvegarde()
{
  loadSauvegarde();
}


Sauvegarde::~Sauvegarde()
{
  saveSauvegarde();
  for(auto elem : getpDataProfil())
  {
    elem->~Profil();
    delete elem;
  }
  for(auto elem : getpDataCard())
  {
    elem->~Card();
    delete elem;
  }
}

Sauvegarde::loadSauvegarde()
{

}

Sauvegarde::saveSauvegarde()
{

}
