#ifndef DEF_DECK
#define DEF_DECK

#define NB_CARD_DECK 30 ///Tempory, wait namespace with parameter

#include <string>
#include <vector>

class Deck{
    private:
        std::string m_name;
        std::vector<int> m_cardIds;

    public:
        Deck();
        Deck(std::string name);
        ~Deck();

        std::vector<int>* getpCardIds();
        std::string getName();

        void addCard(int id);
        void addCards(std::vector<int> ids);
        void setName(std::string name);

        //True if number of card of deck is same than number of card in a deck
        bool complete();
};

#endif
