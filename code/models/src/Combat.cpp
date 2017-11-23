#include "../include/Combat.h"

Combat::Combat(){
    //merci omar pr le projet :p
}

Combat::~Combat(){
    //c est cool d etre avec quelqu un qui sait coder ^^
}

int Combat::askEndGame(){
    if(!getBoardP1().playerAlive()){
        return 2;
    }
    else if(!getBoardP2().playerAlive()){
        return 1;
    }

    return 0;
}

void Combat::startCombat(Profile* player1, std::string nameDeckP1, Profile* player2, std::string nameDeckP2){

    getBoardP1().setNamePlayer(player1->getName());
    getBoardP2().setNamePlayer(player2->getName());

    for(const auto & elem : player1->getDecks()){
        if(elem->getName() == nameDeckP1){
            std::cout << "Yes add to game P1\n";
            m_boardP1.setDeckPlay(elem);
            break;
        }
    }



    for(const auto & elem : player2->getDecks()){
        if(elem->getName() == nameDeckP2){
            std::cout << "Yes add to game P2\n";
            m_boardP2.setDeckPlay(elem);
            break;
        }
    }

    getBoardP1().startGame();
    getBoardP2().startGame();

    setPlayerTurn(Utils::getRand(1,2));
    
}

void Combat::endGame(){
    switch (askEndGame()) {
        case 1:
            getBoardP1().getDeckPlay()->addCard(getBoardP2().getCardBet());
            getBoardP1().getDeckPlay()->addCard(getBoardP1().getCardBet());
            break;
        case 2:
            getBoardP2().getDeckPlay()->addCard(getBoardP1().getCardBet());
            getBoardP2().getDeckPlay()->addCard(getBoardP2().getCardBet());
            break;
        default:
            std::cout<<"ERROR : END OF GAME, ASKENDGAME BAD RETURN OF WINNER\n";
    }

    getBoardP1().endGame();
    getBoardP2().endGame();
}
