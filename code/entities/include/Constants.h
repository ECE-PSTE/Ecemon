#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <map>
#include <fstream>

#include "EnergyCard.h"
#include "PowerCard.h"

namespace Constants {
    const int DeckSize = 30;
    const std::map<int, const Card*> Cards = {
        {1, new EnergyCard(1)},
        {2, new PowerCard(2)}
    };
}

#endif
