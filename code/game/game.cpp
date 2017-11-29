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

#include "../utils/GameUtils.h"
#include "../utils/ProfileUtils.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Deck *player1Cards = new Deck("Collection1");
    for(int i=0 ; i<10 ; i++){
        player1Cards->addCard(GameUtils::Cards.at(1));
    }
    player1Cards->addCards({GameUtils::Cards.at(3), GameUtils::Cards.at(5)});


    Deck *player2Cards = new Deck("Collection2");
    for(int i=0 ; i<10 ; i++){
        player2Cards->addCard(GameUtils::Cards.at(2));
    }
    player2Cards->addCards({GameUtils::Cards.at(4), GameUtils::Cards.at(6)});

    Profile profile1("Player 1");
    profile1.getpCards()->addCards(GameUtils::cardsVector());
    profile1.addDeck(player1Cards);
    profile1.setMoney(0);

    Profile profile2("Player 2");
    profile2.getpCards()->addCards(GameUtils::cardsVector());
    profile2.addDeck(player2Cards);
    profile2.setMoney(0);

    std::vector<Profile*> profiles = {&profile1, &profile2};
    ProfileUtils::saveProfiles(profiles);

    GameUtils::freeCards();



    // sf::RenderWindow window(sf::VideoMode(1000, 700), "Ecemon");
    //
    // EnergyStack stack;
    // stack.setChili(3);
    // stack.setTacos(7);
    // stack.setBlueberries(11);
    // stack.setIceCream(4);
    //
    // GEnergy energy(&window, sf::Vector2f(100, 200));
    // energy.setEnergyStack(stack);
    //
    // GCreatureCard creature(&window, sf::Vector2f(250*0.7, 450*0.7));
    // creature.setCard(GameUtils::Cards.at(10));
    // creature.setCardImage("../graphics/images/cartman.png");
    //
    // GEnergyCard bet(&window, sf::Vector2f(100, 180));
    // bet.setCard(GameUtils::Cards.at(54));
    // bet.setCardImage("../graphics/images/jesus.png");
    // bet.setFontSize(20);
    //
    // GBoard board(&window, sf::Vector2f(window.getSize().x, window.getSize().y));
    // board.setGEnergy(energy);
    // board.setGCreatureCard(creature);
    // board.setGCardBet(&bet);
    // board.setPlayerName("OMAR");
    // board.setPlayerLifePoints(25);
    // board.setDeckCardsLeft(17);
    // board.setCemetryCardsCount(3);
    // board.setPosition(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    //
    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if(event.type == sf::Event::Closed){
    //             window.close();
    //         }
    //         // else if(event.type == sf::Event::MouseButtonPressed){
    //         //     if (event.mouseButton.button == sf::Mouse::Left){
    //         //         selectedGCard = getSelectedGCard(gcards, sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
    //         //         if(selectedGCard!=NULL){
    //         //             isGCardSelected = true;
    //         //             positionOffset.x = event.mouseButton.x;
    //         //             positionOffset.y = event.mouseButton.y;
    //         //         }
    //         //     }
    //         // }
    //         // else if(event.type == sf::Event::MouseButtonReleased){
    //         //     if (event.mouseButton.button == sf::Mouse::Left){
    //         //         isGCardSelected = false;
    //         //         selectedGCard = NULL;
    //         //     }
    //         // }
    //         // else if(event.type == sf::Event::MouseMoved){
    //         //     if(isGCardSelected){
    //         //         selectedGCard->setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
    //         //     }
    //         // }
    //     }
    //
    //     window.clear();
    //     board.draw();
    //     window.display();
    // }
    //
    //
    // GameUtils::freeCards();

    return 0;
}
