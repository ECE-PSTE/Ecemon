#ifndef DEF_POWERCARD
#define DEF_POWERCARD

#include "Card.h"
#include "PowerType.h"

class PowerCard : public Card {
    private:
        int m_stats;
        PowerType m_powerType;

    public:
        PowerCard();
        ~PowerCard();

        int getStats();
        PowerType getPowerType();

        void setStats(int stats);
        void setPowerType(PowerType powerType);
};
#endif
