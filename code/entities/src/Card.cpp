#include "../include/Card.h"

Card::Card(){
    m_id = -1;
    m_cardType = CardType_Undefined;
    m_name = "Default Card Name";
    m_description = "Default Card Description";
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
