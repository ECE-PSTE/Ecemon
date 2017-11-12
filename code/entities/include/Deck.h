#ifndef DEF_DECK
#define DEF_DECK

#define NB_CARD_DECK 30 ///Tempory, wait namespace with parameter

#include <string>
#include <vector>
#include <iostream>

#include "Card.h"

class Deck{
    private:
        std::string m_name;
        std::vector<Card*> m_cards;

        bool m_wasDeserialized;

    public:
        Deck();
        Deck(const Deck &deck);
        Deck(std::string name);
        ~Deck();

        std::vector<Card*> getCards();
        std::string getName();

        void addCard(Card *card);
        void addCards(std::vector<Card*> cards);
        void setName(std::string name);

        //True if number of card of deck is same than number of card in a deck
        bool complete();

        friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
        friend std::istream& operator>>(std::istream& is, Deck& deck);
};

#endif
