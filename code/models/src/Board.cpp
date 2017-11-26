#include "../include/Board.h"

Board::Board(){
}

Board::~Board(){
    //hello my dear
}

void Board::endTurn(){
    std::cout << "LP creature : " <<getCreatureOnBoard()->getLife() - getpEffectsOnPlayer()->getDamage() << "\n";

    // std::cout << "Damage : " << getEffectsOnPlayer().getDamage() << "\n";


    if(getCreatureOnBoard()->getLife() - getpEffectsOnPlayer()->getDamage() <= 0){
        std::cout << "Dead \n";
        if(getCreatureOnBoard()->getLife() - getpEffectsOnPlayer()->getDamage() < 0){
            setLifePoint(getLifePoint() + (getCreatureOnBoard()->getLife() - getpEffectsOnPlayer()->getDamage()));
        }
        getCreatureGraveyard().addCard(getCreatureOnBoard());
        setCreatureOnBoard(NULL);
        getpEffectsOnPlayer()->newCreature();
    }
    else{
        std::cout << "Not Dead\n";
    }

    getpEffectsOnPlayer()->endTurn();
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
    if(!getDeckPlay()->removeCard(getCardBet())){
        std::cout << "ERROR : TAKE OFF CARD BET BY PLAYER \n";
    }

    setCreatureOnBoard(getDeckPlay()->creatureRandom());
    if(!getDeckPlay()->removeCard(getCreatureOnBoard())){
        std::cout<< "ERROR : CREATURE ON BOARD NO TAKE OF DECK PLAY" << std::endl;
    }

    m_effectsOnPlayer.newCreature();

    // std::cout<< "Player " << m_namePlayer << " ID Card On Board : " << *m_creatureOnBoard << "\n";

    setLifePoint(Constants::DefaultLifePointBoard());
}

bool Board::stillAliveCreatureDeck(){
    if(m_creatureOnBoard != NULL){
        std::cout << "Creature on Board\n";
        return true;
    }

    for(auto & elem : m_deckPlay->getCards()){
        if(elem->type() == CardType_Creature){
            std::cout << "Creature in Deck\n";
            return true;
        }
    }
    std::cout<< "Dead\n";
    return false;
}

const Card* Board::askCard(){
    return m_deckPlay->getCards()[Utils::getRand(0, getDeckPlay()->getCards().size()-1)];

}

void Board::playCard(const Card* card){
    switch (card->type()) {
        case CardType_Power:
            playPower((const PowerCard*) card);
            m_deckPlay->removeCard(card);
            m_powerEnergyGraveyard.addCard(card);
            break;
        case CardType_Energy:
            playEnergy((const EnergyCard*) card);
            m_deckPlay->removeCard(card);
            m_powerEnergyGraveyard.addCard(card);
            break;
        case CardType_Creature:
            playCreature((const CreatureCard*) card);
            m_deckPlay->removeCard(card);
            m_creatureGraveyard.addCard(card);
            break;
        default :
            std::cout << "ERROR TYPE OF CARD PLAY IN PLAYCARD\n";
    }
}

void Board::playCreature(const CreatureCard* cardPlay){
    getpCreatureGraveyard()->addCard(getCreatureOnBoard());
    setCreatureOnBoard(cardPlay);
    getpEffectsOnPlayer()->newCreature();
}

void Board::playEnergy(const EnergyCard* cardPlay){
    getpQuantityEnergy()->addEnergy(cardPlay->getEnergyType(), cardPlay->getEnergy());
    getpPowerEnergyGraveyard()->addCard(cardPlay);
}

void Board::playPower(const PowerCard* cardPlay){
    switch (cardPlay->getPowerType()) {
        case PowerType_Cold:
            getpEnemyBoard()->getpEffectsOnPlayer()->setFreez(true);
            break;
        case PowerType_OmgKenny:
            getpEnemyBoard()->setLifePoint(getLifePoint() - cardPlay->getStats());
            break;
        case PowerType_Jesus:
            getDeckPlay()->addCard(getCreatureGraveyard().getCards()[getCreatureGraveyard().getCards().size() - 1]);
            getpCreatureGraveyard()->getCards().pop_back();
            break;
        case PowerType_President:
            getpEffectsOnPlayer()->setDamage(0);
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
