#include "../include/GBoard.h"

GBoard::GBoard(){

}

GBoard::GBoard(sf::RenderWindow* window, sf::Vector2f size){
    m_window = window;
    m_size = size;
    init();
}

sf::Vector2f GBoard::getPosition() const{
    return m_position;
}

sf::Vector2f GBoard::getSize() const{
    return m_size;
}

void GBoard::setPosition(sf::Vector2f position){
    m_position = position;
}

void GBoard::setSize(sf::Vector2f size){
    m_size = size;
}

void GBoard::setGEnergy(GEnergy genergy){
    m_genergy = genergy;
}

void GBoard::setGCreatureCard(GCreatureCard gcreature){
    m_gcreature = gcreature;
}

void GBoard::setGCardBet(GCard* gcardBet){
    m_gcardBet = gcardBet;
}

void GBoard::setPlayerName(std::string playerName){
    m_playerNameText.setString(playerName);
    sf::FloatRect rect = m_playerNameText.getLocalBounds();
    m_playerNameText.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
}

void GBoard::setPlayerLifePoints(int playerLifePoints){
    m_playerLifePointsText.setString(std::to_string(playerLifePoints));
    sf::FloatRect rect = m_playerLifePointsText.getLocalBounds();
    m_playerLifePointsText.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
}

void GBoard::setDeckCardsLeft(int deckCardsLeft){
    m_deckCountText.setString(std::to_string(deckCardsLeft));
    sf::FloatRect rect = m_deckCountText.getLocalBounds();
    m_deckCountText.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
}

void GBoard::setCemetryCardsCount(int cemeteryCardsCount){
    m_cemeteryCountText.setString(std::to_string(cemeteryCardsCount));
    sf::FloatRect rect = m_cemeteryCountText.getLocalBounds();
    m_cemeteryCountText.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
}

void GBoard::init(){
    assert(m_font.loadFromFile("../graphics/fonts/Prototype.ttf"));
    m_fontSize = 24;
    m_deckScale = 0.3f;
    m_cemeteryScale = 0.5f;

    assert(m_deckTexture.loadFromFile("../graphics/images/back-card.png"));
    m_deckTexture.setSmooth(true);
    m_deckSprite.setTexture(m_deckTexture);
    m_deckSprite.setScale(m_deckScale, m_deckScale);
    m_deckSprite.setOrigin(m_deckTexture.getSize().x/2, m_deckTexture.getSize().y/2);

    assert(m_cemeteryTexture.loadFromFile("../graphics/images/cemetery.png"));
    m_cemeteryTexture.setSmooth(true);
    m_cemeterySprite.setTexture(m_cemeteryTexture);
    m_cemeterySprite.setScale(m_cemeteryScale, m_cemeteryScale);
    m_cemeterySprite.setOrigin(m_cemeteryTexture.getSize().x/2, m_cemeteryTexture.getSize().y/2);

    m_playerNameText.setFont(m_font);
    m_playerNameText.setCharacterSize(m_fontSize);
    m_playerNameText.setColor(sf::Color::White);

    m_playerLifePointsText.setFont(m_font);
    m_playerLifePointsText.setCharacterSize(m_fontSize);
    m_playerLifePointsText.setColor(sf::Color::White);

    m_cemeteryCountText.setFont(m_font);
    m_cemeteryCountText.setCharacterSize(m_fontSize);
    m_cemeteryCountText.setColor(sf::Color::White);

    m_deckCountText.setFont(m_font);
    m_deckCountText.setCharacterSize(m_fontSize);
    m_deckCountText.setColor(sf::Color::White);
}

void GBoard::update(){
    m_playerNameText.setPosition(sf::Vector2f(
        m_position.x,
        m_position.y + m_size.y/2 - m_playerNameText.getLocalBounds().top
        - m_playerNameText.getLocalBounds().height/2.0f - m_size.y*0.03
    ));
    m_playerLifePointsText.setPosition(sf::Vector2f(
        m_position.x,
        m_playerNameText.getPosition().y - m_size.y*0.03
    ));
    m_gcardBet->setPosition(sf::Vector2f(
        m_position.x-m_size.x/2 + m_gcardBet->getSize().x/2 + m_size.x*0.03,
        m_position.y
    ));
    m_genergy.setPosition(sf::Vector2f(
        m_position.x-m_size.x/2 + m_genergy.getSize().x/2 + m_size.x*0.03,
        m_position.y+m_size.y/2 - m_genergy.getSize().y/2
    ));
    m_gcreature.setPosition(sf::Vector2f(
        m_position.x,
        m_position.y
    ));
    m_deckSprite.setPosition(sf::Vector2f(
        m_position.x + m_size.x/2 - m_deckScale*m_deckTexture.getSize().x/2 - m_size.x*0.03,
        m_position.y
    ));
    m_deckCountText.setPosition(sf::Vector2f(
        m_deckSprite.getPosition().x,
        m_position.y+m_deckScale*m_deckTexture.getSize().y/2+m_size.y*0.03
    ));
    m_cemeterySprite.setPosition(sf::Vector2f(
        m_position.x-m_size.x/2 + m_cemeteryScale*m_cemeteryTexture.getSize().x/2+m_size.x*0.03,
        m_position.y-m_size.y/2 + m_cemeteryScale*m_cemeteryTexture.getSize().y/2+m_size.x*0.03
    ));
    m_cemeteryCountText.setPosition(sf::Vector2f(
        m_position.x-m_size.x/2 + m_cemeteryScale*m_cemeteryTexture.getSize().x/2+m_size.x*0.03,
        m_cemeterySprite.getPosition().y+m_cemeteryScale*m_cemeteryTexture.getSize().y/2+m_size.y*0.03
    ));
}

void GBoard::draw(){
    GBoard::update();
    m_gcardBet->draw();
    m_gcreature.draw();
    m_genergy.draw();
    m_window->draw(m_playerNameText);
    m_window->draw(m_playerLifePointsText);
    m_window->draw(m_cemeterySprite);
    m_window->draw(m_cemeteryCountText);
    m_window->draw(m_deckSprite);
    m_window->draw(m_deckCountText);
}
