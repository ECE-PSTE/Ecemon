#include "../include/PowerCard.h"

PowerCard::PowerCard(){
    m_stats = 0;
    m_powerType = PowerType_Undefined;
}

PowerCard::PowerCard(int id){
    m_id = id;
    m_stats = 0;
    m_powerType = PowerType_Undefined;
}

PowerCard::~PowerCard(){
}

void PowerCard::writeCard(std::ostream &os){
    Card::writeCard(os);
    os << m_stats << std::endl;
    os << m_powerType << std::endl;
}

void PowerCard::readCard(std::istream &is){
    Card::readCard(is);
    is >> m_stats;
    int pt;
    is >> pt;
    m_powerType = (PowerType) pt;
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

CardType PowerCard::type(){
    return CardType_Power;
}
