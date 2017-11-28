#include "../include/GEnergy.h"

GEnergy::GEnergy(){
    init();
}

GEnergy::GEnergy(sf::RenderWindow* window, sf::Vector2f size){
    m_window = window;
    m_size = size;
    init();
}

void GEnergy::init(){
    assert(m_font.loadFromFile("../graphics/fonts/Prototype.ttf"));

    m_imageScale = m_size.y/(4*256);
    m_size.x *= m_imageScale;
    m_fontSize = 24;

    m_textures.resize(4);
    m_sprites.resize(4);
    m_texts.resize(4);

    for(auto &text : m_texts){
        text.setFont(m_font);
        text.setCharacterSize(m_fontSize);
        text.setColor(sf::Color::White);
    }

    // icones 256x256 pixels
    loadEnergy(m_textures[0], m_sprites[0], "../graphics/images/chili.png");
    loadEnergy(m_textures[1], m_sprites[1], "../graphics/images/taco.png");
    loadEnergy(m_textures[2], m_sprites[2], "../graphics/images/ice-cream.png");
    loadEnergy(m_textures[3], m_sprites[3], "../graphics/images/blueberries.png");
}

void GEnergy::loadEnergy(sf::Texture &texture, sf::Sprite &sprite, std::string imagePath){
    assert(texture.loadFromFile(imagePath));
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(m_imageScale, m_imageScale);
}

sf::Vector2f GEnergy::getPosition() const{
    return m_position;
}

sf::Vector2f GEnergy::getSize() const{
    return m_size;
}

void GEnergy::setPosition(sf::Vector2f position){
    m_position = position;
}

void GEnergy::setSize(sf::Vector2f size){
    m_size = size;
}

void GEnergy::setFontSize(int fontSize){
    m_fontSize = fontSize;
}

void GEnergy::setEnergyStack(EnergyStack energyStack){
    m_energyStack = energyStack;

    m_texts[0].setString(std::to_string(m_energyStack.getChili()));
    m_texts[1].setString(std::to_string(m_energyStack.getTacos()));
    m_texts[2].setString(std::to_string(m_energyStack.getIceCream()));
    m_texts[3].setString(std::to_string(m_energyStack.getBlueberries()));
}

void GEnergy::update(){
    int imageSize = m_imageScale*m_textures[0].getSize().x;
    int margin = 10;

    int j=2;
    for(int i=0 ; i<4 ; i++){
        m_sprites[i].setPosition(m_position.x-imageSize/2, m_position.y-j*imageSize);
        m_texts[i].setPosition(m_position.x+imageSize/2+margin, m_position.y-j*imageSize);
        j--;
    }
}

void GEnergy::draw(){
    GEnergy::update();
    for(int i=0 ; i<4 ; i++){
        m_window->draw(m_sprites[i]);
        m_window->draw(m_texts[i]);
    }
}
