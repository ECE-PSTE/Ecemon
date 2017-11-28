#ifndef DEF_GBOARD
#define DEF_GBOARD

#include "Drawable.h"
#include "GCard.h"
#include "GCreatureCard.h"
#include "GEnergy.h"

class GBoard : public Drawable{
    private:
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
        sf::Font m_font;
        int m_fontSize;
        float m_deckScale;
        float m_cemeteryScale;

        void init();
        void update();

        float left();
        float right();
        float bottom();
        float top();
        float wp(float p);
        float hp(float p);

    public:
        GBoard();
        GBoard(sf::RenderWindow* window, sf::Vector2f size);

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
