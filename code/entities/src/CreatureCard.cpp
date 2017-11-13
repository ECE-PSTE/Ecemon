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

std::vector<Attack> CreatureCard::getVattack()
{
    return m_vattack;
}

void CreatureCard::setLife(int life){
    m_life = life;
}

void CreatureCard::setFirstAttack(Attack firstAttack){
    m_firstAttack = firstAttack;
}

void CreatureCard::setSecondAttack(Attack secondAttack){
    m_secondAttack = secondAttack;
}

CardType CreatureCard::type(){
    return CardType_Creature;
}
