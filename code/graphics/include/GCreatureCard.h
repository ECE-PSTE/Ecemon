#ifndef DEF_GCREATURECARD
#define DEF_GCREATURECARD

#include "GCard.h"
#include "../../entities/include/CreatureCard.h"

class GCreatureCard : public GCard {
    private:
        sf::Text m_lifeText;

        void update();

    public:
        GCreatureCard();
        GCreatureCard(sf::RenderWindow *window, sf::Vector2f size);

        void draw();
        void setCard(const Card* card);
        void setFontSize(unsigned int size);
};

#endif
