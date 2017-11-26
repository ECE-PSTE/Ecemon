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
        GCreatureCard(const Card *card, sf::RenderWindow *window);

        void draw();
        virtual void setCharacterSize(unsigned int size);
};

#endif
