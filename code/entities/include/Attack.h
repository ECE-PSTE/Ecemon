#ifndef DEF_ATTACK
#define DEF_ATTACK

#include <iostream>

#include "EnergyType.h"
#include "Constants.h"
#include "../../utils/Utils.h"

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

        std::string getName() const;
        std::string getDescription() const;
        EnergyType getAttackType() const;
        int getCost() const;
        int getDamage() const;

        void setName(std::string name);
        void setDescription(std::string description);
        void setAttackType(EnergyType attackType);
        void setCost(int cost);
        void setDamage(int dam);

        friend std::ostream& operator<<(std::ostream& os, const Attack& attack);
        friend std::istream& operator>>(std::istream& is, Attack& attack);
};
#endif
