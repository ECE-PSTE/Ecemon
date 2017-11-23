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
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setString(card->getDescription());
    sf::FloatRect descRect = m_descriptionText.getLocalBounds();
    m_descriptionText.setOrigin(descRect.left + descRect.width/2.0f, descRect.top  + descRect.height/2.0f);
}

std::string GCreatureCard::getImagePath() const{
    return m_imagePath;
}

void GCreatureCard::setImagePath(std::string imagePath, float scaleX, float scaleY){
    m_imagePath = imagePath;
    assert(m_texture.loadFromFile(imagePath));
    m_texture.setSmooth(true);
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_texture.getSize().x/2, m_texture.getSize().y/2);
    m_sprite.setScale(scaleX, scaleY);
}

void GCreatureCard::update(){
    m_cardShape.setPosition(m_position.x, m_position.y);
    m_nameText.setPosition(m_position.x, m_position.y-m_size.y/2 + 30);
    m_descriptionText.setPosition(m_position.x, m_position.y+m_size.y/2-30);
    m_sprite.setPosition(m_position.x, m_position.y);
}

void GCreatureCard::draw(){
    update();
    GCard::draw();
    m_window->draw(m_sprite);
}
