#include "../include/Card.h"

Card::Card(){
    m_id = -1;
    m_name = "Default Card Name";
    m_description = "Default Card Description";
}

Card::Card(const Card &card){
    m_id = card.m_id;
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
    os << card.m_id;
    return os;
}

std::istream& operator>>(std::istream& is, Card& card){
    is >> card.m_id;
    return is;
}
