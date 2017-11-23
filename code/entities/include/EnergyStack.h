#ifndef DEF_ENERGYSTACK
#define DEF_ENERGYSTACK

#include <iostream>

#include "../../entities/include/EnergyType.h"

class EnergyStack{
    private:
        int m_chili = 0;
        int m_tacos = 0;
        int m_iceCream = 0;
        int m_blueverries = 0;
    public:

        EnergyStack();
        ~EnergyStack();

        void setChili(int val){m_chili = val;}
        void setTacos(int val){m_tacos = val;}
        void setIceCream(int val){m_iceCream = val;}
        void setBlueberries(int val){m_blueverries = val;}

        int getChili() const{return m_chili ;}
        int getTacos() const{return m_tacos ;}
        int getIceCream() const{return m_iceCream ;}
        int getBlueberries() const{return m_blueverries ;}

        void addEnergy(EnergyType eType, int quantity);
};
#endif
