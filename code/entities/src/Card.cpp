#include "../include/Card.h"

Card::Card(){
    m_id = 0;
    m_cardType = Undefined;
    m_name = "Default Card";
    m_description = "Default description";
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
