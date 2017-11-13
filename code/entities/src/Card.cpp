#include "../include/Card.h"

Card::Card(){
    m_id = -1;
    m_cardType = CardType_Undefined;
    m_name = "Default Card Name";
    m_description = "Default Card Description";
}

Card::Card(const Card &card){
    m_id = card.m_id;
    m_cardType = card.m_cardType;
    m_name = card.m_name;
    m_description = card.m_description;
}

Card::~Card(){
}

int Card::getId(){
    return m_id;
}

std::string Card::getName(){
    return m_name;
}

std::string Card::getDescription(){
    return m_description;
}

void Card::setId(int id){
    m_id = id;
}

void Card::setName(std::string name){
    m_name = name;
}

void Card::setDescription(std::string description){
    m_description = description;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    os << card.m_id << std::endl;
    os << card.m_cardType << std::endl;
    os << card.m_name << std::endl;
    os << card.m_description;
    return os;
}

std::istream& operator>>(std::istream& is, Card& card){
    std::string line;

    getline(is, line);
    card.m_id = std::stoi(line);

    getline(is, line);
    card.m_cardType = (CardType) std::stoi(line);

    getline(is, card.m_name);
    getline(is, card.m_description);
    
    return is;
}
