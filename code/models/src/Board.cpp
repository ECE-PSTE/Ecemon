#include "../include/Board.h"

Board::Board(){
}

Board::~Board(){
    //hello my dear
}


void Board::playerTakeDamage(int damage){
    m_lifePoint -= damage;
}

void Board::endCreatureTurn(){
    if(m_creatureOnBoard != NULL){
        if(getCreatureLifePoint() <= 0){
            if(getCreatureLifePoint() < 0){
                playerTakeDamage(-getCreatureLifePoint());
            }
            getCreatureGraveyard().addCard(getCreatureOnBoard());
            setCreatureOnBoard(NULL);
            getpEffectsOnPlayer()->newCreature();
        }
    }
}

void Board::endTurn(){
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
    int i = Utils::getRand(0, getDeckPlay()->getCards().size()-1);
    return m_deckPlay->getCards()[i];


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
            m_creatureGraveyard.addCard(m_creatureOnBoard);
            playCreature((const CreatureCard*) card);
            m_deckPlay->removeCard(card);
            break;
        default :
            std::cout << "ERROR TYPE OF CARD PLAY IN PLAYCARD\n";
    }
}

void Board::playCreature(const CreatureCard* cardPlay){
    // getpCreatureGraveyard()->addCard(getCreatureOnBoard());
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
            getpEnemyBoard()->playerTakeDamage(cardPlay->getStats());
            break;
        case PowerType_Jesus:
            if(m_creatureGraveyard.getCards().size() != 0){
                getDeckPlay()->addCard(getCreatureGraveyard().getCards()[getCreatureGraveyard().getCards().size() - 1]);
                getpCreatureGraveyard()->getCards().pop_back();
            }
            break;
        case PowerType_President:
            getpEffectsOnPlayer()->setDamage(0);
            break;
        case PowerType_Food:
            getpQuantityEnergy()->addEnergy(EnergyType_Chili, 1);
            getpQuantityEnergy()->addEnergy(EnergyType_Tacos, 1);
            getpQuantityEnergy()->addEnergy(EnergyType_IceCream, 1);
            getpQuantityEnergy()->addEnergy(EnergyType_Blueberries, 1);

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

    if(m_creatureOnBoard != NULL){
        getDeckPlay()->addCard(m_creatureOnBoard);
    }
}

void Board::creatureTakeDamage(int damage){
    m_effectsOnPlayer.takeDamage(damage);
}

bool Board::askAttack(){
    if(m_creatureOnBoard && !m_effectsOnPlayer.getFreez()){
        return true;
    }
    return false;
}

bool Board::askSpecialAttack(){
    if(m_effectsOnPlayer.getFreez()){
        return false;
    }

    if(!m_pEnemyBoard->getCreatureOnBoard()){
        return false;
    }

    switch (m_creatureOnBoard->getAttacks()[1].getAttackType()){
        case EnergyType_Chili:
            if(m_quantityEnergy.getChili() < m_creatureOnBoard->getAttacks()[1].getCost()){
                return false;
            }
            break;
        case EnergyType_Tacos:
            if(m_quantityEnergy.getTacos() < m_creatureOnBoard->getAttacks()[1].getCost()){
                return false;
            }
            break;
        case EnergyType_IceCream:
            if(m_quantityEnergy.getIceCream() < m_creatureOnBoard->getAttacks()[1].getCost()){
                return false;
            }
            break;
        case EnergyType_Blueberries:
            if(m_quantityEnergy.getBlueberries() < m_creatureOnBoard->getAttacks()[1].getCost()){
                return false;
            }
            break;
        default:
            std::cout << "ERROR TYPE ENERGY ATTACK IN ASKSPECIALATTACK\n\n";
    }
    return true;
}

void Board::attackEnemie(bool specialAttack){
    if(specialAttack){
        m_pEnemyBoard->creatureTakeDamage(m_creatureOnBoard->getAttacks()[1].getDamage());
    }
    else if(m_pEnemyBoard->getCreatureOnBoard()){
        m_pEnemyBoard->creatureTakeDamage(m_creatureOnBoard->getAttacks()[0].getDamage());
    }
    else{
        m_pEnemyBoard->playerTakeDamage(m_creatureOnBoard->getAttacks()[0].getDamage());
    }
}

int Board::getCreatureLifePoint(){
    return m_creatureOnBoard->getLife() - m_effectsOnPlayer.getDamage();
}
