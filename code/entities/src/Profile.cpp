#include "../include/Profile.h"

Profile::Profile(){
    m_name = Constants::DefaultProfileName();
}

Profile::Profile(std::string name){
    m_name = name;
}

Profile::~Profile(){
    for(auto pDeck : m_decks){
        delete pDeck;
    }
}

std::string Profile::getName(){
    return m_name;
}

std::vector<Deck*>* Profile::getpDecks(){
    return &m_decks;
}

std::vector<Deck*> Profile::getDecks(){
    return m_decks;
}

Deck* Profile::getpCards(){
    return &m_cards;
}

Deck Profile::getCards(){
    return m_cards;
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
    getline(is, line);
    int length = Utils::toInt(line);

    for(int i=0 ; i<length ; i++){
        Deck *deck = new Deck();
        is >> *deck;
        profile.m_decks.push_back(deck);
    }

    return is;
}
