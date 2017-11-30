#include "../include/GBoard.h"

GBoard::GBoard(){

}

GBoard::GBoard(sf::RenderWindow* window, sf::Vector2f size){
    m_window = window;
    m_size = size;
    init();
}

void GBoard::setBoard(Board *board){
    m_board = board;
}

void GBoard::setGEnergy(GEnergy genergy){
    m_genergy = genergy;
}

void GBoard::setGCreatureCard(GCreatureCard gcreature){
    m_gcreature = gcreature;
}

void GBoard::setGCardBet(GCard gcardBet){
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

void GBoard::setCemeteryCardsCount(int cemeteryCardsCount){
    m_cemeteryCountText.setString(std::to_string(cemeteryCardsCount));
    sf::FloatRect rect = m_cemeteryCountText.getLocalBounds();
    m_cemeteryCountText.setOrigin(rect.left + rect.width/2.0f, rect.top  + rect.height/2.0f);
}

void GBoard::init(){
    m_genergy = GEnergy(m_window, sf::Vector2f(100, 200));
    m_gcreature = GCreatureCard(m_window, sf::Vector2f(Constants::DefaultCardWidth(), Constants::DefaultCardHeight()));
    m_gcardBet = GCard(m_window, sf::Vector2f(100, 180));

    assert(m_font.loadFromFile("../graphics/fonts/"+Constants::DefaultFont()));
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

void GBoard::updateContent(){
    m_genergy.setEnergyStack(*m_board->getpQuantityEnergy());
    m_gcreature.setCard(m_board->getCreatureOnBoard());
    m_gcreature.setCardImage("../graphics/images/cartman.png");  // should load path from card id ...
    m_gcreature.setLife(m_board->getCreatureLifePoint());
    m_gcardBet.setCard(m_board->getCardBet());
    m_gcardBet.setCardImage("../graphics/images/block.png");
    setPlayerName(m_board->getNamePlayer());
    setPlayerLifePoints(m_board->getLifePoint());
    setDeckCardsLeft(m_board->getDeckPlay()->getpCards()->size());
    setCemeteryCardsCount(m_board->getpCreatureGraveyard()->getpCards()->size());
}

void GBoard::update(){
    m_playerNameText.setPosition(sf::Vector2f(
        m_position.x,
        bottom() - m_playerNameText.getLocalBounds().top
        - m_playerNameText.getLocalBounds().height/2.0f - hp(3)
    ));
    m_playerLifePointsText.setPosition(sf::Vector2f(
        m_position.x,
        m_playerNameText.getPosition().y - hp(3)
    ));
    m_gcardBet.setPosition(sf::Vector2f(
        left() + m_gcardBet.getSize().x/2 + wp(3),
        m_position.y
    ));
    m_genergy.setPosition(sf::Vector2f(
        left() + m_genergy.getSize().x/2 + wp(3),
        bottom() - m_genergy.getSize().y/2
    ));
    m_gcreature.setPosition(sf::Vector2f(
        m_position.x,
        m_position.y
    ));
    m_deckSprite.setPosition(sf::Vector2f(
        right() - m_deckScale*m_deckTexture.getSize().x/2 - wp(3),
        m_position.y
    ));
    m_deckCountText.setPosition(sf::Vector2f(
        m_deckSprite.getPosition().x,
        m_position.y+m_deckScale*m_deckTexture.getSize().y/2+hp(3)
    ));
    m_cemeterySprite.setPosition(sf::Vector2f(
        left() + m_cemeteryScale*m_cemeteryTexture.getSize().x/2 + wp(2),
        top() + m_cemeteryScale*m_cemeteryTexture.getSize().y/2 + wp(2)
    ));
    m_cemeteryCountText.setPosition(sf::Vector2f(
        left() + m_cemeteryScale*m_cemeteryTexture.getSize().x/2 + wp(2),
        top() + m_cemeteryScale*m_cemeteryTexture.getSize().y + 2*wp(2)
    ));
}

float GBoard::left(){
    return m_position.x-m_size.x/2.0f;
}

float GBoard::right(){
    return m_position.x+m_size.x/2.0f;
}

float GBoard::bottom(){
    return m_position.y+m_size.y/2.0f;
}

float GBoard::top(){
    return m_position.y-m_size.y/2.0f;
}

float GBoard::wp(float p){
    return m_size.x * (p/100.0f);
}

float GBoard::hp(float p){
    return m_size.y * (p/100.0f);
}

void GBoard::draw(){
    GBoard::updateContent();
    GBoard::update();
    m_gcardBet.draw();
    m_gcreature.draw();
    m_genergy.draw();
    m_window->draw(m_playerNameText);
    m_window->draw(m_playerLifePointsText);
    m_window->draw(m_cemeterySprite);
    m_window->draw(m_cemeteryCountText);
    m_window->draw(m_deckSprite);
    m_window->draw(m_deckCountText);
}
