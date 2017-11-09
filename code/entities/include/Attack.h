#ifndef DEF_ATTACK
#define DEF_ATTACK

#include <string>
#include "EnergyType.h"

class Attack {
    private:
        std::string m_name;
        std::string m_description;
        EnergyType m_attackType;
        int m_cost;

    public:
        Attack();
        ~Attack();

        std::string getName();
        std::string getDescription();
        EnergyType getAttackType();
        int getCost();
};
#endif
