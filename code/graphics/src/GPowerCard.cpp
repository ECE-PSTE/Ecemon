#include "../include/GPowerCard.h"

GPowerCard::GPowerCard(){
}

GPowerCard::GPowerCard(sf::RenderWindow *window, sf::Vector2f size){
    GCard::init(window, size);

    m_cardShape.setFillColor(Constants::DefaultPowerCardColor());
    m_cardShape.setOutlineColor(Constants::DefaultPowerCardOutlineColor());
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_nameText.setColor(sf::Color(0, 255, 0));
    m_descriptionText.setColor(sf::Color(0, 255, 0));
}
