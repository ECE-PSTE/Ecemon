#include "../include/Drawable.h"

Drawable::Drawable(){
}

Drawable::~Drawable(){
}

sf::Vector2f Drawable::getPosition() const{
    return m_position;
}

sf::Vector2f Drawable::getSize() const{
    return m_size;
}

void Drawable::setPosition(sf::Vector2f position){
    m_position = position;
}

void Drawable::setSize(sf::Vector2f size){
    m_size = size;
}

void Drawable::update(){
}

void Drawable::draw(){
}
