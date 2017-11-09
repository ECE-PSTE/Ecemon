#include "../include/Card.h"

Card::Card(){
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
