#include "../include/Profil.h"

Profil::Profil(){
    m_name = "Default Profil Name";
}

Profil::Profil(std::string name){
    m_name = name;
}

Profil::~Profil(){
    for(auto pDeck : m_decks){
        delete pDeck;
    }
}

Deck* Profil::getpCards(){
    return &m_cards;
}

std::vector<Deck*>* Profil::getpDecks(){
    return &m_decks;
}

std::string Profil::getName(){
    return m_name;
}

void Profil::addCard(Card* card){
    m_cards.addCard(card);
}

void Profil::addCards(std::vector<Card*> cards){
    m_cards.addCards(cards);
}

void Profil::addDeck(Deck *deck){
    m_decks.push_back(deck);
}

void Profil::setName(std::string name){
    m_name = name;
}

bool Profil::deleteDeck(std::string name)
{
    for(int i=0 ; i<m_decks.size() ; i++){
        if(m_decks[i]->getName() == name){
            m_decks.erase(m_decks.begin() + i);
            return true;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const Profil& profil){
    os << profil.m_name << std::endl;
    os << profil.m_cards << std::endl;

    int length = profil.m_decks.size();
    os << length << std::endl;
    for(int i=0 ; i<length ; i++){
        os << *profil.m_decks[i];
        if(i!=length-1){
            os << std::endl;
        }
    }

    return os;
}

std::istream& operator>>(std::istream& is, Profil& profil){
    getline(is, profil.m_name);
    is >> profil.m_cards;

    std::string line;
    int length;

    getline(is, line);
    length = std::stoi(line);
    for(int i=0 ; i<length ; i++){
        Deck *deck = new Deck();
        is >> *deck;
        profil.m_decks.push_back(deck);
    }

    return is;
}
