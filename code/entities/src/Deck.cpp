#include "../include/Deck.h"

Deck::Deck(){
    m_name = "Default Deck Name";
    m_wasDeserialized = false;
}

Deck::Deck(const Deck &deck){
    m_name = deck.m_name;
    m_cards = deck.m_cards;
    m_wasDeserialized = deck.m_wasDeserialized;
}

Deck::Deck(std::string name){
    m_name = name;
    m_wasDeserialized = false;
}

Deck::~Deck(){
    // for now...
    if(m_wasDeserialized){
        for(auto pCard : m_cards){
            delete pCard;
        }
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

    int length = deck.m_cards.size();
    os << length << std::endl;
    for(int i=0 ; i<length ; i++){
        os << *deck.m_cards[i];
        if(i!=length-1){
            os << std::endl;
        }
    }
    return os;
}

std::istream& operator>>(std::istream& is, Deck& deck){
    deck.m_wasDeserialized = true;

    getline(is, deck.m_name);

    std::string line;
    int length;

    getline(is, line);
    length = std::stoi(line);

    for(int i=0 ; i<length ; i++){
        Card *card = new Card();
        is >> *card;
        deck.m_cards.push_back(card);
    }
    return is;
}
