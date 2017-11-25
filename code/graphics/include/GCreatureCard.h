#ifndef DEF_GCREATURECARD
#define DEF_GCREATURECARD

#include "GCard.h"
#include "../../entities/include/CreatureCard.h"

class GCreatureCard : public GCard {
    private:
        sf::Text m_lifeText;

    public:
        GCreatureCard();
        GCreatureCard(const Card *card, sf::RenderWindow *window);

        void update();
        void draw();
};

#endif
