#include "../include/Attack.h"

Attack::Attack(){
}

Attack::~Attack(){
}

std::string Attack::getName(){
    return m_name;
}

std::string Attack::getDescription(){
    return m_description;
}

EnergyType Attack::getAttackType(){
    return m_attackType;
}

int Attack::getCost(){
    return m_cost;
}
