#include "../include/EffectStack.h"

EffectStack::EffectStack() {
    //Coucou
}

EffectStack::~EffectStack(){
    //Chalut
}

void EffectStack::endTurn(){
    setFreez(false);
}

void EffectStack::takeDamage(int damage){
    m_damage += damage;
}

void EffectStack::newCreature(){
    setFreez(false);
    setDamage(0);
}
