#ifndef DEF_PROFILE
#define DEF_PROFILE

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "Deck.h"
#include "Constants.h"

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
        std::vector<Deck*> getDecks(){return m_decks;}

        Deck getCollectionDeck(){return m_cards;}
        std::string getName();

        void addDeck(Deck *deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Profile& profile);
        friend std::istream& operator>>(std::istream& is, Profile& profile);
    };

#endif
