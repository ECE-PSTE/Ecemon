#ifndef DEF_POWERCARD
#define DEF_POWERCARD

#include <iostream>

#include "Card.h"
#include "PowerType.h"
#include "CardType.h"
#include "Constants.h"

class PowerCard : public Card {
    private:
        int m_stats;
        PowerType m_powerType;

    public:
        PowerCard();
        PowerCard(int id);
        ~PowerCard();

        void writeCard(std::ostream &os);
        void readCard(std::istream &is);

        int getStats();
        PowerType getPowerType();

        void setStats(int stats);
        void setPowerType(PowerType powerType);

        CardType type();
};
#endif
