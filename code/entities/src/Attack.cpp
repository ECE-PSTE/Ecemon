#include "../include/Attack.h"

Attack::Attack(){
    m_name = Constants::DefaultAttackName();
    m_description = Constants::DefaultAttackDescription();
    m_attackType = Constants::DefaultAttackType();
    m_cost = Constants::DefaultAttackCost();
    m_damage = Constants::DefaultDamageAttack();
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

int Attack::getDamage(){
    return m_damage;
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

void Attack::setDamage(int dam){
    m_damage = dam;
}

std::ostream& operator<<(std::ostream& os, const Attack& attack){
    os << attack.m_name << std::endl;
    os << attack.m_description << std::endl;
    os << attack.m_attackType << std::endl;
    os << attack.m_cost << std::endl;
    os << attack.m_damage;
}

std::istream& operator>>(std::istream& is, Attack& attack){
    std::string line;
    getline(is, attack.m_name);
    getline(is, attack.m_description);
    getline(is, line);
    attack.m_attackType = (EnergyType) Utils::toInt(line);
    getline(is, line);
    attack.m_cost = Utils::toInt(line);
    getline(is, line);
    attack.m_damage = Utils::toInt(line);
}
