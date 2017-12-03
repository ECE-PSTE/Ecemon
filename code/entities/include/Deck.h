#ifndef DEF_DECK
#define DEF_DECK

#include <iostream>
#include <vector>

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

        std::string getName() const;
        std::vector<const Card*>* getpCards();
        std::vector<const Card*> getCards() const;
        const Card* getCardById(int id) const;

        void addCard(const Card* card);
        void addCards(std::vector<const Card*> cards);
        void setName(std::string name);

        bool removeCard(const Card* card);
        const CreatureCard* creatureRandom();

        bool isComplete() const;

        friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
        friend std::istream& operator>>(std::istream& is, Deck& deck);
};

#endif
