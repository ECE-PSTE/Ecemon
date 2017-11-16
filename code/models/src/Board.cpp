#include "../include/Board.h"

Board::Board(){
    //A voir ...
}

Board::~Board(){
    //A voir ...
}

void Board::endTurn(){
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
    setCreatureOnBoard(getpDeckPlay()->creatureRandom());
    if(!getpDeckPlay()->takeoffCard(getCreatureOnBoard())){
        std::cout<< "ERROR : CREATURE ON BOARD NO TAKE OF DECK PLAY" << std::endl;
    }
}

bool stillAliveCreatureDeck(){
    for(const auto & elem : getpDeckPlay()->getCards()){
        if(elem.type() = CardType_Creature){
            return true;
        }
    }

    return false;
}
