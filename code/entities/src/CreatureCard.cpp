#include "../include/CreatureCard.h"

CreatureCard::CreatureCard(){
    m_life = Constants::DefaultCreatureLife;
}

CreatureCard::CreatureCard(int id){
    m_id = id;
    m_life = Constants::DefaultCreatureLife;
}

CreatureCard::~CreatureCard(){
}

void CreatureCard::writeCard(std::ostream &os){
    Card::writeCard(os);
    os << m_life << std::endl;
}

void CreatureCard::readCard(std::istream &is){
    Card::readCard(is);
    is >> m_life;
}

int CreatureCard::getLife(){
    return m_life;
}

std::vector<Attack> CreatureCard::getAttacks()
{
    return m_attacks;
}

void CreatureCard::setLife(int life){
    m_life = life;
}

void CreatureCard::addAttack(Attack attack){
    m_attacks.push_back(attack);
}

CardType CreatureCard::type(){
    return CardType_Creature;
}
