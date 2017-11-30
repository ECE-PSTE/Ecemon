#ifndef DEF_GDIALOG
#define DEF_GDIALOG

#include <SFML/Graphics.hpp>
#include <cassert>
#include "Drawable.h"

class GDialog : public Drawable {
    private:
        sf::RectangleShape m_dialogBox;
        sf::RectangleShape m_positiveBox;
        sf::RectangleShape m_negativeBox;
        sf::Text m_messageText;
        sf::Text m_positiveButtonText;
        sf::Text m_negativeButtonText;
        sf::Font m_font;
        sf::Color m_fontColor;
        sf::Color m_backgroundColor;
        sf::Color m_positiveButtonColor;
        sf::Color m_negativeButtonColor;
        int m_fontSize;

        bool m_positiveHovered;
        bool m_negativeHovered;

        void update();

    public:
        GDialog(sf::RenderWindow* window, sf::Vector2f size);

        void setMessage(std::string message);
        void setPositiveButton(std::string positiveButton);
        void setNegativeButton(std::string negativeButton);

        int whichArea(sf::Vector2f position);

        void draw();
};

#endif
