#ifndef DEF_ENERGYCARD
#define DEF_ENERGYCARD

#include "Card.h"
#include "EnergyType.h"

class EnergyCard : public Card {
    private:
        EnergyType m_energyType;
        int m_energy;

    public:
        EnergyCard();
        EnergyCard(int id);
        ~EnergyCard();

        EnergyType getEnergyType();
        int getEnergy();

        void setEnergyType(EnergyType energyType);
        void setEnergy(int energy);
};
#endif
