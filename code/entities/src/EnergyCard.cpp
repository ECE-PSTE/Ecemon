#include "../include/EnergyCard.h"

EnergyCard::EnergyCard(){
    m_energyType = Constants::DefaultEnergyType();
    m_energy = Constants::DefaultEnergy();
}

EnergyCard::EnergyCard(int id){
    m_id = id;
    m_energyType = Constants::DefaultEnergyType();
    m_energy = Constants::DefaultEnergy();
}

EnergyCard::~EnergyCard(){
}

void EnergyCard::writeCard(std::ostream &os) const{
    Card::writeCard(os);
    os << m_energyType << std::endl;
    os << m_energy << std::endl;
}

void EnergyCard::readCard(std::istream &is){
    Card::readCard(is);
    std::string line;
    getline(is, line);
    m_energyType = (EnergyType) Utils::toInt(line);
    getline(is, line);
    m_energy = Utils::toInt(line);
}

CardType EnergyCard::type() const{
    return CardType_Energy;
}

EnergyType EnergyCard::getEnergyType() const{
    return m_energyType;
}

int EnergyCard::getEnergy() const{
    return m_energy;
}

void EnergyCard::setEnergyType(EnergyType energyType){
    m_energyType = energyType;
}

void EnergyCard::setEnergy(int energy){
    m_energy = energy;
}
