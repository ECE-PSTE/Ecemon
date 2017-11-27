#ifndef DEF_GBOARD
#define DEF_GBOARD

#include "GCard.h"
#include "GCreatureCard.h"
#include "GEnergy.h"

class GBoard {
    private:
        sf::RenderWindow* m_window;
        GEnergy m_genergy;
        GCreatureCard m_gcreature;
        GCard* m_gcardBet;
        sf::Text m_playerNameText;
        sf::Text m_playerLifePointsText;
        sf::Texture m_deckTexture;
        sf::Sprite m_deckSprite;
        sf::Text m_deckCountText;
        sf::Texture m_cemeteryTexture;
        sf::Sprite m_cemeterySprite;
        sf::Text m_cemeteryCountText;
        sf::Vector2f m_position;
        sf::Vector2f m_size;
        sf::Font m_font;
        int m_fontSize;
        float m_deckScale;
        float m_cemeteryScale;

        void init();
        void update();

    public:
        GBoard();
        GBoard(sf::RenderWindow* window, sf::Vector2f size);

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;

        void setPosition(sf::Vector2f position);
        void setSize(sf::Vector2f size);

        void setGEnergy(GEnergy genergy);
        void setGCreatureCard(GCreatureCard gcreature);
        void setGCardBet(GCard* gcardBet);
        void setPlayerName(std::string playerName);
        void setPlayerLifePoints(int playerLifePoints);
        void setDeckCardsLeft(int deckCardsLeft);
        void setCemetryCardsCount(int cemeteryCardsCount);

        void draw();
};

#endif
