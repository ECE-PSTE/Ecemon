#include "..\include\Effectstack.h"

Effectstack::Effectstack(): m_freez(false), m_damage(0){
    //Coucou
}

Effectstack::~Effectstack(){
    //Chalut
}

void Effectstack::endTurn(){
    setFreez(false);
}

void Effectstack::takeDamage(int damage){
    setDamage(getDamage() + damage);
}

void Effectstack::newCreature(){
    setFreez(false);
    setDamage(0);
}
