#ifndef DEF_OPENINGGAME
#define DEF_OPENINGGAME

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../graphics/include/GCreatureCard.h"

#include "../../utils/GameUtils.h"
#include "../../utils/GraphicUtils.h"

static void startOpening() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "ECEMON", sf::Style::Fullscreen);

    GCreatureCard cartman(&window,
        sf::Vector2f(
            Constants::DefaultCardWidth(),
            Constants::DefaultCardHeight()
        )
    );
    cartman.setPosition(
        window.getSize().x/2 - Constants::DefaultCardWidth()/2,
        window.getSize().y/2
    );
    cartman.setCard(GameUtils::Cards.at(1));
    cartman.setCardImage("../graphics/images/"+GraphicUtils::CardImages.at(1));
    cartman.setHideText(true);

    GCreatureCard kyle(&window,
        sf::Vector2f(
            Constants::DefaultCardWidth(),
            Constants::DefaultCardHeight()
        )
    );
    kyle.setPosition(
        window.getSize().x/2 + Constants::DefaultCardWidth()/2,
        window.getSize().y/2
    );
    kyle.setCard(GameUtils::Cards.at(2));
    kyle.setCardImage("../graphics/images/"+GraphicUtils::CardImages.at(2));
    kyle.setHideText(true);


    sf::Font font;
    assert(font.loadFromFile("../graphics/fonts/"+Constants::DefaultFont()));

    sf::Text ecemon("ECEMON", font, 250);
    ecemon.setColor(sf::Color::White);
    sf::FloatRect rect = ecemon.getLocalBounds();
    ecemon.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
    ecemon.setPosition(window.getSize().x/2, window.getSize().y/2);

    sf::Text enterToContinue("Press enter to continue", font, 40);
    enterToContinue.setColor(sf::Color::White);
    sf::FloatRect etcDim = enterToContinue.getLocalBounds();
    enterToContinue.setOrigin(etcDim.left + etcDim.width/2.0f, etcDim.top  + etcDim.height/2.0f);
    enterToContinue.setPosition(window.getSize().x/2, window.getSize().y-etcDim.height-50);

    sf::RectangleShape leftShape(sf::Vector2f(window.getSize().x/2, rect.height));
    leftShape.setFillColor(sf::Color::Black);
    leftShape.setOrigin(window.getSize().x/2, rect.height/2);
    leftShape.setPosition(window.getSize().x/2, window.getSize().y/2);

    sf::RectangleShape rightShape(sf::Vector2f(window.getSize().x/2, rect.height));
    rightShape.setFillColor(sf::Color::Black);
    rightShape.setOrigin(0, rect.height/2);
    rightShape.setPosition(window.getSize().x/2, window.getSize().y/2);

    float start = Constants::DefaultCardWidth()/2.0f;
    float end = window.getSize().x-Constants::DefaultCardWidth()/2.0f;
    bool animationFinished = false;
    int deltaTimeMilli = 600;
    int timeBeforeAnimation = 1000;
    sf::Clock timer;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Return){
                    window.close();
                }
            }
        }

        if(timer.getElapsedTime().asMilliseconds() > timeBeforeAnimation){
            if(cartman.getPosition().x>=start){
                cartman.moveToward(start, window.getSize().y/2);
            }
            if(kyle.getPosition().x<=end){
                kyle.moveToward(end, window.getSize().y/2);
            }
            else{
                animationFinished = true;
            }
        }

        leftShape.setPosition(cartman.getPosition().x+cartman.getSize().x/2, window.getSize().y/2);
        rightShape.setPosition(kyle.getPosition().x-kyle.getSize().x/2, window.getSize().y/2);

        window.clear();
        window.draw(ecemon);
        window.draw(leftShape);
        window.draw(rightShape);
        cartman.draw();
        kyle.draw();
        if(animationFinished){
            if(timer.getElapsedTime().asMilliseconds()>2*deltaTimeMilli){
                timer.restart();
            }
            else if(timer.getElapsedTime().asMilliseconds()>deltaTimeMilli){
                window.draw(enterToContinue);
            }
        }
        window.display();
    }
}

#endif
