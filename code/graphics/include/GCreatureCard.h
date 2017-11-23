#ifndef DEF_GCREATURECARD
#define DEF_GCREATURECARD

#include "GCard.h"
#include "../../entities/include/CreatureCard.h"

class GCreatureCard : public GCard {
    private:
        std::string m_imagePath;

    public:
        GCreatureCard();
        GCreatureCard(const Card *card, sf::RenderWindow *window);
        void update();
        void draw();
};

#endif
