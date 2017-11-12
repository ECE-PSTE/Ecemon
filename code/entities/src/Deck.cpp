#include "../include/Deck.h"

Deck::Deck(){
    m_name = "Default Deck Name";
}

Deck::Deck(std::string name){
    m_name = name;
}

Deck::~Deck(){
    for(auto pCard : m_cards){
        delete pCard;
    }
}

std::vector<Card*> Deck::getCards(){
    return m_cards;
}

std::string Deck::getName(){
    return m_name;
}

void Deck::addCard(Card *card){
    m_cards.push_back(card);
}

void Deck::addCards(std::vector<Card*> cards){
    m_cards.insert(m_cards.end(), cards.begin(), cards.end());
}

void Deck::setName(std::string name){
    m_name = name;
}

bool Deck::complete(){
    return (m_cards.size() == NB_CARD_DECK);
}

std::ostream& operator<<(std::ostream& os, const Deck& deck){
    os << deck.m_name << std::endl;

    Card* last = deck.m_cards.back();
    for(auto pCard : deck.m_cards){
        os << *pCard;
        if(pCard!=last){
            os << std::endl;
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Deck& deck){
    getline(is, deck.m_name);

    Card card;
    while(!is.eof()){
        is >> card;
        deck.m_cards.push_back(new Card(card));
    }
    return is;
}
