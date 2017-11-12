#include "../include/Profile.h"

Profile::Profile(){
    m_name = "Default Profile Name";
}

Profile::Profile(std::string name){
    m_name = name;
}

Profile::~Profile(){
    for(auto pDeck : m_decks){
        delete pDeck;
    }
}

Deck* Profile::getpCards(){
    return &m_cards;
}

std::vector<Deck*>* Profile::getpDecks(){
    return &m_decks;
}

std::string Profile::getName(){
    return m_name;
}

void Profile::addCard(Card* card){
    m_cards.addCard(card);
}

void Profile::addCards(std::vector<Card*> cards){
    m_cards.addCards(cards);
}

void Profile::addDeck(Deck *deck){
    m_decks.push_back(deck);
}

void Profile::setName(std::string name){
    m_name = name;
}

bool Profile::deleteDeck(std::string name)
{
    for(int i=0 ; i<m_decks.size() ; i++){
        if(m_decks[i]->getName() == name){
            m_decks.erase(m_decks.begin() + i);
            return true;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const Profile& profile){
    os << profile.m_name << std::endl;
    os << profile.m_cards << std::endl;

    int length = profile.m_decks.size();
    os << length << std::endl;
    for(int i=0 ; i<length ; i++){
        os << *profile.m_decks[i];
        if(i!=length-1){
            os << std::endl;
        }
    }

    return os;
}

std::istream& operator>>(std::istream& is, Profile& profile){
    getline(is, profile.m_name);
    is >> profile.m_cards;

    std::string line;
    int length;

    getline(is, line);
    length = std::stoi(line);
    for(int i=0 ; i<length ; i++){
        Deck *deck = new Deck();
        is >> *deck;
        profile.m_decks.push_back(deck);
    }

    return is;
}
