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

void Drawable::moveToward(sf::Vector2f position){
    int x = position.x;
    int y = position.y;
    float velocity = 0.2f;

    float length = sqrt(pow(x-m_position.x, 2)+pow(y-m_position.y, 2));
    if(length!=0){
        m_position.x += (x-m_position.x)*velocity/length;
        m_position.y += (y-m_position.y)*velocity/length;
    }
}

void Drawable::update(){
}

void Drawable::draw(){
}
