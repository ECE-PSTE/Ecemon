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
        ~EnergyCard();

        EnergyType getEnergyType();
        int getEnergy();
};
#endif
