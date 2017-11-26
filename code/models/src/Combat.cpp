#include "../include/Combat.h"

Combat::Combat(){
    //merci omar pr le projet :p
}

Combat::~Combat(){
    //c est cool d etre avec quelqu un qui sait coder ^^
}

int Combat::askEndGame(){
    std::cout << "P1 : ";
    if(!m_boardP1.playerAlive()){
        return 2;
    }
    std::cout << "P2 : ";
    if(!m_boardP2.playerAlive()){
        return 1;
    }

    return 0;
}

void Combat::startCombat(Profile* player1, std::string nameDeckP1, Profile* player2, std::string nameDeckP2){

    m_boardP1.setNamePlayer(player1->getName());
    m_boardP2.setNamePlayer(player2->getName());

    for(const auto & elem : player1->getDecks()){
        if(elem->getName() == nameDeckP1){
            m_boardP1.setDeckPlay(elem);
            break;
        }
    }

    for(const auto & elem : player2->getDecks()){
        if(elem->getName() == nameDeckP2){
            m_boardP2.setDeckPlay(elem);
            break;
        }
    }

    m_boardP1.startGame();
    m_boardP2.startGame();

    m_boardP1.setpEnemyBoard(&m_boardP2);
    m_boardP2.setpEnemyBoard(&m_boardP1);

    setPlayerTurn(Utils::getRand(1,2));
}

void Combat::endGame(){
    switch (askEndGame()) {
        case 1:
            m_boardP1.getDeckPlay()->addCard(m_boardP2.getCardBet());
            m_boardP1.getDeckPlay()->addCard(m_boardP1.getCardBet());
            break;
        case 2:
            m_boardP2.getDeckPlay()->addCard(m_boardP1.getCardBet());
            m_boardP2.getDeckPlay()->addCard(m_boardP2.getCardBet());
            break;
        default:
            std::cout<<"ERROR : END OF GAME, ASKENDGAME BAD RETURN OF WINNER\n";
    }

    m_boardP1.endGame();
    m_boardP2.endGame();
}
