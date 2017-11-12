#ifndef DEF_SAUVER
#define DEF_SAUVER

#include <iostream>

#include "../../entities/include/Profil.h"
#include "../../entities/include/Card.h"
#include "../../entities/include/EnergyCard.h"
#include "../../entities/include/EnergyType.h"
#include "../../entities/include/CardType.h"
#include "../../entities/include/CreatureCard.h"
#include "../../entities/include/Attack.h"

#include "../../entities/src/Profil.cpp"
#include "../../entities/src/Card.cpp"
#include "../../entities/src/EnergyCard.cpp"

#include <fstream>
#include <vector>
#include <map>

class Saver {
    private:
        std::vector<Profil*> m_dataProfil;
        //int id card / pointeur of card
        std::map<int, Card*> m_dataCard;

    public:
        /** Default constructor */
        Saver();
        /** Default destructor */
        ~Saver();

        //GETTER : pointeur of m_dataProfil
        std::vector<Profil*>* getpDataProfil(){return &m_dataProfil;}

        //GETTER : m_dataProfil
        std::vector<Profil*> getDataProfil(){return m_dataProfil;}

        //GETTER : pointeur of m_dataCard
        std::map<int, Card*>* getpDataCard(){return &m_dataCard;}

        //GETTER : m_dataCard
        std::map<int, Card*> getDataCard(){return m_dataCard;}

        //Function who load all data on .txt to our game's Profil of players and Card
        void loadSaver();

};
#endif // SAVER_H
