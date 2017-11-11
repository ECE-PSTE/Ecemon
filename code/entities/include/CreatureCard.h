#ifndef DEF_CREATURECARD
#define DEF_CREATURECARD

#include "Card.h"
#include "Attack.h"

class CreatureCard : public Card {
    private:
        int m_life;
        Attack m_firstAttack;
        Attack m_secondAttack;

    public:
        CreatureCard();
        ~CreatureCard();

        int getLife();
        Attack getFirstAttack();
        Attack getSecondAttack();
};
#endif
