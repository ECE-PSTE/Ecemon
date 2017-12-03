#include "../include/Drawable.h"

Drawable::Drawable(){

}

Drawable::Drawable(sf::RenderWindow* window, sf::Vector2f size){
    m_window = window;
    m_size = size;
}

Drawable::~Drawable(){
}

sf::Vector2f Drawable::getPosition() const{
    return m_position;
}

sf::Vector2f Drawable::getSize() const{
    return m_size;
}

void Drawable::setPosition(int x, int y){
    m_position.x = x;
    m_position.y = y;
}

void Drawable::setSize(int x, int y){
    m_size.x = x;
    m_size.y = y;
}

void Drawable::moveToward(int x, int y){
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
