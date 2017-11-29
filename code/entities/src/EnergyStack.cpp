#include "../include/EnergyStack.h"

EnergyStack::EnergyStack(): m_chili(0), m_tacos(0), m_iceCream(0), m_blueberries(0){
    //Yooo
}

EnergyStack::~EnergyStack(){
    //mdrrrr
}

void EnergyStack::addEnergy(EnergyType eType, int quantity){
    switch (eType) {
        case EnergyType_Chili:
            setChili(getChili() + quantity);
            break;
        case EnergyType_Tacos:
            setTacos(getTacos() + quantity);
            break;
        case EnergyType_IceCream:
            setIceCream(getIceCream() + quantity);
            break;
        case EnergyType_Blueberries:
            setBlueberries(getBlueberries() + quantity);
            break;
        default:
            std::cout<<"Error EnergyType in addEnergy" << std::endl;
    }
}
