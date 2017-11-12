#ifndef DEF_PROFIL
#define DEF_PROFIL

#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "Deck.h"

class Profil{
    private:
        std::string m_name;
        std::vector<std::pair<Card*, int> > m_cards; // <Card*, int> = <Card, nb of occurrences>
        std::vector<Deck*> m_decks;

    public:
        Profil();
        Profil(std::string nom);
        ~Profil();

        std::vector<std::pair<Card*, int> >* getpCards();
        std::vector<Deck*>* getpDecks();
        std::string getName();

        void addCard(std::pair<Card*, int> card);
        void addDeck(Deck *deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Profil& profil);
        friend std::istream& operator>>(std::istream& is, Profil& profil);
    };

#endif
