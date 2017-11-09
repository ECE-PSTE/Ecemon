#include "../include/EnergyCard.h"

EnergyCard::EnergyCard(){
}

EnergyCard::~EnergyCard(){
}

EnergyType EnergyCard::getEnergyType(){
    return m_energyType;
}

int EnergyCard::getEnergy(){
    return m_energy;
}
