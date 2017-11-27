#ifndef GCARD
#define GCARD

#include <cassert>
#include <SFML/Graphics.hpp>
#include "../../entities/include/Card.h"
#include "../../entities/include/Constants.h"

class GCard {
    protected:
        sf::RenderWindow *m_window;
        sf::RectangleShape m_cardShape;
        sf::Texture m_imageTexture;
        sf::Sprite m_imageSprite;
        sf::Text m_nameText;
        sf::Text m_descriptionText;
        sf::Font m_font;
        sf::Vector2f m_size;
        sf::Vector2f m_position;
        unsigned int m_characterSize;

        const Card* m_card;

        void init(sf::RenderWindow* window, sf::Vector2f size, const Card *card);
        float getSpriteScale() const;
        virtual void update();

    public:
        GCard();
        GCard(sf::RenderWindow *window, sf::Vector2f size, const Card *card);
        virtual ~GCard();

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setWindow(sf::RenderWindow *window);
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);
        void setCardImage(std::string imagePath);
        virtual void setFontSize(unsigned int size);

        virtual void draw();
};

#endif
