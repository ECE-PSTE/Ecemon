#ifndef DEF_BOARD
#define DEF_BOARD

#include <iostream>

#include "../../entities/include/Card.h"
#include "../../entities/include/Deck.h"
#include "../../entities/include/CreatureCard.h"
#include "../../entities/include/EnergyCard.h"
#include "../../entities/include/PowerCard.h"

#include "EnergyStack.h"
#include "EffectStack.h"

#include <list>

class Board{
    private:
        Card* m_cardBet;
        Deck m_deckPlay;
        Deck m_creatureGraveyard;
        Deck m_powerEnergyGraveyard;
        Card* m_creatureOnBoard;
        EffectStack m_effectsOnPlayer;
        EnergyStack m_quantityEnergy;
        Board* m_pEnemyBoard;
        int m_lifePoint;

        void playCreature(CreatureCard* cardPlay);

        void playEnergy(EnergyCard* cardPlay);

        void playPower(PowerCard* cardPlay);

        bool stillAliveCreatureDeck();

public:
    Board();
    ~Board();

    Card* getCardBet(){return m_cardBet;}

    Deck* getpDeckPlay(){return &m_deckPlay;}
    Deck getpDeckPlay(){return m_deckPlay;}

    std::list<Card*>* getpCreatureGraveyard(){return &m_creatureGraveyard;}
    std::list<Card*> getCreatureGraveyard(){return m_creatureGraveyard;}

    std::list<Card*>* getpPowerEnergyGraveyard(){return &m_powerEnergyGraveyard;}
    std::list<Card*> getPowerEnergyGraveyard(){return m_powerEnergyGraveyard;}

    Card* getCreatureOnBoard(){return m_creatureOnBoard;}

    EffectStack getEffectsOnPlayer(){return m_effectsOnPlayer;}

    EnergyStack getQuantityEnergy(){return m_quantityEnergy;}

    Board* getpEnemyBoard(){return m_pEnemyBoard;}

    int getLifePoint(){return m_lifePoint;}

    void setCardBet(Card* val){m_cardBet = val;}
    void setDeckPlay(Deck val){m_deckPlay = val;}
    void setCreatureOnBoard(Card* val){m_creatureOnBoard = val;}
    void setpEnemyBoard(Board* val){m_pEnemyBoard = val;}
    void setLifePoint(int val){m_lifePoint = val;}


    void endTurn();

    //True if lifepoint > 0 or still creature in deck
    bool playerAlive();

    //To discut : because it call every other methode to play a turn by player
    void playCard(Card* card);

    //Initialisation of every parameter for a game (ex : lifepoibt of player at start)
    void startGame();

    Card* askCard();
};
#endif
