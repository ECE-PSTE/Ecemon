#include <iostream>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../entities/include/CreatureCard.h"
#include "../entities/include/EnergyCard.h"
#include "../entities/include/PowerCard.h"
#include "../entities/include/Attack.h"
#include "../entities/include/Profile.h"
#include "../entities/include/Constants.h"
#include "../entities/include/EnergyStack.h"
#include "../entities/include/EnergyType.h"

#include "../graphics/include/GCreatureCard.h"
#include "../graphics/include/GEnergyCard.h"
#include "../graphics/include/GPowerCard.h"
#include "../graphics/include/GEnergy.h"
#include "../graphics/include/GBoard.h"
#include "../graphics/include/GDialog.h"

#include "../models/include/Combat.h"

#include "../utils/GameUtils.h"
#include "../utils/ProfileUtils.h"

using namespace std;

enum GameState {
    GameState_PICK_CARD,
    GameState_DIALOG_CARD,
    GameState_PLAY_CARD,
    GameState_DONT_PLAY_CARD,
    GameState_DIALOG_ATTACK,
    GameState_DO_ATTACK,
    GameState_DONT_ATTACK,
    GameState_END_TURN
};

enum AttackState {
    AttackState_BASIC,
    AttackState_SPECIAL,
    AttackState_BOTH
};

void gameLoop(Profile* profile1, std::string deck1, Profile* profile2, std::string deck2){
    Combat combat;
    combat.startCombat(profile1, deck1, profile2, deck2);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "FUCKING ECEMON !!!");

    GBoard gboardP1(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP1.setPosition(sf::Vector2f(window.getSize().x/4, window.getSize().y/2));
    gboardP1.setBoard(combat.getpBoardP1());

    GBoard gboardP2(&window, sf::Vector2f(window.getSize().x/2, window.getSize().y));
    gboardP2.setPosition(sf::Vector2f(3*window.getSize().x/4, window.getSize().y/2));
    gboardP2.setBoard(combat.getpBoardP2());

    GDialog dialogPlayCard(&window, sf::Vector2f(400, 90));
    dialogPlayCard.setPosition(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    dialogPlayCard.setPositiveButton("Play the card !");
    dialogPlayCard.setNegativeButton("Don't play");

    GDialog dialogAttack(&window, sf::Vector2f(400, 90));
    dialogAttack.setPosition(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));

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

        playerBoard = playerTurn==1?combat.getpBoardP1():combat.getpBoardP2();

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

            case GameState_END_TURN:
                playerTurn = playerTurn==1?2:1;
                gameState = GameState_PICK_CARD;
        }

        window.clear();
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

int main(int argc, char const *argv[]) {
    std::vector<Profile> profiles;
    if(ProfileUtils::loadProfiles(profiles)){
        std::string deckName1 = profiles[0].getpDecks()->at(0)->getName();
        std::string deckName2 = profiles[1].getpDecks()->at(0)->getName();

        gameLoop(&profiles[0], deckName1, &profiles[1], deckName2);
    }

    GameUtils::freeCards();

    return 0;
}
