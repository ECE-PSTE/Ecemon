#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <string>
#include "CardType.h"
#include "EnergyType.h"
#include "PowerType.h"

// ########################## NOTICE ##########################
// used functions to avoid “static initialization order fiasco”
// ############################################################

namespace Constants {
    // GAME
    inline std::string DefaultCardsFilename(){
        return "GameCards";
    }

    // PROFILE
    inline std::string DefaultProfileName(){
        return "Default Profile Name";
    }

    // DECK
    inline int DefaultDeckSize(){
        return 30;
    }
    inline std::string DefaultDeckName(){
        return "Default Deck Name";
    }

    // ATTACK
    inline int DefaultAttackCost(){
        return 10;
    }
    inline EnergyType DefaultAttackType(){
        return EnergyType_Undefined;
    }
    inline std::string DefaultAttackName(){
        return "Default Attack Name";
    }
    inline std::string DefaultAttackDescription(){
        return "Default Attack Description";
    }

    // CARD
    inline int DefaultCardId(){
        return -1;
    }
    inline std::string DefaultCardName(){
        return "Default Card Name";
    }
    inline std::string DefaultCardDescription(){
        return "Default Card Description";
    }
    inline CardType DefaultCardType(){
        return CardType_Undefined;
    }

    // CREATURE
    inline int DefaultCreatureLife(){
        return 100;
    }

    // ENERGY
    inline int DefaultEnergy(){
        return 5;
    }
    inline EnergyType DefaultEnergyType(){
        return EnergyType_Undefined;
    }

    // POWER
    inline int DefaultPowerStats(){
        return -1;
    }
    inline PowerType DefaultPowerType(){
        return PowerType_Undefined;
    }
};

#endif