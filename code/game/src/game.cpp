#ifndef DEF_GAMELOOP
#define DEF_GAMELOOP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../entities/include/CreatureCard.h"
#include "../../entities/include/EnergyCard.h"
#include "../../entities/include/PowerCard.h"
#include "../../entities/include/Attack.h"
#include "../../entities/include/Profile.h"
#include "../../entities/include/Constants.h"
#include "../../entities/include/EnergyStack.h"
#include "../../entities/include/EnergyType.h"

#include "../../graphics/include/GCreatureCard.h"
#include "../../graphics/include/GEnergyCard.h"
#include "../../graphics/include/GPowerCard.h"
#include "../../graphics/include/GEnergy.h"
#include "../../graphics/include/GBoard.h"
#include "../../graphics/include/GDialog.h"

#include "../../models/include/Combat.h"

#include "../../utils/GameUtils.h"
#include "../../utils/ProfileUtils.h"

enum GameState {
    GameState_PICK_CARD,
    GameState_DIALOG_CARD,
    GameState_PLAY_CARD,
    GameState_DONT_PLAY_CARD,
    GameState_DIALOG_ATTACK,
    GameState_DO_ATTACK,
    GameState_DONT_ATTACK,
    GameState_END_TURN,
    GameState_END_GAME
};

enum AttackState {
    AttackState_BASIC,
    AttackState_SPECIAL,
    AttackState_BOTH
};

inline void gameLoop(Profile* profile1, std::string deck1, Profile* profile2, std::string deck2){
    Combat combat;
    combat.startCombat(profile1, deck1, profile2, deck2);

    sf::RenderWindow window(sf::VideoMode(1000, 800), "ECEMON", sf::Style::Titlebar);

    sf::RectangleShape lineSeparator(sf::Vector2f(window.getSize().y, 3));
    lineSeparator.setFillColor(sf::Color::White);
    lineSeparator.setPosition(window.getSize().x/2, 0);
    lineSeparator.rotate(90);

    GBoard gboardP1(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP1.setPosition(sf::Vector2f(window.getSize().x/4, window.getSize().y/2));
    gboardP1.setBoard(combat.getpBoardP1());

    GBoard gboardP2(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP2.setPosition(sf::Vector2f(3*window.getSize().x/4, window.getSize().y/2));
    gboardP2.setBoard(combat.getpBoardP2());

    GDialog dialogPlayCard(&window, sf::Vector2f(400, 90));
    dialogPlayCard.setPositiveButton("Play the card !");
    dialogPlayCard.setNegativeButton("Don't play");

    GDialog dialogAttack(&window, sf::Vector2f(400, 90));

    GameState gameState = GameState_PICK_CARD;
    AttackState attackState;
    Board *playerBoard;
    const Card* card;
    int playerTurn = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if(gameState==GameState_DIALOG_CARD){
                        int resp = dialogPlayCard.getState(mousePos);
                        if(resp==1){
                            gameState = GameState_PLAY_CARD;
                        }
                        else if(resp==-1){
                            gameState = GameState_DONT_PLAY_CARD;
                        }
                    }
                    else if(gameState==GameState_DIALOG_ATTACK){
                        int resp = dialogPlayCard.getState(mousePos);
                        if(resp==1){
                            gameState = GameState_DO_ATTACK;
                            if(attackState==AttackState_BOTH){
                                attackState = AttackState_SPECIAL;
                            }
                        }
                        else if(resp==-1){
                            if(attackState==AttackState_BASIC || attackState==AttackState_SPECIAL){
                                gameState = GameState_DONT_ATTACK;
                            }
                            else{
                                gameState = GameState_DO_ATTACK;
                                attackState = AttackState_BASIC;
                            }
                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved){
                sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
                if(gameState==GameState_DIALOG_CARD){
                    dialogPlayCard.mouseHoverProcess(mousePos);
                }
                else if(gameState==GameState_DIALOG_ATTACK){
                    dialogAttack.mouseHoverProcess(mousePos);
                }
            }
        }

        sf::Vector2f pos;
        if(playerTurn==1){
            playerBoard = combat.getpBoardP1();
            pos = sf::Vector2f(window.getSize().x/4, dialogPlayCard.getSize().y);
        }
        else{
            playerBoard = combat.getpBoardP2();
            pos = sf::Vector2f(3*window.getSize().x/4, dialogPlayCard.getSize().y);
        }
        dialogPlayCard.setPosition(pos);
        dialogAttack.setPosition(pos);

        switch(gameState){
            case GameState_PICK_CARD:
                card = playerBoard->askCard();
                gameState = GameState_DIALOG_CARD;
            break;

            case GameState_DIALOG_CARD:
                dialogPlayCard.setMessage("Do you want to play "+card->getName());
            break;

            case GameState_PLAY_CARD:
                playerBoard->playCard(card);
                gameState = GameState_DIALOG_ATTACK;
            break;

            case GameState_DONT_PLAY_CARD:
                gameState = GameState_DIALOG_ATTACK;
            break;

            case GameState_DIALOG_ATTACK:
                if(playerBoard->getCreatureOnBoard()!=NULL){
                    bool hasBasic = playerBoard->askAttack();
                    bool hasSpecial = playerBoard->askSpecialAttack();
                    if(hasBasic && !hasSpecial){
                        dialogAttack.setMessage("You only have a basic attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        attackState = AttackState_BASIC;
                    }
                    else if(!hasBasic && hasSpecial){
                        dialogAttack.setMessage("You only have a special attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        attackState = AttackState_SPECIAL;
                    }
                    else if(hasBasic && hasSpecial){
                        dialogAttack.setMessage("Use basic or special attack ?");
                        dialogAttack.setPositiveButton("Special");
                        dialogAttack.setNegativeButton("Basic");
                        attackState = AttackState_BOTH;
                    }
                } else{
                    gameState = GameState_END_TURN;
                }
            break;

            case GameState_DO_ATTACK:
                if(attackState==AttackState_BASIC){
                    playerBoard->attackEnemie(false);
                }
                else{
                    playerBoard->attackEnemie(true);
                }
                gameState = GameState_END_TURN;
            break;

            case GameState_DONT_ATTACK:
                gameState = GameState_END_TURN;
            break;

            case GameState_END_GAME:
            break;
        }

        if(gameState == GameState_END_TURN){
            combat.endTurn();
            playerBoard->endTurn();
            playerTurn = playerTurn==1?2:1;
            gameState = GameState_PICK_CARD;

            int state = combat.askEndGame();
            if(state==1){
                std::cout << "Player 1 win !" << std::endl;
                combat.endGame();
                window.close();
            }
            else if(state==2){
                std::cout << "Player 2 win !" << std::endl;
                combat.endGame();
                window.close();
            }
        }

        window.clear();
        window.draw(lineSeparator);
        gboardP1.draw();
        gboardP2.draw();
        if(gameState==GameState_DIALOG_CARD){
            dialogPlayCard.draw();
        }
        if(gameState==GameState_DIALOG_ATTACK){
            dialogAttack.draw();
        }
        window.display();
    }
}

#endif
