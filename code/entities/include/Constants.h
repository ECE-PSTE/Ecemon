#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <string>
#include "EnergyType.h"

namespace Constants {
    const std::string DefaultProfileName = "Default Profile Name";

    const int DeckSize = 30;
    const std::string DefaultDeckName = "Default Deck Name";

    const int DefaultCreatureLife = 100;

    const int DefaultEnergy = 5;
    const EnergyType DefaultEnergyType = EnergyType_Undefined;

    const int DefaultPowerStats = -1;

    const int DefaultCardId = -1;
    const std::string DefaultCardName = "Default Card Name";
    const std::string DefaultCardDescription = "Default Card Description";

    const int DefaultAttackCost = 10;
    const EnergyType DefaultAttackType = EnergyType_Undefined;
    const std::string DefaultAttackName = "Default Attack Name";
    const std::string DefaultAttackDescription = "Default Attack Description";
}

#endif
