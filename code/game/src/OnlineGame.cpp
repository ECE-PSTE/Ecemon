#ifndef DEF_ONLINEGAMELOOP
#define DEF_ONLINEGAMELOOP

#include <sstream>
#include "LocalGame.cpp"
#include "../../Socket/lib/SocketClient.h"

struct Data {
    GameState gameState = GameState_PickCard;
    AttackState attackState;
    Board *playerBoard = NULL;
    bool playerFound = false;
    bool gotUid = false;
    int firstToPlay = -1;
    const Card* cardOnBoard = NULL;
    Profile onlinePlayerProfile;
    std::string onlinePlayerDeck;
    std::string onlinePlayerUid;
};

static Data DATA;

inline void onUid(SocketClient *socket, std::vector<std::string> messages){
    std::cout << "[uid] : " << messages[0] << std::endl;
    socket->setTag(new std::string(messages[0]));
    DATA.gotUid = true;
}

inline void onPlayerFound(SocketClient *socket, std::vector<std::string> messages){
    std::cout << "player connected: " << messages[0] << std::endl;
    DATA.onlinePlayerUid = messages[0];
    std::stringstream ss2(messages[1]);
    ss2 >> DATA.onlinePlayerProfile;
    DATA.onlinePlayerDeck = messages[2];
    DATA.playerFound = true;
}

inline void onFirstPlayer(SocketClient *socket, std::vector<std::string> messages){
    DATA.firstToPlay = Utils::toInt(messages[0]);
}

inline void onCardPicked(SocketClient *socket, std::vector<std::string> messages){
    int id = Utils::toInt(messages[0]);
    DATA.cardOnBoard = DATA.playerBoard->getDeckPlay()->getCardById(id);
    std::cout << "player picked : " << DATA.cardOnBoard->getName() << std::endl;
    DATA.gameState = GameState_DialogCard;
}

inline void onCardPlayed(SocketClient *socket, std::vector<std::string> messages){
    int resp = Utils::toInt(messages[0]);
    if(resp==1){
        DATA.gameState = GameState_PlayCard;
    }
    else if(resp==-1){
        DATA.gameState = GameState_DontPlayCard;
    }
}

inline void onAttack(SocketClient *socket, std::vector<std::string> messages){
    int resp = Utils::toInt(messages[0]);
    if(resp==1){
        DATA.gameState = GameState_DoAttack;
        if(DATA.attackState==AttackState_Both){
            DATA.attackState = AttackState_Special;
        }
    }
    else if(resp==-1){
        if(DATA.attackState==AttackState_Basic || DATA.attackState==AttackState_Special){
            DATA.gameState = GameState_DontAttack;
        }
        else{
            DATA.gameState = GameState_DoAttack;
            DATA.attackState = AttackState_Basic;
        }
    }
}

inline void startOnlineGameLoop(Profile* profile, std::string deck){
    SocketClient *socket = new SocketClient("127.0.0.1", 8888);
    socket->addListener("uid", onUid);
    socket->addListener("player", onPlayerFound);
    socket->addListener("first", onFirstPlayer);
    socket->addListener("pick", onCardPicked);
    socket->addListener("playCardDialog", onCardPlayed);
    socket->addListener("attackDialog", onAttack);
    if(socket->connect()){
        std::cout << "Connected to server !" << std::endl;
    }
    else{
        std::cout << "Could not connect to server" << std::endl;
        return;
    }

    while(!DATA.gotUid);

    std::stringstream ss1;
    ss1 << *profile;
    std::string *uid = (std::string*) socket->getTag();
    socket->send("player", {*uid, ss1.str(), deck});

    std::cout << "Waiting for a player..." << std::endl;

    while(!DATA.playerFound);

    while(DATA.firstToPlay==-1);

    std::cout << "starting graphics..." << std::endl;

    // all set

    Combat combat;
    combat.startCombat(profile, deck, &DATA.onlinePlayerProfile, DATA.onlinePlayerDeck);

    std::cout << "combat ok" << std::endl;

    sf::RenderWindow window(sf::VideoMode(1500, 1080), "ECEMON");

    sf::Music music;
    assert(music.openFromFile("../graphics/sounds/"+Constants::DefaultIntroSound()));
    music.setLoop(true);
    music.play();

    sf::RectangleShape lineSeparator(sf::Vector2f(window.getSize().y, 3));
    lineSeparator.setFillColor(sf::Color::White);
    lineSeparator.setPosition(window.getSize().x/2, 0);
    lineSeparator.rotate(90);

    std::cout << "init gboards..." << std::endl;

    sf::Vector2f winSize(window.getSize().x/2, window.getSize().y);

    std::cout << "init gboards...0" << std::endl;
    GBoard gboardP1(&window, winSize);
    std::cout << "init gboards...0.5" << std::endl;
    gboardP1.setPosition(window.getSize().x/4, window.getSize().y/2);
    std::cout << "init gboards...1" << std::endl;
    gboardP1.setBoard(combat.getpBoardP1());

    GBoard gboardP2(&window, winSize);
    gboardP2.setPosition(3*window.getSize().x/4, window.getSize().y/2);
    std::cout << "init gboards...2" << std::endl;
    gboardP2.setBoard(combat.getpBoardP2());

    std::cout << "init gboards...OK" << std::endl;

    GDialog dialogPlayCard(&window, sf::Vector2f(400, 90));
    dialogPlayCard.setPositiveButton("Play the card !");
    dialogPlayCard.setNegativeButton("Don't play");

    GDialog dialogAttack(&window, sf::Vector2f(400, 90));

    int playerTurn = DATA.firstToPlay;

    std::cout << "entering game loop... :O" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if(mousePos.x<=window.getSize().x/2){
                        if(DATA.gameState==GameState_DialogCard){
                            int resp = dialogPlayCard.getState(mousePos);
                            socket->send("playCardDialog", {Utils::toString(resp)});
                            std::cout << "play dialog : " << resp << std::endl;

                            if(resp==1){
                                DATA.gameState = GameState_PlayCard;
                            }
                            else if(resp==-1){
                                DATA.gameState = GameState_DontPlayCard;
                            }
                        }
                        else if(DATA.gameState==GameState_DialogAttack){
                            int resp = dialogAttack.getState(mousePos);
                            socket->send("attackDialog", {Utils::toString(resp)});
                            std::cout << "attack dialog : " << resp << std::endl;

                            if(resp==1){
                                DATA.gameState = GameState_DoAttack;
                                if(DATA.attackState==AttackState_Both){
                                    DATA.attackState = AttackState_Special;
                                }
                            }
                            else if(resp==-1){
                                if(DATA.attackState==AttackState_Basic || DATA.attackState==AttackState_Special){
                                    DATA.gameState = GameState_DontAttack;
                                }
                                else{
                                    DATA.gameState = GameState_DoAttack;
                                    DATA.attackState = AttackState_Basic;
                                }
                            }
                        }
                    }
                }
            }
            else if (event.type == sf::Event::MouseMoved){
                sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
                if(mousePos.x<=window.getSize().x/2){
                    if(DATA.gameState==GameState_DialogCard){
                        dialogPlayCard.mouseHoverProcess(mousePos);
                    }
                    else if(DATA.gameState==GameState_DialogAttack){
                        dialogAttack.mouseHoverProcess(mousePos);
                    }
                }
            }
        }

        sf::Vector2f pos;
        if(playerTurn==1){
            DATA.playerBoard = combat.getpBoardP1();
            pos = sf::Vector2f(window.getSize().x/4, dialogPlayCard.getSize().y);
        }
        else{
            DATA.playerBoard = combat.getpBoardP2();
            pos = sf::Vector2f(3*window.getSize().x/4, dialogPlayCard.getSize().y);
        }
        dialogPlayCard.setPosition(pos.x, pos.y);
        dialogAttack.setPosition(pos.x, pos.y);

        switch(DATA.gameState){
            case GameState_PickCard:
                if(playerTurn==1){
                    DATA.cardOnBoard = DATA.playerBoard->askCard();
                    socket->send("pick", {Utils::toString(DATA.cardOnBoard->getId())});
                    DATA.gameState = GameState_DialogCard;
                }
            break;

            case GameState_DialogCard:
                dialogPlayCard.setMessage("Do you want to play "+DATA.cardOnBoard->getName());
            break;

            case GameState_PlayCard:
                DATA.playerBoard->playCard(DATA.cardOnBoard);
                DATA.gameState = GameState_DialogAttack;
            break;

            case GameState_DontPlayCard:
                DATA.gameState = GameState_DialogAttack;
            break;

            case GameState_DialogAttack:
                if(DATA.playerBoard->getCreatureOnBoard()!=NULL){
                    bool hasBasic = DATA.playerBoard->askAttack();
                    bool hasSpecial = DATA.playerBoard->askSpecialAttack();
                    if(hasBasic && !hasSpecial){
                        dialogAttack.setMessage("You only have a basic attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        DATA.attackState = AttackState_Basic;
                    }
                    else if(!hasBasic && hasSpecial){
                        dialogAttack.setMessage("You only have a special attack. Attack ?");
                        dialogAttack.setPositiveButton("Yes");
                        dialogAttack.setNegativeButton("No");
                        DATA.attackState = AttackState_Special;
                    }
                    else if(hasBasic && hasSpecial){
                        dialogAttack.setMessage("Use basic or special attack ?");
                        dialogAttack.setPositiveButton("Special");
                        dialogAttack.setNegativeButton("Basic");
                        DATA.attackState = AttackState_Both;
                    }
                } else{
                    DATA.gameState = GameState_EndTurn;
                }
            break;

            case GameState_DoAttack:
                std::cout << "attacking.." << std::endl;
                if(DATA.attackState==AttackState_Basic){
                    DATA.playerBoard->attackEnemie(false);
                }
                else{
                    DATA.playerBoard->attackEnemie(true);
                }
                DATA.gameState = GameState_EndTurn;
                std::cout << "attacking..OK" << std::endl;
            break;

            case GameState_DontAttack:
                DATA.gameState = GameState_EndTurn;
            break;

            case GameState_EndGame:
            break;
        }

        if(DATA.gameState == GameState_EndTurn){
            combat.endTurn();
            DATA.playerBoard->endTurn();
            playerTurn = playerTurn==1?2:1;
            DATA.gameState = GameState_PickCard;

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
        if(DATA.gameState==GameState_DialogCard){
            dialogPlayCard.draw();
        }
        if(DATA.gameState==GameState_DialogAttack){
            dialogAttack.draw();
        }
        window.display();
    }

    music.stop();

    delete uid;
    delete socket;
}

#endif
