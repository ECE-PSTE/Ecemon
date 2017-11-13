#ifndef DEF_PROFILE
#define DEF_PROFILE

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "Deck.h"

class Profile{
    private:
        std::string m_name;
        std::vector<Deck*> m_decks;
        Deck m_cards;

    public:
        Profile();
        Profile(std::string nom);
        ~Profile();

        Deck* getpCards();
        std::vector<Deck*>* getpDecks();
        std::string getName();

        void addCard(const Card *card);
        void addCards(std::vector<const Card*> cards);
        void addDeck(Deck *deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Profile& profile);
        friend std::istream& operator>>(std::istream& is, Profile& profile);
    };

#endif
