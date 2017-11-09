#include "../include/PowerCard.h"

PowerCard::PowerCard(){
}

PowerCard::~PowerCard(){
}

int PowerCard::getStats(){
    return m_stats;
}

PowerType PowerCard::getPowerType(){
    return m_powerType;
}
