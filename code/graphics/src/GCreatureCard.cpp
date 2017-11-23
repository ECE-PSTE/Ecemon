#include "../include/GCreatureCard.h"

GCreatureCard::GCreatureCard(){
}

GCreatureCard::GCreatureCard(const Card *card, sf::RenderWindow *window){
    init();
    m_card = card;
    m_window = window;

    m_cardShape.setFillColor(sf::Color(150, 50, 250));
    m_cardShape.setOutlineThickness(3);
    m_cardShape.setOutlineColor(sf::Color(250, 150, 100));

    m_nameText.setString(card->getName());
    m_descriptionText.setString(card->getDescription());
}

void GCreatureCard::update(){
    float xCorner = m_position.x-m_size.x/2;
    float yCorner = m_position.y-m_size.y/2;
    m_cardShape.setPosition(xCorner, yCorner);
    m_nameText.setPosition(xCorner+10, yCorner+10);
    m_descriptionText.setPosition(xCorner+10, yCorner+60);
}

void GCreatureCard::draw(){
    update();
    GCard::draw();
}
