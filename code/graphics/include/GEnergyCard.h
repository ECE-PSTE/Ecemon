#ifndef DEF_GENERGYCARD
#define DEF_GENERGYCARD

#include "GCard.h"
#include "../../entities/include/EnergyCard.h"

class GEnergyCard : public GCard {
    private:
        sf::Text m_energyText;

        void update();

    public:
        GEnergyCard();
        GEnergyCard(sf::RenderWindow *window, sf::Vector2f size);

        void setEnergyImage(std::string imagePath, float scaleX, float scaleY);

        void draw();
        void setCard(const Card* card);
        void setFontSize(unsigned int size);
};

#endif
