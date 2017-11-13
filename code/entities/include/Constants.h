#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <map>

#include "CreatureCard.h"
#include "EnergyCard.h"
#include "PowerCard.h"

const std::map<int, const Card*> CARDS_MAP = {
    {1, new EnergyCard(1)},
    {2, new PowerCard(2)},
    {3, new CreatureCard(3)},
    /* .... */
};

const int DECK_SIZE = 30;

#endif
