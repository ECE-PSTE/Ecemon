#include "../include/EnergyCard.h"

EnergyCard::EnergyCard(){
    m_energyType = EnergyType_Undefined;
    m_energy = 0;
}

EnergyCard::~EnergyCard(){
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
