#include "../include/GPowerCard.h"

GPowerCard::GPowerCard(){
}

GPowerCard::GPowerCard(const Card* card, sf::RenderWindow* window){
    GCard::init(card, window);

    m_cardShape.setFillColor(sf::Color(150, 50, 250));
    m_cardShape.setOutlineColor(sf::Color(0, 255, 10));
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_nameText.setColor(sf::Color(0, 255, 0));
    m_descriptionText.setColor(sf::Color(0, 255, 0));
}

void GPowerCard::update(){

}

void GPowerCard::draw(){
    GCard::draw();
    GPowerCard::update();
}
