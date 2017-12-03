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
        Drawable(sf::RenderWindow* window, sf::Vector2f size);
        virtual ~Drawable();

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setPosition(int x, int y);
        virtual void setSize(int x, int y);

        void moveToward(int x, int y);

        virtual void draw();
};
#endif
