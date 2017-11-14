#include "../include/CreatureCard.h"

CreatureCard::CreatureCard(){
    m_life = 0;
}

CreatureCard::CreatureCard(int id){
    m_id = id;
    m_life = 0;
}

CreatureCard::~CreatureCard(){
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

CardType CreatureCard::type(){
    return CardType_Creature;
}
