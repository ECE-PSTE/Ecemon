#include "../include/GCard.h"

GCard::GCard(){
}

GCard::GCard(const Card *card, sf::RenderWindow *window){
    init(card, window);
}

GCard::~GCard(){
}

void GCard::init(const Card* card, sf::RenderWindow* window){
    m_card = card;
    m_window = window;

    m_size.x = 250;
    m_size.y = 450;
    m_position.x = 0;
    m_position.y = 0;

    m_cardShape = sf::RectangleShape(m_size);
    m_cardShape.setOrigin(m_size.x/2, m_size.y/2);

    assert(m_font.loadFromFile("../graphics/fonts/Prototype.ttf"));
    m_nameText.setFont(m_font);
    m_nameText.setCharacterSize(24);
    m_nameText.setColor(sf::Color::Red);
    m_nameText.setString(card->getName());
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setFont(m_font);
    m_descriptionText.setCharacterSize(24);
    m_descriptionText.setColor(sf::Color::Red);
    m_descriptionText.setString(card->getDescription());
    sf::FloatRect descRect = m_descriptionText.getLocalBounds();
    m_descriptionText.setOrigin(descRect.left + descRect.width/2.0f, descRect.top  + descRect.height/2.0f);
}

sf::RenderWindow* GCard::getWindow() const{
    return m_window;
}

sf::Vector2f GCard::getPosition() const{
    return m_position;
}

sf::Vector2f GCard::getSize() const{
    return m_size;
}

void GCard::setWindow(sf::RenderWindow *window){
    m_window = window;
}

void GCard::setPosition(sf::Vector2f position){
    m_position = position;
}

void GCard::setSize(sf::Vector2f size){
    m_size = size;
}

void GCard::setCardImage(std::string imagePath, float scaleX, float scaleY){
    assert(m_imageTexture.loadFromFile(imagePath));
    m_imageTexture.setSmooth(true);
    m_imageSprite.setTexture(m_imageTexture);
    m_imageSprite.setOrigin(m_imageTexture.getSize().x/2, m_imageTexture.getSize().y/2);
    m_imageSprite.setScale(scaleX, scaleY);
}

void GCard::update(){
    m_cardShape.setPosition(m_position.x, m_position.y);
    m_nameText.setPosition(m_position.x, m_position.y-m_size.y/2 + 30);
    m_descriptionText.setPosition(m_position.x, m_position.y+m_size.y/2-30);
    m_imageSprite.setPosition(m_position.x, m_position.y);
}

void GCard::draw(){
    GCard::update();
    m_window->draw(m_cardShape);
    m_window->draw(m_nameText);
    m_window->draw(m_descriptionText);
    m_window->draw(m_imageSprite);
}
