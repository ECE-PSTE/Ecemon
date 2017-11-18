#ifndef DEF_COMBAT
#define DEF_COMBAT

#include <iostream>
#include <cstdlib>
#include <string>

#include "Board.h"
#include "../../entities/include/Profile.h"

class Combat {
private:
    Board m_boardP1;
    Board m_boardP2;
    int m_playerTurn;

public:
    Combat();
    ~Combat ();

    Board getBoardP1(){return m_boardP1;}
    Board getBoardP2(){return m_boardP2;}
    int getPlayerTrun(){return m_playerTurn;}

    void setPlayerTurn(int val){m_playerTurn = val;}


    //1 P1 win, 2 P2 win
    int askEndGame();

    void startCombat(Profile* player1, std::string nameDeckP1, Profile* player2, std::string nameDeckP2);

    void endGame();


};

#endif
