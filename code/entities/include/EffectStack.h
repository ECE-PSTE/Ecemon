#ifndef DEF_EFFECTSTACK
#define DEF_EFFECTSTACK

#include <iostream>
#include <cstdlib>
#include <string>

class EffectStack{
    private:
        bool m_freez;
        int m_damage;

    public:

        EffectStack();
        ~EffectStack();

        bool getFreez(){return m_freez;}
        int getDamage();

        void setFreez(bool val){m_freez = val;}
        void setDamage(int val){m_damage = val;}

         //Clean effects like m_freez
        void endTurn();

        void takeDamage(int damage);

        //Reset all effects on creature
        void newCreature();
};
#endif
