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
        GEnergyCard(const Card* card, sf::RenderWindow *window);

        void setEnergyImage(std::string imagePath, float scaleX, float scaleY);

        void draw();
        virtual void setCharacterSize(unsigned int size);
};

#endif
