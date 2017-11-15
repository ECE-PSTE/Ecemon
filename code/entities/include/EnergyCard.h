#ifndef DEF_ENERGYCARD
#define DEF_ENERGYCARD

#include <iostream>

#include "Card.h"
#include "EnergyType.h"
#include "CardType.h"

class EnergyCard : public Card {
    private:
        EnergyType m_energyType;
        int m_energy;

    public:
        EnergyCard();
        EnergyCard(int id);
        ~EnergyCard();

        void writeCard(std::ostream &os);
        void readCard(std::istream &is);

        EnergyType getEnergyType();
        int getEnergy();

        void setEnergyType(EnergyType energyType);
        void setEnergy(int energy);

        CardType type();
};
#endif
