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

    assert(m_font.loadFromFile("../graphics/fonts/"+Constants::DefaultFont()));

    m_size.x = Constants::DefaultCardWidth();
    m_size.y = Constants::DefaultCardHeight();
    m_position.x = 0;
    m_position.y = 0;
    m_characterSize = Constants::DefaultCharacterSize();

    m_cardShape = sf::RectangleShape(m_size);
    m_cardShape.setOrigin(m_size.x/2, m_size.y/2);

    m_nameText.setFont(m_font);
    m_nameText.setCharacterSize(m_characterSize);
    m_nameText.setColor(sf::Color::Red);
    m_nameText.setString(card->getName());
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setFont(m_font);
    m_descriptionText.setCharacterSize(m_characterSize);
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

unsigned int GCard::getCharacterSize() const{
    return m_characterSize;
}

float GCard::getSpriteScale() const{
    int width = m_imageTexture.getSize().x;
    if(width>m_size.x){
        float margin = 0.02*width;
        float scale = (m_size.x-2.0*margin)/width;
        return scale;
    }
    return 0.1f;
}

void GCard::setWindow(sf::RenderWindow *window){
    m_window = window;
}

void GCard::setPosition(sf::Vector2f position){
    m_position = position;
}

void GCard::setSize(sf::Vector2f size){
    m_size = size;
    m_cardShape.setSize(size);
    m_cardShape.setOrigin(m_size.x/2, m_size.y/2);
    float scale = getSpriteScale();
    m_imageSprite.setScale(scale, scale);
}

void GCard::setCardImage(std::string imagePath){
    assert(m_imageTexture.loadFromFile(imagePath));
    m_imageTexture.setSmooth(true);
    m_imageSprite.setTexture(m_imageTexture);
    m_imageSprite.setOrigin(m_imageTexture.getSize().x/2, m_imageTexture.getSize().y/2);
    float scale = getSpriteScale();
    m_imageSprite.setScale(scale, scale);
}

void GCard::setCharacterSize(unsigned int size){
    m_characterSize = size;

    m_nameText.setCharacterSize(size);
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setCharacterSize(size);
    sf::FloatRect descRect = m_descriptionText.getLocalBounds();
    m_descriptionText.setOrigin(descRect.left + descRect.width/2.0f, descRect.top  + descRect.height/2.0f);
}

void GCard::update(){
    m_cardShape.setPosition(m_position.x, m_position.y);
    m_nameText.setPosition(m_position.x, m_position.y-m_size.y/2 + 0.1*m_size.y);
    m_descriptionText.setPosition(m_position.x, m_position.y+m_size.y/2- 0.1*m_size.y);
    m_imageSprite.setPosition(m_position.x, m_position.y);
}

void GCard::draw(){
    GCard::update();
    m_window->draw(m_cardShape);
    m_window->draw(m_nameText);
    m_window->draw(m_descriptionText);
    m_window->draw(m_imageSprite);
}
