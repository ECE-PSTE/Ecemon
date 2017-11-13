#ifndef DEF_CREATURECARD
#define DEF_CREATURECARD

#include "Card.h"
#include "Attack.h"
#include "CardType.h"

class CreatureCard : public Card {
    private:
        int m_life;
        std::vector<Attack> m_vattack;

    public:
        CreatureCard();
        CreatureCard(int id);
        ~CreatureCard();

        int getLife();
        std::vector<Attack> getVattack();


        void setLife(int life);


        CardType type();


};
#endif
