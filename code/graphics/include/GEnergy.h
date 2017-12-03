#ifndef DEF_GENERGY
#define DEF_GENERGY

#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "../../entities/include/EnergyStack.h"
#include "../../entities/include/Constants.h"
#include "../../utils/Utils.h"
#include "Drawable.h"

class GEnergy : public Drawable{
    private:
        std::vector<sf::Texture> m_textures;
        std::vector<sf::Sprite> m_sprites;
        std::vector<sf::Text> m_texts;
        sf::Font m_font;
        int m_fontSize;
        float m_imageScale;

        EnergyStack m_energyStack;

        void update();
        void loadEnergy(sf::Texture &texture, sf::Sprite &sprite, std::string imagePath);

    public:
        GEnergy();
        GEnergy(sf::RenderWindow* window, sf::Vector2f size);

        void setEnergyStack(EnergyStack energyStack);
        void setFontSize(int fontSize);

        void draw();
};
#endif
