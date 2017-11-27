#ifndef DEF_ENERGYSTACK
#define DEF_ENERGYSTACK

#include <iostream>

#include "../../entities/include/EnergyType.h"

class EnergyStack{
    private:
        int m_chili = 0;
        int m_tacos = 0;
        int m_iceCream = 0;
        int m_blueberries = 0;

        void (*m_listenerEnergyStack)(EnergyStack*);

    public:



        EnergyStack();
        ~EnergyStack();

        void setChili(int val){m_chili = val;}
        void setTacos(int val){m_tacos = val;}
        void setIceCream(int val){m_iceCream = val;}
        void setBlueberries(int val){m_blueberries = val;}

        void setListenerEnergyStack(void (*listener) (EnergyStack*)){m_listenerEnergyStack = listener;}

        int getChili() const{return m_chili ;}
        int getTacos() const{return m_tacos ;}
        int getIceCream() const{return m_iceCream ;}
        int getBlueberries() const{return m_blueberries ;}

        void addEnergy(EnergyType eType, int quantity);
};
#endif
