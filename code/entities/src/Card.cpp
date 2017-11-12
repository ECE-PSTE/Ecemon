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

CardType Card::getCardType(){
    return m_cardType;
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

void Card::setCardType(CardType type){
    m_cardType = type;
}

void Card::setName(std::string name){
    m_name = name;
}

void Card::setDescription(std::string description){
    m_description = description;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    os << card.m_id << std::endl;
    os << card.m_name << std::endl;
    os << card.m_description;
    return os;
}

std::istream& operator>>(std::istream& is, Card& card){
    std::string line;
    std::stringstream ss;

    getline(is, line);
    ss << line;
    ss >> card.m_id;

    getline(is, line);
    card.m_name = line;

    getline(is, line);
    card.m_description = line;
}
