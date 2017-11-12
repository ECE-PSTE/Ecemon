#include "../include/Saver.h"

Saver::Saver()
{
    loadSaver();
}

Saver::~Saver()
{

}

void Saver::loadSaver()
{
    ifstream fichierCard("../../../DataGame/DataCard.txt", ios::in);  // on ouvre le fichier en lecture

    if(fichierCard)  // si l'ouverture a réussi
    {
        int nb_card, id, nb_energy, nb_stats, nb_lp, nbCostAttack;
        char typeC;
        std::string nameC, descriptionC, nameA, descriptionA;
        EnergyType typeE;
        PowerType powerType;
        fichierCard >> nb_card;

        for(int i = 0; i < nb_card ; i++)
        {
            fichierCard >> id >> nameC >> descriptionC >> typeC;

            switch (typeC) {
                case 'C':
                    fichierCard >> nb_lp;
                    (*getpDataCard())[id] = new CreatureCard();
                    (*getpDataCard())[id]->setCardType(CardType_Creature);
                    (*getpDataCard())[id]->setLife(nb_lp);
                    //Attack 1
                    fichierCard >> nameA >> descriptionA >> typeE >> nbCostAttack;
                    (*getpDataCard())[id]->getFirstAttack().setName(nameA);
                    (*getpDataCard())[id]->getFirstAttack().setDescription(descriptionA);
                    (*getpDataCard())[id]->getFirstAttack().setAttackType(typeE);
                    (*getpDataCard())[id]->getFirstAttack().setCost(nbCostAttack);
                    //Attack 2
                    fichierCard >> nameA >> descriptionA >> typeE >> nbCostAttack;
                    (*getpDataCard())[id]->getSecondAttack().setName(nameA);
                    (*getpDataCard())[id]->getSecondAttack().setDescription(descriptionA);
                    (*getpDataCard())[id]->getSecondAttack().setAttackType(typeE);
                    (*getpDataCard())[id]->getSecondAttack().setCost(nbCostAttack);
                    break;
                case 'P':
                    fichierCard >> powerType >> nb_stats;
                    (*getpDataCard())[id] = new PowerCard();
                    (*getpDataCard())[id]->setStats(nb_stats);
                    (*getpDataCard())[id]->setPowerType(powerType);
                    (*getpDataCard())[id]->setCardType(CardType_Power);
                    break;
                case 'E':
                    fichierCard >> typeE >> nb_energy;
                    (*getpDataCard())[id] = new EnergyCard();
                    (*getpDataCard())[id]->setCardType(CardType_Energy);
                    (*getpDataCard())[id]->setEnergyType(typeE);
                    (*getpDataCard())[id]->setEnergy(nb_energy);
                    break;
                default :
                    std::cout << "Error type read of Card" << '\n';
            }

            (*getpDataCard())[id]->setId(id);
            (*getpDataCard())[id]->setName(nameC);
            (*getpDataCard())[id]->setDescription(descriptionC);

        }


        fichierCard.close();  // on ferme le fichier
    }
    else  // sinon
        std::cout << "Impossible d'ouvrir le fichier DataCard.txt !" << endl;
}
