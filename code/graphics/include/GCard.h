#ifndef GCARD
#define GCARD

#include <cassert>
#include <SFML/Graphics.hpp>
#include "../../entities/include/Card.h"

class GCard {
    protected:
        sf::RenderWindow *m_window;
        sf::RectangleShape m_cardShape;
        sf::Text m_nameText;
        sf::Text m_descriptionText;
        sf::Font m_font;
        sf::Vector2f m_size;
        sf::Vector2f m_position;

        const Card* m_card;

        void init();

    public:
        GCard();
        virtual ~GCard();

        sf::RenderWindow* getWindow() const;
        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setWindow(sf::RenderWindow *window);
        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);

        virtual void update();
        virtual void draw();
};

#endif
