#ifndef SAVER_H
#define SAVER_H

#include <iostream>

#include "../../entities/include/Profil.h"
#include "../../entities/include/Card.h"

#include <fstream>
#include <vector>
#include <map>

class Saver
{
    private:
        std::vector<Profil*> m_dataProfil;
        //int id card / pointeur of card
        std::map<int, Card*> m_dataCard;

    public:
        /** Default constructor */
        Saver();
        /** Default destructor */
        ~Saver();

        void testaff();

};
#endif // SAVER_H
