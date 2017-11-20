#ifndef DEF_ATTACK
#define DEF_ATTACK

#include <iostream>

#include "EnergyType.h"
#include "Constants.h"

class Attack {
    private:
        std::string m_name;
        std::string m_description;
        EnergyType m_attackType;
        int m_cost;
        int m_damage;

    public:
        Attack();
        ~Attack();

        std::string getName();
        std::string getDescription();
        EnergyType getAttackType();
        int getCost();
        int getDamage();

        void setName(std::string name);
        void setDescription(std::string description);
        void setAttackType(EnergyType attackType);
        void setCost(int cost);
        void setDamage(int dam);
};
#endif
