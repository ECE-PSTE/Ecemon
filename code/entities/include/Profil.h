#ifndef DEF_PROFIL
#define DEF_PROFIL

#include <string>
#include <vector>
#include <utility>

#include "Deck.h"

class Profil{
    private:
        std::string m_name;
        std::vector<std::pair<int, int> > m_cards; // <int, int> = <id, nb of occurrences>
        std::vector<Deck> m_decks;

    public:
        Profil();
        Profil(std::string nom);
        ~Profil();

        std::vector<std::pair<int, int> >* getpCards();
        std::vector<Deck>* getpDecks();
        std::string getName();

        void addCard(std::pair<int, int> card);
        void addDeck(Deck deck);
        void setName(std::string name);

        // delete a deck by its name, return true if success
        bool deleteDeck(std::string name);
    };

#endif
