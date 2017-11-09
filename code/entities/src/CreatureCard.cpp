#include "../include/CreatureCard.h"

CreatureCard::CreatureCard(){
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
