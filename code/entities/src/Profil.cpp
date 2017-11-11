#include "../include/Profil.h"

Profil::Profil(){
    m_name = "Default Profil Name";
}

Profil::Profil(std::string name){
    m_name = name;
}

Profil::~Profil(){
}

std::vector<std::pair<int, int> >* Profil::getpCards(){
    return &m_cards;
}

std::vector<Deck>* Profil::getpDecks(){
    return &m_decks;
}

std::string Profil::getName(){
    return m_name;
}

void Profil::addCard(std::pair<int, int> card){
    m_cards.push_back(card);
}

void Profil::addDeck(Deck deck){
    m_decks.push_back(deck);
}

bool Profil::deleteDeck(std::string name)
{
    for(int i=0 ; i<m_decks.size() ; i++){
        if(m_decks[i].getName() == name){
            m_decks.erase(m_decks.begin() + i);
            return true;
        }
    }

    return false;
}
