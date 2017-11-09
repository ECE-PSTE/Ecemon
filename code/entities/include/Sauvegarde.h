#ifndef DEF_SAUVEGARDE
#define DEF_SAUVEGARDE

#include "Card.h"
#include <vector>


class EnergyCard{
    private:
        std::vector<Profil*> m_dataProfil;
        std::map<int, Card*> m_dataCard;

    public:
        Sauvegarde();
        ~Sauvegarde();

        //GETTER : pointeur of m_dataProfil
        std::vector<Profil*>* getpDataProfil(){return &m_dataProfil;}

        //GETTER : pointeur of m_dataCard
        std::map<int, Card*>* getpDataCard(){return &m_dataCard;}

        //Function who load all data on .txt to our game's Profil of players and Card
        void loadSauvegarde();

        //Function who right on .txt every infomrations about card and profil for tne next use of application
        void saveSauvegarde();

    };


#endif
