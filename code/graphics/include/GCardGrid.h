#ifndef DEF_GCARDGRID
#define DEF_GCARDGRID

#include <vector>
#include <cmath>
#include "GCard.h"

class GCardGrid {
    private:
        std::vector<GCard*> m_gcards;
        sf::Vector2f m_position;
        int m_maxCardsPerLine;
        int m_spaceBetweenCards;

    public:
        GCardGrid(int maxCardsPerLine);

        sf::Vector2f getPosition() const;

        void addGCard(GCard* gcard);
        void addGCards(std::vector<GCard*> gcards);
        void setPosition(sf::Vector2f position);

        void update();
        void draw();
};

#endif
