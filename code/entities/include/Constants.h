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
    static std::string DefaultCardsFilename(){
        return "GameCards";
    }
    static std::string DefaultCardImagesFilename(){
        return "GameCardImages";
    }
    static std::string DefaultProfilesFilename(){
        return "GameProfiles";
    }

    static int DefaultLifePointBoard(){
        return 100;
    }

    static std::string DefaultPasswordAdmin(){
        return "omarlebg";
    }

    // PROFILE
    static std::string DefaultProfileName(){
        return "Default Profile Name";
    }

    inline int DefaultMoneyProfile(){
        return 500;
    }

    // DECK
    static int DefaultDeckSize(){
        return 13;
    }
    static std::string DefaultDeckName(){
        return "Default Deck Name";
    }

    // ATTACK
    static int DefaultAttackCost(){
        return 10;
    }
    static EnergyType DefaultAttackType(){
        return EnergyType_Undefined;
    }
    static std::string DefaultAttackName(){
        return "Default Attack Name";
    }
    static std::string DefaultAttackDescription(){
        return "Default Attack Description";
    }

    // CARD
    static int DefaultCardId(){
        return -1;
    }
    static std::string DefaultCardName(){
        return "Default Card Name";
    }
    static std::string DefaultCardDescription(){
        return "Default Card Description";
    }
    static CardType DefaultCardType(){
        return CardType_Undefined;
    }

    static int DefaultRandomCardPrice(){
        return 10;
    }



    // CREATURE
    static int DefaultCreatureLife(){
        return 100;
    }

    // ENERGY
    static int DefaultEnergy(){
        return 5;
    }
    static EnergyType DefaultEnergyType(){
        return EnergyType_Undefined;
    }

    // POWER
    static int DefaultPowerStats(){
        return -1;
    }
    static PowerType DefaultPowerType(){
        return PowerType_Undefined;
    }

    static int DefaultDamageAttack(){
        return 0;
    }

    // GRAPHICS
    static std::string DefaultFont(){
        return "Prototype.ttf";
    }

    // GCARDS
    static int DefaultCardWidth(){
        return 250;
    }
    static int DefaultCardHeight(){
        return 450;
    }
    static float DefaultCardOutlineThickness(){
        return -3.0f; // static
    }
    static int DefaultCardFontSize(){
        return 24;
    }
    static sf::Color DefaultCardTextColor(){
        return sf::Color::White;
    }

    // G ENERGY CARD
    static sf::Color DefaultEnergyCardColor(){
        return sf::Color(150, 50, 250);
    }
    static sf::Color DefaultEnergyCardOutlineColor(){
        return sf::Color(50, 255, 0);
    }
    static sf::Color DefaultEnergyCardTextColor(){
        return sf::Color::White;
    }

    // G CREATURE CARD
    static sf::Color DefaultCreatureCardColor(){
        return sf::Color(0, 0, 100);
    }
    static sf::Color DefaultCreatureCardOutlineColor(){
        return sf::Color(250, 150, 100);
    }
    static sf::Color DefaultCreatureCardTextColor(){
        return sf::Color(255, 0, 0);
    }

    // G POWER CARD
    static sf::Color DefaultPowerCardColor(){
        return sf::Color(150, 50, 250);
    }
    static sf::Color DefaultPowerCardOutlineColor(){
        return sf::Color(0, 255, 10);
    }

    // G ENERGY
    static int DefaultEnergyImageSize(){
        return 256; // 256x256
    }
    static int DefaultEnergyFontSize(){
        return 18;
    }
    static std::string DefaultEnergyChili(){
        return "chili.png";
    }
    static std::string DefaultEnergyTaco(){
        return "taco.png";
    }
    static std::string DefaultEnergyIceCream(){
        return "ice-cream.png";
    }
    static std::string DefaultEnergyBlueberries(){
        return "blueberries.png";
    }

};

#endif
