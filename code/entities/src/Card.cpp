#include "../include/Card.h"

Card::Card(){
    m_id = Constants::DefaultCardId();
    m_name = Constants::DefaultCardName();
    m_description = Constants::DefaultCardDescription();
}

Card::Card(const Card &card){
    m_id = card.m_id;
    m_name = card.m_name;
    m_description = card.m_description;
}

Card::~Card(){
}

void Card::writeCard(std::ostream &os) const{
    os << m_id << std::endl;
    os << m_name << std::endl;
    os << m_description << std::endl;
}

void Card::readCard(std::istream &is){
    std::string line;
    getline(is, line);
    m_id = std::stoi(line);
    getline(is, m_name);
    getline(is, m_description);
}

CardType Card::type() const{
    return Constants::DefaultCardType();
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
    std::string line;
    getline(is, line);
    card.m_id = std::stoi(line);
    return is;
}
