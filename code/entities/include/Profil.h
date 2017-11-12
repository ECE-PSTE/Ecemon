#ifndef DEF_PROFIL
#define DEF_PROFIL

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "Deck.h"

class Profil{
    private:
        std::string m_name;
        std::vector<Deck*> m_decks;
        Deck m_cards;

    public:
        Profil();
        Profil(std::string nom);
        ~Profil();

        Deck* getpCards();
        std::vector<Deck*>* getpDecks();
        std::string getName();

        void addCard(Card *card);
        void addCards(std::vector<Card*> cards);
        void addDeck(Deck *deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Profil& profil);
        friend std::istream& operator>>(std::istream& is, Profil& profil);
    };

#endif
