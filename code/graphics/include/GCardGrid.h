#ifndef DEF_GCARDGRID
#define DEF_GCARDGRID

#include <vector>
#include "GCard.h"

class GCardGrid {
    private:
        sf::Vector2u m_gridSize;
        std::vector<GCard*> m_gcards;

    public:
        GCardGrid(sf::Vector2u m_gridSize);

        void addGCard(GCard* gcard);
        void addGCards(std::vector<GCard*> gcards);

        void update();
        void draw();
};

#endif
