#ifndef DEF_GAME
#define DEF_GAME

#include <map>
#include <fstream>

#include "../../entities/include/PowerCard.h"
#include "../../entities/include/EnergyCard.h"
#include "../../entities/include/CreatureCard.h"

namespace Game{
    inline const std::map<int, const Card*> LoadGameCards(){
        std::map<int, const Card*> cards;
        std::ifstream file(Constants::DefaultCardsFilename().c_str());
        if(file){
            std::string line;
            CardType type;
            int nbCards;

            getline(file, line);
            nbCards = std::stoi(line);

            for(int i=0 ; i<nbCards ; i++){
                getline(file, line);
                type = (CardType) std::stoi(line);
                Card* card;
                if(type==CardType_Energy){
                    card = new EnergyCard();
                }
                else if(type==CardType_Power){
                    card = new PowerCard();
                }
                else if(type==CardType_Creature){
                    card = new CreatureCard();
                }
                card->readCard(file);
                cards[card->getId()] = card;
            }
        }
        return cards;
    }

    const std::map<int, const Card*> Cards = LoadGameCards();
};

#endif
