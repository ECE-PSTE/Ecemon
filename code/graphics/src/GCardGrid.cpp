#include "../include/GCardGrid.h"

GCardGrid::GCardGrid(sf::Vector2u gridSize){
    m_gridSize = gridSize;
}

void GCardGrid::addGCard(GCard* gcard){
    m_gcards.push_back(gcard);
}

void GCardGrid::addGCards(std::vector<GCard*> gcards){
    m_gcards.insert(m_gcards.end(), gcards.begin(), gcards.end());
}

void GCardGrid::update(){
    int cardWidth = Constants::DefaultCardWidth();
    int cardHeight = Constants::DefaultCardHeight();
    int space = 10;
    int nbCardPerLine = m_gridSize.x/(cardWidth+space);

    int x=0,y=0;
    for(int i=0 ; i<m_gcards.size() ; i++){
        m_gcards[i]->setPosition(sf::Vector2f(cardWidth/2+x*cardWidth, cardHeight/2+y*cardHeight));
        x++;
        if(i+1==nbCardPerLine){
            y++;
            x=0;
        }
    }
}

void GCardGrid::draw(){
    for(auto gcard : m_gcards){
        gcard->draw();
    }
}
