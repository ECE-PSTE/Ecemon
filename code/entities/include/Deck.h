#ifndef DEF_DECK
#define DEF_DECK

#define NB_CARD_DECK 30 ///Tempory, wait namespace with parameter

#include <iostream>

#include <vector>

class Deck{
    private:
        std::string m_nom;
        std::vector<int> m_vecteurIdCardDeck;


    public:
        Deck();
        //Constructor with the name
        Deck(std::string nom);

        ~Deck();

        //GETTER : pointeur of m_vecteurIdCardDeck
        std::vector<int>* getpVecteurIdCardDeck(){return &m_vecteurIdCardDeck;}

        //GETTER : std::string m_nom
        std::string getNom(){return m_nom;}

        //Setter : std::string m_nom
        void setNom(std::string val){m_nom = val;}

        //True if number of card of deck is same than number of card in a deck
        bool complet();

    };

#endif
