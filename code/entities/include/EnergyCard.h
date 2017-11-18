#ifndef DEF_ENERGYCARD
#define DEF_ENERGYCARD

#include <iostream>

#include "Card.h"
#include "EnergyType.h"
#include "CardType.h"
#include "Constants.h"

#include "../../utils/Utils.h"

class EnergyCard : public Card {
    private:
        EnergyType m_energyType;
        int m_energy;

    public:
        EnergyCard();
        EnergyCard(int id);
        ~EnergyCard();

        void writeCard(std::ostream &os) const;
        void readCard(std::istream &is);
        CardType type() const;

        EnergyType getEnergyType();
        int getEnergy();

        void setEnergyType(EnergyType energyType);
        void setEnergy(int energy);
};
#endif
