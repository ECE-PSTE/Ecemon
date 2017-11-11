#include "../include/Attack.h"

Attack::Attack(){
    m_name = "Default Attack Name";
    m_description = "Default Attack Description";
    m_attackType = EnergyType_Undefined;
    m_cost = 0;
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
