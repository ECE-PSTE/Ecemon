#include "../include/GCreatureCard.h"

GCreatureCard::GCreatureCard(){
}

GCreatureCard::GCreatureCard(sf::RenderWindow *window, sf::Vector2f size){
    GCard::init(window, size);

    m_cardShape.setFillColor(Constants::DefaultCreatureCardColor());
    m_cardShape.setOutlineColor(Constants::DefaultCreatureCardOutlineColor());
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_fontColor = Constants::DefaultCreatureCardTextColor();

    m_lifeText.setFont(m_font);
    m_lifeText.setCharacterSize(m_fontSize);
    m_lifeText.setColor(m_fontColor);

    GCard::setFontColor(m_fontColor);
}

void GCreatureCard::setLife(int life){
    m_lifeText.setString(std::to_string(life));
    sf::FloatRect lifeRect = m_lifeText.getLocalBounds();
    m_lifeText.setOrigin(lifeRect.left + lifeRect.width/2.0f, lifeRect.top  + lifeRect.height/2.0f);
}

void GCreatureCard::setCard(const Card* card){
    GCard::setCard(card);
    GCreatureCard::setLife(((const CreatureCard*)card)->getLife());
}

void GCreatureCard::setFontSize(unsigned int size){
    GCard::setFontSize(size);
    m_lifeText.setCharacterSize(size);
    sf::FloatRect lifeRect = m_lifeText.getLocalBounds();
    m_lifeText.setOrigin(lifeRect.left + lifeRect.width/2.0f, lifeRect.top  + lifeRect.height/2.0f);
}

void GCreatureCard::setFontColor(sf::Color fontColor){
    GCard::setFontColor(fontColor);
    m_lifeText.setColor(fontColor);
}

void GCreatureCard::update(){
    m_lifeText.setPosition(m_position.x, m_position.y-m_size.y/2 + 0.2*m_size.y);
}

void GCreatureCard::draw(){
    GCard::draw();
    GCreatureCard::update();
    m_window->draw(m_lifeText);
}
