#ifndef DEF_GENERGY
#define DEF_GENERGY

#include <vector>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "../../entities/include/EnergyStack.h"
#include "../../entities/include/Constants.h"

class GEnergy {
    private:
        sf::RenderWindow* m_window;
        std::vector<sf::Texture> m_textures;
        std::vector<sf::Sprite> m_sprites;
        std::vector<sf::Text> m_texts;
        sf::Vector2f m_position;
        sf::Vector2f m_size;
        sf::Font m_font;
        int m_fontSize;
        float m_imageScale;

        EnergyStack m_energyStack;

        void init();
        void update();
        void loadEnergy(sf::Texture &texture, sf::Sprite &sprite, std::string imagePath);

    public:
        GEnergy();
        GEnergy(sf::RenderWindow* window, sf::Vector2f size);

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setEnergyStack(EnergyStack energyStack);
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);
        void setFontSize(int fontSize);

        void draw();
};
#endif
