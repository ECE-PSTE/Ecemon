#ifndef GCARD
#define GCARD

#include <cassert>
#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "../../entities/include/Card.h"
#include "../../entities/include/Constants.h"

class GCard : public Drawable {
    protected:
        sf::RectangleShape m_cardShape;
        sf::Texture m_imageTexture;
        sf::Sprite m_imageSprite;
        sf::Text m_nameText;
        sf::Text m_descriptionText;
        sf::Font m_font;
        sf::Color m_fontColor;
        unsigned int m_fontSize;

        const Card* m_card;

        void init(sf::RenderWindow* window, sf::Vector2f size);
        float getSpriteScale() const;
        virtual void update();

    public:
        GCard();
        GCard(sf::RenderWindow *window, sf::Vector2f size);
        virtual ~GCard();

        void setSize(sf::Vector2f size);
        void setCardImage(std::string imagePath);
        void setCardColor(sf::Color cardColor);
        virtual void setCard(const Card *card);
        virtual void setFontSize(unsigned int size);
        virtual void setFontColor(sf::Color fontColor);

        virtual void draw();
};

#endif
