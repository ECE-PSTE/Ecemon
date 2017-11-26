#include "../include/EffectStack.h"

EffectStack::EffectStack() {
    //Coucou
}

EffectStack::~EffectStack(){
    //Chalut
}

int EffectStack::getDamage(){
    return m_damage;
}

void EffectStack::endTurn(){
    setFreez(false);
}

void EffectStack::takeDamage(int damage){
    m_damage += damage;
}

void EffectStack::newCreature(){
    std::cout<< "New creature\n";
    setFreez(false);
    setDamage(0);
}
