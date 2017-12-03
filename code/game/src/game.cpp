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
    GameState_PickCard,
    GameState_DialogCard,
    GameState_PlayCard,
    GameState_DontPlayCard,
    GameState_DialogAttack,
    GameState_DoAttack,
    GameState_DontAttack,
    GameState_EndTurn,
    GameState_EndGame
};

enum AttackState {
    AttackState_Basic,
    AttackState_Special,
    AttackState_Both
};

inline void gameLoop(Profile* profile1, std::string deck1, Profile* profile2, std::string deck2){
    Combat combat;
    combat.startCombat(profile1, deck1, profile2, deck2);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ECEMON", sf::Style::Titlebar);

    sf::RectangleShape lineSeparator(sf::Vector2f(window.getSize().y, 3));
    lineSeparator.setFillColor(sf::Color::White);
    lineSeparator.setPosition(window.getSize().x/2, 0);
    lineSeparator.rotate(90);

    GBoard gboardP1(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP1.setPosition(window.getSize().x/4, window.getSize().y/2);
    gboardP1.setBoard(combat.getpBoardP1());

    GBoard gboardP2(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP2.setPosition(3*window.getSize().x/4, window.getSize().y/2);
    gboardP2.setBoard(combat.getpBoardP2());

    GDialog dialogPlayCard(&window, sf::Vector2f(400, 90));
    dialogPlayCard.setPositiveButton("Play the card !");
    dialogPlayCard.setNegativeButton("Don't play");

    GDialog dialogAttack(&window, sf::Vector2f(400, 90));

    GameState gameState = GameState_PickCard;
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
                    if(gameState==GameState_DialogCard){
                        int resp = dialogPlayCard.getState(mousePos);
                        if(resp==1){
                            gameState = GameState_PlayCard;
                        }
                        else if(resp==-1){
                            gameState = GameState_DontPlayCard;
                        }
                    }
                    else if(gameState==GameState_DialogAttack){
                        int resp = dialogPlayCard.getState(mousePos);
                        if(resp==1){
                            gameState = GameState_DoAttack;
                            if(attackState==AttackState_Both){
                                attackState = AttackState_Special;
                            }
                        }
                        else if(resp==-1){
                            if(attackState==AttackState_Basic || attackState==AttackState_Special){
                                gameState = GameState_DontAttack;
                            }
                            else{
                                gameState = GameState_DoAttack;
                                attackState = AttackState_Basic;
                            }
                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved){
                sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
                if(gameState==GameState_DialogCard){
                    dialogPlayCard.mouseHoverProcess(mousePos);
                }
                else if(gameState==GameState_DialogAttack){
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
        dialogPlayCard.setPosition(pos.x, pos.y);
        dialogAttack.setPosition(pos.x, pos.y);

        switch(gameState){
            case GameState_PickCard:
                card = playerBoard->askCard();
                gameState = GameState_DialogCard;
            break;

            case GameState_DialogCard:
                dialogPlayCard.setMessage("Do you want to play "+card->getName());
            break;

            case GameState_PlayCard:
                playerBoard->playCard(card);
                gameState = GameState_DialogAttack;
            break;

            case GameState_DontPlayCard:
                gameState = GameState_DialogAttack;
            break;

            case GameState_DialogAttack:
                if(playerBoard->getCreatureOnBoard()!=NULL){
                    bool hasBasic = playerBoard->askAttack();
                    bool hasSpecial = playerBoard->askSpecialAttack();
                    if(hasBasic && !hasSpecial){
                        dialogAttack.setMessage("You only have a basic attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        attackState = AttackState_Basic;
                    }
                    else if(!hasBasic && hasSpecial){
                        dialogAttack.setMessage("You only have a special attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        attackState = AttackState_Special;
                    }
                    else if(hasBasic && hasSpecial){
                        dialogAttack.setMessage("Use basic or special attack ?");
                        dialogAttack.setPositiveButton("Special");
                        dialogAttack.setNegativeButton("Basic");
                        attackState = AttackState_Both;
                    }
                } else{
                    gameState = GameState_EndTurn;
                }
            break;

            case GameState_DoAttack:
                if(attackState==AttackState_Basic){
                    playerBoard->attackEnemie(false);
                }
                else{
                    playerBoard->attackEnemie(true);
                }
                gameState = GameState_EndTurn;
            break;

            case GameState_DontAttack:
                gameState = GameState_EndTurn;
            break;

            case GameState_EndGame:
            break;
        }

        if(gameState == GameState_EndTurn){
            combat.endTurn();
            playerBoard->endTurn();
            playerTurn = playerTurn==1?2:1;
            gameState = GameState_PickCard;

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
        if(gameState==GameState_DialogCard){
            dialogPlayCard.draw();
        }
        if(gameState==GameState_DialogAttack){
            dialogAttack.draw();
        }
        window.display();
    }
}

#endif
