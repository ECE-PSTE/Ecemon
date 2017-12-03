#ifndef DEF_CONSTANTS
#define DEF_CONSTANTS

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

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
    inline std::string DefaultCardImagesFilename(){
        return "GameCardImages";
    }
    inline std::string DefaultProfilesFilename(){
        return "GameProfiles";
    }

    inline int DefaultLifePointBoard(){
        return 100;
    }

    inline std::string DefaultPasswordAdmin(){
        return "omarlebg";
    }

    // PROFILE
    inline std::string DefaultProfileName(){
        return "Default Profile Name";
    }

    inline int DefaultMoneyProfile(){
        return 500;
    }

    // DECK
    inline int DefaultDeckSize(){
        return 12;
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

    inline int DefaultRandomCardPrice(){
        return 10;
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

    inline int DefaultDamageAttack(){
        return 0;
    }

    // GRAPHICS
    inline std::string DefaultFont(){
        return "Prototype.ttf";
    }

    // GCARDS
    inline int DefaultCardWidth(){
        return 250;
    }
    inline int DefaultCardHeight(){
        return 450;
    }
    inline float DefaultCardOutlineThickness(){
        return -3.0f; // inline
    }
    inline int DefaultCardFontSize(){
        return 24;
    }
    inline sf::Color DefaultCardTextColor(){
        return sf::Color::White;
    }

    // G ENERGY CARD
    inline sf::Color DefaultEnergyCardColor(){
        return sf::Color(150, 50, 250);
    }
    inline sf::Color DefaultEnergyCardOutlineColor(){
        return sf::Color(50, 255, 0);
    }
    inline sf::Color DefaultEnergyCardTextColor(){
        return sf::Color::White;
    }

    // G CREATURE CARD
    inline sf::Color DefaultCreatureCardColor(){
        return sf::Color(0, 0, 100);
    }
    inline sf::Color DefaultCreatureCardOutlineColor(){
        return sf::Color(250, 150, 100);
    }
    inline sf::Color DefaultCreatureCardTextColor(){
        return sf::Color(255, 0, 0);
    }

    // G POWER CARD
    inline sf::Color DefaultPowerCardColor(){
        return sf::Color(150, 50, 250);
    }
    inline sf::Color DefaultPowerCardOutlineColor(){
        return sf::Color(0, 255, 10);
    }

    // G ENERGY
    inline int DefaultEnergyImageSize(){
        return 256; // 256x256
    }
    inline int DefaultEnergyFontSize(){
        return 18;
    }
    inline std::string DefaultEnergyChili(){
        return "chili.png";
    }
    inline std::string DefaultEnergyTaco(){
        return "taco.png";
    }
    inline std::string DefaultEnergyIceCream(){
        return "ice-cream.png";
    }
    inline std::string DefaultEnergyBlueberries(){
        return "blueberries.png";
    }

};

#endif
