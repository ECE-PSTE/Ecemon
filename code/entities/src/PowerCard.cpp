#include "../include/PowerCard.h"

PowerCard::PowerCard(){
    m_stats = Constants::DefaultPowerStats();
    m_powerType = Constants::DefaultPowerType();
}

PowerCard::PowerCard(int id){
    m_id = id;
    m_stats = Constants::DefaultPowerStats();
    m_powerType = Constants::DefaultPowerType();
}

PowerCard::~PowerCard(){
}

void PowerCard::writeCard(std::ostream &os) const{
    Card::writeCard(os);
    os << m_stats << std::endl;
    os << m_powerType << std::endl;
}

void PowerCard::readCard(std::istream &is){
    Card::readCard(is);
    std::string line;
    getline(is, line);
    m_stats = Utils::toInt(line);
    getline(is, line);
    m_powerType = (PowerType) Utils::toInt(line);
}

CardType PowerCard::type() const{
    return CardType_Power;
}

int PowerCard::getStats() const{
    return m_stats;
}

PowerType PowerCard::getPowerType() const{
    return m_powerType;
}

void PowerCard::setStats(int stats){
    m_stats = stats;
}

void PowerCard::setPowerType(PowerType powerType){
    m_powerType = powerType;
}
