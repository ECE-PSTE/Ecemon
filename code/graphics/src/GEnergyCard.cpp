#include "../include/GEnergyCard.h"

GEnergyCard::GEnergyCard(){
}

GEnergyCard::GEnergyCard(const Card* card, sf::RenderWindow* window){
    GCard::init(card, window);

    m_cardShape.setFillColor(sf::Color(150, 50, 250));
    m_cardShape.setOutlineColor(sf::Color(250, 10, 20));
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_nameText.setColor(sf::Color(250, 128, 114));
    m_descriptionText.setColor(sf::Color(250, 128, 114));

    m_energyText.setFont(m_font);
    m_energyText.setCharacterSize(Constants::DefaultCharacterSize());
    m_energyText.setColor(sf::Color(255, 218, 185));
    m_energyText.setString(std::to_string(((const EnergyCard*)card)->getEnergy()));
    sf::FloatRect energyRect = m_energyText.getLocalBounds();
    m_energyText.setOrigin(energyRect.left + energyRect.width/2.0f, energyRect.top  + energyRect.height/2.0f);
}

void GEnergyCard::update(){
    m_energyText.setPosition(m_position.x, m_position.y-m_size.y/2 + 80);
}

void GEnergyCard::draw(){
    GCard::draw();
    GEnergyCard::update();
    m_window->draw(m_energyText);
}
