#ifndef DEF_ENERGYSTACK
#define DEF_ENERGYSTACK

#include <iostream>
#include "..\..\entities\include\EnergyType.h"

class EnergyStack{
    private:
        int m_chili;
        int m_tacos;
        int m_iceCream;
        int m_blueverries;
    public:

        EnergyStack();
        ~EnergyStack();

        void setChili(int val){m_chili = val}
        void setTacos(int val){m_tacos = val}
        void setIceCream(int val){m_iceCream = val}
        void setBlueberries(int val){m_blueverries = val}

        int getChili(){return m_chili }
        int getTacos(){return m_tacos }
        int getIceCream(){return m_iceCream }
        int getBlueberries(){return m_blueverries }

        void addEnergy(EnergyType eType, int quantity);
};
#endif
