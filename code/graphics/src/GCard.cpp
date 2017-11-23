#include "../include/GCard.h"

GCard::GCard(){
}

GCard::~GCard(){
}

void GCard::init(){
    m_size.x = 250;
    m_size.y = 450;
    m_position.x = 0;
    m_position.y = 0;

    m_cardShape = sf::RectangleShape(m_size);

    assert(m_font.loadFromFile("../graphics/font/Prototype.ttf"));
    m_nameText.setFont(m_font);
    m_nameText.setCharacterSize(24);
    m_nameText.setColor(sf::Color::Red);
    m_descriptionText.setFont(m_font);
    m_descriptionText.setCharacterSize(24);
    m_descriptionText.setColor(sf::Color::Red);
}

sf::RenderWindow* GCard::getWindow() const{
    return m_window;
}

sf::Vector2f GCard::getPosition() const{
    return m_position;
}

sf::Vector2f GCard::getSize() const{
    return m_size;
}

void GCard::setWindow(sf::RenderWindow *window){
    m_window = window;
}

void GCard::setPosition(sf::Vector2f position){
    m_position = position;
}

void GCard::setSize(sf::Vector2f size){
    m_size = size;
}

void GCard::update(){
}

void GCard::draw(){
    update();
    m_window->draw(m_cardShape);
    m_window->draw(m_nameText);
    m_window->draw(m_descriptionText);
}
