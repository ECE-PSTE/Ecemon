#include "../include/Board.h"

Board::Board(){
    //A voir ...
}

Board::~Board(){
    //hello my dear
}

void Board::endTurn(){
    if(getCreatureOnBoard()->getLife() - getEffectsOnPlayer().getDamage() <= 0){
        if(getCreatureOnBoard()->getLife() - getEffectsOnPlayer().getDamage() < 0){
            setLifePoint(getLifePoint() + (getCreatureOnBoard()->getLife() - getEffectsOnPlayer().getDamage()));
        }
        getCreatureGraveyard().addCard(getCreatureOnBoard());
        setCreatureOnBoard(NULL);
        getEffectsOnPlayer().newCreature();
    }
    getEffectsOnPlayer().endTurn();
}

bool Board::playerAlive(){
    if(getLifePoint() > 0 && stillAliveCreatureDeck())
    {
        return true;
    }

    return false;
}

void Board::startGame(){

    setCardBet(askCard());
    if(!getDeckPlay().takeoffCard(getCardBet())){
        std::cout << "ERROR : TAKE OFF CARD BET BY PLAYER \n";
    }

    setCreatureOnBoard(getpDeckPlay()->creatureRandom());
    if(!getpDeckPlay()->takeoffCard(getCreatureOnBoard())){
        std::cout<< "ERROR : CREATURE ON BOARD NO TAKE OF DECK PLAY" << std::endl;
    }
}

bool Board::stillAliveCreatureDeck(){
    for(auto & elem : getDeckPlay().getCards()){
        if(elem->type() == CardType_Creature){
            return true;
        }
    }

    return false;
}

Card* Board::askCard(){

    int i = rand()%(getDeckPlay().getCards().size());

    return ((getDeckPlay().getCards())[i]);
}

void Board::playCreature(CreatureCard* cardPlay){
    getpCreatureGraveyard()->addCard(getCreatureOnBoard());
    setCreatureOnBoard(cardPlay);
    getEffectsOnPlayer().newCreature();
}

void Board::playEnergy(EnergyCard* cardPlay){
    getQuantityEnergy().addEnergy(cardPlay->getEnergyType(), cardPlay->getEnergy());
    getpPowerEnergyGraveyard()->addCard(cardPlay);
}

void Board::playPower(PowerCard* cardPlay){
    switch (cardPlay->getPowerType()) {
        case PowerType_Cold:
            getpEnemyBoard()->getEffectsOnPlayer().setFreez(true);
            break;
        case PowerType_OmgKenny:
            getpEnemyBoard()->setLifePoint(getLifePoint() - cardPlay->getStats());
            break;
        case PowerType_Jesus:
            getpDeckPlay()->addCard(getCreatureGraveyard().getCards()[getCreatureGraveyard().getCards().size() - 1]);
            getpCreatureGraveyard()->getCards().pop_back();
            break;
        case PowerType_President:
            getEffectsOnPlayer().setDamage(0);
            break;

        default:
            std::cout<<"ERROR : POWER CARD PLAY NO RECONIZE \n";
    }
}

void Board::endGame(){
    for(const auto & elem : getCreatureGraveyard().getCards()){
        getpDeckPlay()->addCard(elem);
    }

    for(const auto & elem : getpPowerEnergyGraveyard()->getCards()){
        getpDeckPlay()->addCard(elem);
    }
}
