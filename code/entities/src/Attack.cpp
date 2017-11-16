#include "../include/Attack.h"

Attack::Attack(){
    m_name = Constants::DefaultAttackName();
    m_description = Constants::DefaultAttackDescription();
    m_attackType = Constants::DefaultAttackType();
    m_cost = Constants::DefaultAttackCost();
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

void Attack::setName(std::string name){
    m_name = name;
}

void Attack::setDescription(std::string description){
    m_description = description;
}

void Attack::setAttackType(EnergyType attackType){
    m_attackType = attackType;
}

void Attack::setCost(int cost){
    m_cost = cost;
}
