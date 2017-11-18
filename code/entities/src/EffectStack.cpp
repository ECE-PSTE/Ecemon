#include "../include/EffectStack.h"

EffectStack::EffectStack(): m_freez(false), m_damage(0){
    //Coucou
}

EffectStack::~EffectStack(){
    //Chalut
}

void EffectStack::endTurn(){
    setFreez(false);
}

void EffectStack::takeDamage(int damage){
    setDamage(getDamage() + damage);
}

void EffectStack::newCreature(){
    setFreez(false);
    setDamage(0);
}
