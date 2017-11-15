#ifndef DEF_BOARD
#define DEF_BOARD

#include <iostream>

#include "..\..\include\Card.h"
#include "..\..\include\Deck.h"
#include "..\..\include\CreatureCard.h"
#include "..\..\include\EnergyCard.h"
#include "..\..\include\PowerCard.h"

#include "EnergyStack.h"
#include "EffectStack.h"

#include <list>

class Board{
    private:
        Card* m_cardBet;
        Deck m_deckPlay;
        std::list<Card*> m_creatureGraveyard;
        std::list<Card*> m_powerEnergyGraveyard;
        Card* m_creatureOnBoard;
        EffectStack m_effectsOnPlayer;
        EnergyStack m_quantityEnergy;
        Board* m_pEnemyBoard;
        int m_lifePoint;

        void mixDeck();

        void playCreature(CreatureCard* cardPlay);

        void playEnergy(EnergyCard* cardPlay);

        void playPower();

        bool stillAliveCreatureDeck();

public:
    Board();
    ~Board();

    Card* getCardBet(){return m_cardBet;}

    Deck* getpDeckPlay(){return &m_deckPlay;}
    Deck getpDeckPlay(){return m_deckPlay;}

    std::list<Card*>* getpCreatureGraveyard(){return &m_creatureGraveyard;}
    std::list<Card*> getCreatureGraveyard(){return m_creatureGraveyard};

    std::list<Card*>* getpPowerEnergyGraveyard(){return &m_powerEnergyGraveyard;}
    std::list<Card*> getPowerEnergyGraveyard(){return m_powerEnergyGraveyard};

    Card* getCreatureOnBoard(){return m_creatureOnBoard;}

    EffectStack getEffectsOnPlayer(){return m_effectsOnPlayer;}

    EnergyStack getQuantityEnergy(){return m_quantityEnergy;}

    Board* getpEnemyBoard(){return m_pEnemyBoard;}

    int getLifePoint(){return m_lifePoint;}

    void setCardBet(Card* val){m_cardBet = val;}
    void setDeckPlay(Deck val){m_deckPlay = val;}

    void endTurn();

    //True if lifepoint > 0 or still creature in deck
    bool playerAlive();

    //To discut : because it call every other methode to play a turn by player
    void playTurn();

    //Initialisation of every parameter for a game (ex : lifepoibt of player at start)
    void startGame();
};
#endif
