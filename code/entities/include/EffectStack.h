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

        void setFreez(bool val){m_freez = val;}
        void setDamage(int val){m_damage = val;}

        bool getFreez() const{return m_freez;}
        int getDamage() const{return m_damage;}

         //Clean effects like m_freez
        void endTurn();

        void takeDamage(int damage);

        //Reset all effects on creature
        void newCreature();
};
#endif
