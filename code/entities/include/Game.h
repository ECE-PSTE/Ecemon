#ifndef DEF_GAME
#define DEF_GAME

#include <map>

#include "PowerCard.h"
#include "EnergyCard.h"
#include "CreatureCard.h"

namespace Game{
    const std::map<int, const Card*> Cards = {
        {1, new EnergyCard(1)},
        {2, new PowerCard(2)},
        {3, new CreatureCard(3)}
    };
};

#endif
