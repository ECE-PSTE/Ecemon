#include "../include/Deck.h"

Deck::Deck(){
    m_name = "Default Deck";
}

Deck::Deck(std::string name){
    m_name = name;
}

Deck::~Deck(){
}

std::vector<int>* Deck::getpCardIds(){
    return &m_cardIds;
}

std::string Deck::getName(){
    return m_name;
}

void Deck::addCard(int id){
    m_cardIds.push_back(id);
}

void Deck::addCards(std::vector<int> ids){
    m_cardIds.insert(m_cardIds.end(), ids.begin(), ids.end());
}

void Deck::setName(std::string name){
    m_name = name;
}

bool Deck::complete(){
    return (m_cardIds.size() == NB_CARD_DECK);
}
