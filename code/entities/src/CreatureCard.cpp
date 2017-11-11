#include "../include/CreatureCard.h"

CreatureCard::CreatureCard(){
    m_life = 0;
}

CreatureCard::~CreatureCard(){
}

int CreatureCard::getLife(){
    return m_life;
}

Attack CreatureCard::getFirstAttack(){
    return m_firstAttack;
}

Attack CreatureCard::getSecondAttack(){
    return m_secondAttack;
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
