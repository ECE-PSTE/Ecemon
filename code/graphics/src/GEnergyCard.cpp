#include "../include/GEnergyCard.h"

GEnergyCard::GEnergyCard(){
}

GEnergyCard::GEnergyCard(sf::RenderWindow *window, sf::Vector2f size) : GCard(window, size){
    m_cardShape.setFillColor(Constants::DefaultEnergyCardColor());
    m_cardShape.setOutlineColor(Constants::DefaultEnergyCardOutlineColor());
    m_cardShape.setOutlineThickness(Constants::DefaultCardOutlineThickness());

    m_fontColor = Constants::DefaultEnergyCardTextColor();

    m_nameText.setColor(m_fontColor);
    m_descriptionText.setColor(m_fontColor);

    m_energyText.setFont(m_font);
    m_energyText.setCharacterSize(m_fontSize);
    m_energyText.setColor(m_fontColor);

    GCard::setFontColor(m_fontColor);
}

void GEnergyCard::setCard(const Card* card){
    GCard::setCard(card);
    m_energyText.setString(Utils::toString(((const EnergyCard*)card)->getEnergy()));
    sf::FloatRect energyRect = m_energyText.getLocalBounds();
    m_energyText.setOrigin(energyRect.left + energyRect.width/2.0f, energyRect.top  + energyRect.height/2.0f);
}

void GEnergyCard::setFontSize(unsigned int size){
    GCard::setFontSize(size);
    m_energyText.setCharacterSize(size);
    sf::FloatRect energyRect = m_energyText.getLocalBounds();
    m_energyText.setOrigin(energyRect.left + energyRect.width/2.0f, energyRect.top  + energyRect.height/2.0f);
}

void GEnergyCard::setFontColor(sf::Color fontColor){
    GCard::setFontColor(fontColor);
    m_energyText.setColor(fontColor);
}

void GEnergyCard::update(){
    m_energyText.setPosition(m_position.x, m_position.y-m_size.y/2 + 0.2*m_size.y);
}

void GEnergyCard::draw(){
    GCard::draw();
    GEnergyCard::update();
    if(!m_hideText){
        m_window->draw(m_energyText);
    }
}
