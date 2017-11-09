#ifndef DEF_PROFIL
#define DEF_PROFIL

#include <iostream>

#include "Card.h"
#include <vector>
#include <map>

class Profil{
    private:
        std::string m_nom;
        std::map<int, int> m_collectionCard;
        std::vector<Deck*> m_collectionDeck;


    public:
        Profil();
        //Constructor with the name
        Profil(std::string nom);

        ~Profil();

        //GETTER : pointeur of m_collectionDeck
        std::vector<Deck*>* getpCollectionDeck(){return &m_collectionDeck;}

        //GETTER : pointeur of m_collectionCard
        std::map<int, Card*>* getpCollectionCard(){return &m_collectionCard;}

        //GETTER : std::string m_nom
        std::string getNom(){return m_nom;}

        //Setter : std::string m_nom
        void setNom(std::string val){m_nom = val;}

        //Function who delete a deck from his profil with his name, true if success
        bool deleteDeck(std::string name);

    };

#endif
