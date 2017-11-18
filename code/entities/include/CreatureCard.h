#ifndef DEF_CREATURECARD
#define DEF_CREATURECARD

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "Card.h"
#include "Attack.h"
#include "CardType.h"
#include "Constants.h"

class CreatureCard : public Card {
    private:
        int m_life;
        std::vector<Attack> m_attacks;

    public:
        CreatureCard();
        CreatureCard(int id);
        ~CreatureCard();

        void writeCard(std::ostream &os) const;
        void readCard(std::istream &is);
        CardType type() const;

        int getLife();
        std::vector<Attack> getAttacks();

        void setLife(int life);
        void addAttack(Attack attack);
};
#endif
