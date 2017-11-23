#ifndef DEF_GCREATURECARD
#define DEF_GCREATURECARD

#include "GCard.h"
#include "../../entities/include/CreatureCard.h"

class GCreatureCard : public GCard {
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Text m_lifeText;
        std::string m_imagePath;

    public:
        GCreatureCard();
        GCreatureCard(const Card *card, sf::RenderWindow *window);

        void setImage(std::string imagePath, float scaleX, float scaleY);

        void update();
        void draw();
};

#endif
