#ifndef DEF_EFFECTSTACK
#define DEF_EFFECTSTACK

#include <iostream>

class Effectstack{
    private:
        bool m_freez;
        int m_damage;

    public:

        Effectstack();
        ~Effectstack();

        void setFreez(bool val){m_freez = val}
        void setDamage(int val){m_damage = val}

        bool getFreez(){return m_freez}
        int getDamage(){return m_damage}

         //Clean effects like m_freez
        void endTurn();

        void takeDamage(int damage);

        //Reset all effects on creature
        void newCreature();
};
#endif
