#include "../include/PowerCard.h"

PowerCard::PowerCard(){
    m_stats = 0;
    m_powerType = PowerType_Undefined;
}

PowerCard::~PowerCard(){
}

int PowerCard::getStats(){
    return m_stats;
}

PowerType PowerCard::getPowerType(){
    return m_powerType;
}

void PowerCard::setStats(int stats){
    m_stats = stats;
}

void PowerCard::setPowerType(PowerType powerType){
    m_powerType = powerType;
}
