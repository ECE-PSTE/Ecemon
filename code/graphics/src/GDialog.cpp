#include "../include/GDialog.h"

GDialog::GDialog(sf::RenderWindow* window, sf::Vector2f size) : Drawable(window, size){
    assert(m_font.loadFromFile("../graphics/fonts/Prototype.ttf"));
    m_fontColor = sf::Color::White;
    m_backgroundColor = sf::Color::Blue;
    m_positiveButtonColor = sf::Color::Green;
    m_negativeButtonColor = sf::Color::Red;
    m_fontSize = 18;

    m_position.x = 0;
    m_position.y = 0;

    m_positiveHovered = false;
    m_negativeHovered = false;

    m_dialogBox = sf::RectangleShape(m_size);
    m_dialogBox.setOrigin(m_size.x/2, m_size.y/2);
    m_dialogBox.setFillColor(m_backgroundColor);
    m_dialogBox.setOutlineThickness(3);
    m_dialogBox.setOutlineColor(sf::Color::Red);

    m_messageText.setFont(m_font);
    m_positiveButtonText.setFont(m_font);
    m_negativeButtonText.setFont(m_font);

    m_messageText.setCharacterSize(m_fontSize);
    m_positiveButtonText.setCharacterSize(m_fontSize);
    m_negativeButtonText.setCharacterSize(m_fontSize);

    m_messageText.setColor(m_fontColor);
    m_positiveButtonText.setColor(m_positiveButtonColor);
    m_negativeButtonText.setColor(m_negativeButtonColor);
}

void GDialog::setMessage(std::string message){
    m_messageText.setString(message);
}

void GDialog::setPositiveButton(std::string positiveButton){
    m_positiveButtonText.setString(positiveButton);
    sf::FloatRect pos = m_positiveButtonText.getGlobalBounds();
    m_positiveBox = sf::RectangleShape(sf::Vector2f(pos.width+6, pos.height+6));
    m_positiveBox.setOrigin(pos.width/2.0f+3, pos.height/2.0f+3);
    m_positiveBox.setFillColor(sf::Color::Transparent);
    m_positiveBox.setOutlineThickness(3);
    m_positiveBox.setOutlineColor(sf::Color::Green);
}

void GDialog::setNegativeButton(std::string negativeButton){
    m_negativeButtonText.setString(negativeButton);
    sf::FloatRect neg = m_negativeButtonText.getGlobalBounds();
    m_negativeBox = sf::RectangleShape(sf::Vector2f(neg.width+6, neg.height+6));
    m_negativeBox.setOrigin(neg.width/2.0f+3, neg.height/2.0f+3);
    m_negativeBox.setFillColor(sf::Color::Transparent);
    m_negativeBox.setOutlineThickness(3);
    m_negativeBox.setOutlineColor(sf::Color::Red);
}

int GDialog::getState(sf::Vector2f position){
    sf::FloatRect pos = m_positiveButtonText.getGlobalBounds();
    sf::FloatRect neg = m_negativeButtonText.getGlobalBounds();

    if(position.x >= pos.left && position.x <= pos.left+pos.width){
        if(position.y >= pos.top && position.y <= pos.top+pos.height){
            return 1;
        }
    }
    if(position.x >= neg.left && position.x <= neg.left+neg.width){
        if(position.y >= neg.top && position.y <= neg.top+neg.height){
            return -1;
        }
    }

    return 0;
}

void GDialog::mouseHoverProcess(sf::Vector2f position){
    int r = getState(position);
    if(r==1){
        m_positiveHovered = true;
        m_negativeHovered = false;
    }
    else if(r==-1){
        m_positiveHovered = false;
        m_negativeHovered = true;
    }
    else{
        m_positiveHovered = false;
        m_negativeHovered = false;
    }
}

void GDialog::update(){
    m_dialogBox.setPosition(m_position.x, m_position.y);
    m_messageText.setPosition(m_position.x-m_size.x/2+15, m_position.y-m_size.y/2+15);
    sf::FloatRect pos = m_positiveButtonText.getGlobalBounds();
    sf::FloatRect neg = m_negativeButtonText.getGlobalBounds();
    m_positiveButtonText.setPosition(
        m_position.x-m_size.x/2+15,
        m_position.y+m_size.y/2-15 - pos.height
    );
    m_negativeButtonText.setPosition(
        m_position.x+m_size.x/2-15 - neg.width,
        m_position.y+m_size.y/2-15 - pos.height
    );
    m_positiveBox.setPosition(
        pos.left + pos.width/2.0f,
        pos.top  + pos.height/2.0f
    );
    m_negativeBox.setPosition(
        neg.left + neg.width/2.0f,
        neg.top  + neg.height/2.0f
    );
}

void GDialog::draw(){
    GDialog::update();
    m_window->draw(m_dialogBox);
    m_window->draw(m_messageText);
    m_window->draw(m_positiveButtonText);
    m_window->draw(m_negativeButtonText);
    if(m_positiveHovered){
        m_window->draw(m_positiveBox);
    }
    else if(m_negativeHovered){
        m_window->draw(m_negativeBox);
    }
}
