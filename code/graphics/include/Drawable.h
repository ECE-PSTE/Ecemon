#ifndef DEF_DRAWABLE
#define DEF_DRAWABLE

#include <SFML/Graphics.hpp>
#include <cmath>

class Drawable {
    protected:
        sf::RenderWindow* m_window;
        sf::Vector2f m_position;
        sf::Vector2f m_size;

        void update();

    public:
        Drawable();
        virtual ~Drawable();

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setPosition(sf::Vector2f position);
        virtual void setSize(sf::Vector2f size);

        void moveToward(sf::Vector2f position);

        virtual void draw();
};
#endif
