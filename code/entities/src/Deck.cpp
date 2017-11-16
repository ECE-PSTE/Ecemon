#include "../include/Deck.h"

Deck::Deck(){
    m_name = Constants::DefaultDeckName();
}

Deck::Deck(const Deck &deck){
    m_name = deck.m_name;
    m_cards = deck.m_cards;
}

Deck::Deck(std::string name){
    m_name = name;
}

std::vector<const Card*> Deck::getCards(){
    return m_cards;
}

std::string Deck::getName(){
    return m_name;
}

void Deck::addCard(const Card* card){
    m_cards.push_back(card);
}

void Deck::addCards(std::vector<const Card*> cards){
    m_cards.insert(m_cards.begin(), cards.begin(), cards.end());
}

void Deck::setName(std::string name){
    m_name = name;
}

bool Deck::isComplete(){
    return (m_cards.size() == Constants::DefaultDeckSize());
}

std::ostream& operator<<(std::ostream& os, const Deck& deck){
    int length = deck.m_cards.size();
    os << deck.m_name << std::endl;
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
    std::string line;
    getline(is, deck.m_name);
    getline(is, line);
    int length = std::stoi(line);
    Card card;
    for(int i=0 ; i<length ; i++){
        is >> card;
        deck.m_cards.push_back(Game::Cards.at(card.getId()));
    }
    return is;
}

bool Deck::takeoffCard(const Card* card){

    std::vector<Card*>::iterator i;
    for(i = getCards().begin() ; i != getCards().end(); i++){
        if(card == *i){
            getCards().erase(i);
            return true;
        }
    }
    return false;
}

Card* Deck::creatureRandom(){

    Card* p;
    int hasard;

    srand(time(NULL));

    do{
        hasard = rand()%getCards().size();
        p = getCards()[hasard];
    }while(p->type() == CardType_Creature);

    return p;
}
