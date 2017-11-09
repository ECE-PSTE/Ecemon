#ifndef DEF_CREATURECARD
#define DEF_CREATURECARD

#include "Card.h"

class CreatureCard : public Card {
    private:
        int m_life;
        // Attack m_attack1...

    public:
        CreatureCard();
        ~CreatureCard();

        int getLife();
};
#endif
