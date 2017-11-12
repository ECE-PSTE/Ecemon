#ifndef DEF_SAUVER
#define DEF_SAUVER

#include "Profil.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Saver {
    private:
        std::vector<Profil*> m_dataProfil;
        //int id card / pointeur of card
        std::map<int, Card*> m_dataCard;

        //Save a card in the fill pass, the card is in a map with his Id and pointeur of card
        void saveCardOnFil(const std::pair<const int, Card*> pMap, std::ofstream filCard);

    public:
        Saver();
        ~Saver();

        //GETTER : pointeur of m_dataProfil
        std::vector<Profil*>* getpDataProfil(){return &m_dataProfil;}

        //GETTER : pointeur of m_dataCard
        std::map<int, Card*>* getpDataCard(){return &m_dataCard;}

        //GETTER : m_dataCard
        std::map<int, Card*> getDataCard(){return m_dataCard;}

        //Function who load all data on .txt to our game's Profil of players and Card
        void loadSauvegarde();

        //Function who right on .txt every infomrations about card and profil for tne next use of application
        void saveSauvegarde();

        //Function who will save in SauvegardeData/CardData.txt all data about our card
        void saveDataCard();

    };


#endif
