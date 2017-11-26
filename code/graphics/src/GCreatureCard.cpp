#include "../include/GCreatureCard.h"

GCreatureCard::GCreatureCard(){
}

GCreatureCard::GCreatureCard(const Card *card, sf::RenderWindow *window){
    GCard::init(card, window);

    m_cardShape.setFillColor(sf::Color(150, 50, 250));
    m_cardShape.setOutlineColor(sf::Color(250, 150, 100));
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_lifeText.setFont(m_font);
    m_lifeText.setCharacterSize(m_characterSize);
    m_lifeText.setColor(sf::Color::Red);
    m_lifeText.setString(std::to_string(((const CreatureCard*)card)->getLife()));
    sf::FloatRect lifeRect = m_lifeText.getLocalBounds();
    m_lifeText.setOrigin(lifeRect.left + lifeRect.width/2.0f, lifeRect.top  + lifeRect.height/2.0f);
}

void GCreatureCard::setCharacterSize(unsigned int size){
    GCard::setCharacterSize(size);
    m_lifeText.setCharacterSize(size);
    sf::FloatRect lifeRect = m_lifeText.getLocalBounds();
    m_lifeText.setOrigin(lifeRect.left + lifeRect.width/2.0f, lifeRect.top  + lifeRect.height/2.0f);
}

void GCreatureCard::update(){
    m_lifeText.setPosition(m_position.x, m_position.y-m_size.y/2 + 0.2*m_size.y);
}

void GCreatureCard::draw(){
    GCard::draw();
    GCreatureCard::update();
    m_window->draw(m_lifeText);
}
