#ifndef DEF_PROFILE
#define DEF_PROFILE

#include <iostream>
#include <vector>
#include <map>

#include "Deck.h"
#include "Constants.h"

#include "../../utils/Utils.h"

class Profile{
    private:
        std::string m_name;
        std::vector<Deck*> m_decks;
        Deck m_cards;

    public:
        Profile();
        Profile(std::string nom);
        ~Profile();

        std::string getName() const;
        std::vector<Deck*>* getpDecks();
        std::vector<Deck*> getDecks() const;
        Deck* getpCards();
        Deck getCards() const;

        void addDeck(Deck *deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Profile& profile);
        friend std::istream& operator>>(std::istream& is, Profile& profile);
    };

#endif
