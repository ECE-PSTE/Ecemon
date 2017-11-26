#include "../include/GCardGrid.h"

GCardGrid::GCardGrid(int maxCardsPerLine){
    m_maxCardsPerLine = maxCardsPerLine;
    m_spaceBetweenCards = 5;
}

sf::Vector2f GCardGrid::getPosition() const{
    return m_position;
}

void GCardGrid::addGCard(GCard* gcard){
    m_gcards.push_back(gcard);
}

void GCardGrid::addGCards(std::vector<GCard*> gcards){
    m_gcards.insert(m_gcards.end(), gcards.begin(), gcards.end());
}

void GCardGrid::setPosition(sf::Vector2f position){
    m_position = position;
}

void GCardGrid::update(){
    if(m_gcards.size()>0){
        int cardWidth = m_gcards[0]->getSize().x;
        int cardHeight = m_gcards[0]->getSize().y;
        int nbOfLines = ceil((float)m_gcards.size()/m_maxCardsPerLine);
        int gridWidth = m_maxCardsPerLine*cardWidth+(m_maxCardsPerLine-1)*m_spaceBetweenCards;
        int gridHeight = nbOfLines*cardHeight+(nbOfLines-1)*m_spaceBetweenCards;

        m_position.x -= gridWidth/2;
        m_position.y -= gridHeight/2;

        int x=0,y=0;
        for(int i=0 ; i<m_gcards.size() ; i++){
            m_gcards[i]->setPosition(
                sf::Vector2f(
                    m_position.x + cardWidth/2 + x*cardWidth + (x+1)*m_spaceBetweenCards,
                    m_position.y + cardHeight/2 + y*cardHeight + (y+1)*m_spaceBetweenCards
                )
            );

            x++;
            if(i+1==m_maxCardsPerLine){
                y++;
                x=0;
            }
        }
    }
}

void GCardGrid::draw(){
    for(auto gcard : m_gcards){
        gcard->draw();
    }
}
