#include "../include/GCard.h"

GCard::GCard(){
}

GCard::GCard(sf::RenderWindow *window, sf::Vector2f size){
    init(window, size);
}

GCard::~GCard(){
}

void GCard::init(sf::RenderWindow* window, sf::Vector2f size){
    m_window = window;
    m_size = size;

    assert(m_font.loadFromFile("../graphics/fonts/"+Constants::DefaultFont()));

    m_position.x = 0;
    m_position.y = 0;
    m_fontSize = Constants::DefaultCardFontSize();
    m_fontColor = Constants::DefaultCardTextColor();

    m_cardShape = sf::RectangleShape(m_size);
    m_cardShape.setOrigin(m_size.x/2, m_size.y/2);

    m_nameText.setFont(m_font);
    m_nameText.setCharacterSize(m_fontSize);
    m_nameText.setColor(m_fontColor);

    m_descriptionText.setFont(m_font);
    m_descriptionText.setCharacterSize(m_fontSize);
    m_descriptionText.setColor(m_fontColor);
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

void GCard::setSize(sf::Vector2f size){
    m_size = size;
    m_cardShape.setSize(size);
    m_cardShape.setOrigin(m_size.x/2, m_size.y/2);
    float scale = getSpriteScale();
    m_imageSprite.setScale(scale, scale);
}

void GCard::setCard(const Card *card){
    m_card = card;

    m_nameText.setString(m_card->getName());
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setString(m_card->getDescription());
    sf::FloatRect descRect = m_descriptionText.getLocalBounds();
    m_descriptionText.setOrigin(descRect.left + descRect.width/2.0f, descRect.top  + descRect.height/2.0f);
}

void GCard::setCardImage(std::string imagePath){
    assert(m_imageTexture.loadFromFile(imagePath));
    m_imageTexture.setSmooth(true);
    m_imageSprite.setTexture(m_imageTexture);
    m_imageSprite.setOrigin(m_imageTexture.getSize().x/2, m_imageTexture.getSize().y/2);
    float scale = getSpriteScale();
    m_imageSprite.setScale(scale, scale);
}

void GCard::setFontSize(unsigned int size){
    m_fontSize = size;

    m_nameText.setCharacterSize(size);
    sf::FloatRect nameRect = m_nameText.getLocalBounds();
    m_nameText.setOrigin(nameRect.left + nameRect.width/2.0f, nameRect.top  + nameRect.height/2.0f);

    m_descriptionText.setCharacterSize(size);
    sf::FloatRect descRect = m_descriptionText.getLocalBounds();
    m_descriptionText.setOrigin(descRect.left + descRect.width/2.0f, descRect.top  + descRect.height/2.0f);
}

void GCard::setFontColor(sf::Color fontColor){
    m_fontColor = fontColor;
    m_nameText.setColor(fontColor);
    m_descriptionText.setColor(fontColor);
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
