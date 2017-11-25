#ifndef DEF_GENERGYCARD
#define DEF_GENERGYCARD

#include "GCard.h"
#include "../../entities/include/EnergyCard.h"

class GEnergyCard : public GCard {
    private:
        sf::Text m_energyText;

    public:
        GEnergyCard();
        GEnergyCard(const Card* card, sf::RenderWindow *window);

        void setEnergyImage(std::string imagePath, float scaleX, float scaleY);

        void update();
        void draw();
};

#endif
