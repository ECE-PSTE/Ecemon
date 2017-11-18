#ifndef DEF_DECK
#define DEF_DECK

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "Card.h"
#include "Constants.h"

#include "../../utils/GameUtils.h"
#include "../../utils/Utils.h"

class Deck{
    private:
        std::string m_name;
        std::vector<const Card*> m_cards;

    public:
        Deck();
        Deck(const Deck &deck);
        Deck(std::string name);

        std::vector<const Card*> getCards();
        std::string getName();

        void addCard(const Card* card);
        void addCards(std::vector<const Card*> cards);
        void setName(std::string name);

        //true if card take off
        bool takeoffCard(const Card* card);
        Card* creatureRandom();

        bool isComplete();

        friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
        friend std::istream& operator>>(std::istream& is, Deck& deck);
};

#endif
