#ifndef DEF_BOARD
#define DEF_BOARD

#include <iostream>
#include <cstdlib>
#include <string>

#include "../../entities/include/Card.h"
#include "../../entities/include/Deck.h"
#include "../../entities/include/CreatureCard.h"
#include "../../entities/include/EnergyCard.h"
#include "../../entities/include/PowerCard.h"
#include "../../entities/include/EnergyStack.h"
#include "../../entities/include/EffectStack.h"
#include "../../entities/include/Constants.h"

#include "../../utils/Utils.h"

class Board{
    private:
        std::string m_namePlayer;
        const Card* m_cardBet;
        Deck* m_deckPlay;
        Deck m_creatureGraveyard;
        Deck m_powerEnergyGraveyard;
        const CreatureCard* m_creatureOnBoard;
        EffectStack m_effectsOnPlayer;
        EnergyStack m_quantityEnergy;
        Board* m_pEnemyBoard;
        int m_lifePoint;

        void playCreature(const CreatureCard* cardPlay);

        void playEnergy(const EnergyCard* cardPlay);

        void playPower(const PowerCard* cardPlay);

        bool stillAliveCreatureDeck();

    public:
        Board();
        ~Board();

        std::string getNamePlayer(){return m_namePlayer;}
        const Card* getCardBet(){return m_cardBet;}
        Deck* getDeckPlay(){return m_deckPlay;}
        Deck* getpCreatureGraveyard(){return &m_creatureGraveyard;}
        Deck getCreatureGraveyard(){return m_creatureGraveyard;}
        Deck* getpPowerEnergyGraveyard(){return &m_powerEnergyGraveyard;}
        Deck getPowerEnergyGraveyard(){return m_powerEnergyGraveyard;}
        const CreatureCard* getCreatureOnBoard(){return m_creatureOnBoard;}
        EffectStack* getpEffectsOnPlayer(){return &m_effectsOnPlayer;}
        EnergyStack* getpQuantityEnergy(){return &m_quantityEnergy;}
        Board* getpEnemyBoard(){return m_pEnemyBoard;}
        int getLifePoint(){return m_lifePoint;}

        void setNamePlayer(std::string val){m_namePlayer = val;}
        void setCardBet(const Card* val){m_cardBet = val;}
        void setDeckPlay(Deck* val){m_deckPlay = val;}
        void setCreatureOnBoard(const CreatureCard* val){m_creatureOnBoard = val;}
        void setpEnemyBoard(Board* val){m_pEnemyBoard = val;}
        void setLifePoint(int val){m_lifePoint = val;}

        void endCreatureTurn();

        void playerTakeDamage(int damage);

        void creatureTakeDamage(int damage);

        int getCreatureLifePoint();

        void endTurn();

        //True if lifepoint > 0 or still creature in deck
        bool playerAlive();

        bool askAttack();

        bool askSpecialAttack();

        void attackEnemie(bool specialAttack);

        //To discut : because it call every other methode to play a turn by player
        void playCard(const Card* card);

        //Initialisation of every parameter for a game (ex : lifepoibt of player at start)
        void startGame();

        const Card* askCard();

        void endGame();
};
#endif
