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
    if(!getDeckPlay()->takeoffCard(getCardBet())){
        std::cout << "ERROR : TAKE OFF CARD BET BY PLAYER \n";
    }


    setCreatureOnBoard(getDeckPlay()->creatureRandom());
    if(!getDeckPlay()->takeoffCard(getCreatureOnBoard())){
        std::cout<< "ERROR : CREATURE ON BOARD NO TAKE OF DECK PLAY" << std::endl;
    }


    setLifePoint(Constants::DefaultLifePointBoard());
}

bool Board::stillAliveCreatureDeck(){
    for(auto & elem : getDeckPlay()->getCards()){
        if(elem->type() == CardType_Creature){
            return true;
        }
    }

    return false;
}

const Card* Board::askCard(){
    //std::cout << *m_deckPlay << "\n";
    //std::cout << m_deckPlay->getName() << "\n";
    return m_deckPlay->getCards()[Utils::getRand(0, getDeckPlay()->getCards().size()-1)];

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
            getDeckPlay()->addCard(getCreatureGraveyard().getCards()[getCreatureGraveyard().getCards().size() - 1]);
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
        getDeckPlay()->addCard(elem);
    }

    for(const auto & elem : getpPowerEnergyGraveyard()->getCards()){
        getDeckPlay()->addCard(elem);
    }
}
