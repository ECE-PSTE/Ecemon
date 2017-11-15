#ifndef DEF_CREATURECARD
#define DEF_CREATURECARD

#include <iostream>
#include <vector>

#include "Card.h"
#include "Attack.h"
#include "CardType.h"

class CreatureCard : public Card {
    private:
        int m_life;
        std::vector<Attack> m_attacks;

    public:
        CreatureCard();
        CreatureCard(int id);
        ~CreatureCard();

        void writeCard(std::ostream &os);
        void readCard(std::istream &is);

        int getLife();
        std::vector<Attack> getAttacks();

        void setLife(int life);
        CardType type();
};
#endif
