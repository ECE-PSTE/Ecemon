#include "../include/EnergyCard.h"

EnergyCard::EnergyCard(){
    m_energyType = Constants::DefaultEnergyType;
    m_energy = Constants::DefaultEnergy;
}

EnergyCard::EnergyCard(int id){
    m_id = id;
    m_energyType = Constants::DefaultEnergyType;
    m_energy = Constants::DefaultEnergy;
}

EnergyCard::~EnergyCard(){
}

void EnergyCard::writeCard(std::ostream &os){
    Card::writeCard(os);
    os << m_energyType << std::endl;
    os << m_energy << std::endl;
}

void EnergyCard::readCard(std::istream &is){
    Card::readCard(is);
    int et;
    is >> et;
    m_energyType = (EnergyType) et;
    is >> m_energy;
}

EnergyType EnergyCard::getEnergyType(){
    return m_energyType;
}

int EnergyCard::getEnergy(){
    return m_energy;
}

void EnergyCard::setEnergyType(EnergyType energyType){
    m_energyType = energyType;
}

void EnergyCard::setEnergy(int energy){
    m_energy = energy;
}

CardType EnergyCard::type(){
    return CardType_Energy;
}
