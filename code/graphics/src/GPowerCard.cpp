#include "../include/GPowerCard.h"

GPowerCard::GPowerCard(){
}

GPowerCard::GPowerCard(const Card* card, sf::RenderWindow* window){
    GCard::init(card, window);
}

void GPowerCard::update(){

}

void GPowerCard::draw(){
    GCard::draw();
    GPowerCard::update();
}
