#ifndef DEF_POWERCARD
#define DEF_POWERCARD

#include <iostream>

#include "Card.h"
#include "PowerType.h"
#include "CardType.h"
#include "Constants.h"

#include "../../utils/Utils.h"

class PowerCard : public Card {
    private:
        int m_stats;
        PowerType m_powerType;

    public:
        PowerCard();
        PowerCard(int id);
        ~PowerCard();

        void writeCard(std::ostream &os) const;
        void readCard(std::istream &is);
        CardType type() const;

        int getStats() const;
        PowerType getPowerType() const;

        void setStats(int stats);
        void setPowerType(PowerType powerType);
};
#endif
