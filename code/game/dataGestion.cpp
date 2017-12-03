#include <iostream>
#include <time.h>

#include "include/Menu.h"
#include "../../utils/ProfileUtils.h"
#include "../../utils/GameUtils.h"

void carteajout(Card* p){
    std::string name;
    std::string descritpion;
    int id;

    std::cout << "Nom : ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "Id : ";
    std::cin >> id;
    std::cout << "Decription : ";
    std::cin.ignore();
    getline(std::cin, descritpion);

    p->setId(id);
    p->setName(name);
    p->setDescription(descritpion);
}

void pouvoirajout(Card* e){
    carteajout(e);
    PowerCard* p = (PowerCard*)e;

    int stats;
    int powerType;

    std::cout << "Stats de la carte (0 si rien) : ";
    std::cin >> stats;

    std::cout << "Type de pouvoir de la carte : ";
    std::cin >> powerType;

    p->setStats(stats);
    p->setPowerType((PowerType) powerType);
}

void energyajout(Card* e){
    carteajout(e);
    EnergyCard* p = (EnergyCard*)e;

    int stats;
    int energyType;

    std::cout << "Combien d energy apporter : ";
    std::cin >> stats;

    std::cout << "Type de energy de la carte : ";
    std::cin >> energyType;

    p->setEnergy(stats);
    p->setEnergyType((EnergyType) energyType);
}



void creaturerajout(Card* e){
    carteajout(e);
    CreatureCard* p = (CreatureCard*)e;

    int life;
    std::cout << "Point de vie de la creature : ";
    std::cin >> life;

    p->setLife(life);

    for(int i = 0 ; i < 2 ; i++){
        std::string nameatt;
        std::string descriptionatt;
        int cost;
        int damage;
        int typeatt;
        Attack att;

        std::cout << "Nom attaque " << i << " : ";
        std::cin.ignore();
        getline(std::cin, nameatt);
        std::cout << "Descirption attaque " << i << " : ";
        getline(std::cin, descriptionatt);
        std::cout << "Damage attaque " << i << " : ";
        std::cin >> damage;

        att.setName(nameatt);
        att.setDescription(descriptionatt);
        att.setDamage(damage);

        if(i == 0){
            att.setCost(0);
            att.setAttackType(EnergyType_Neutral);
        }
        else{
            std::cout << "Cout attaque 1 : ";
            std::cin >> cost;
            std::cout << "Type Energy :";
            std::cin >> typeatt;

            att.setCost(cost);
            att.setAttackType((EnergyType) typeatt);
        }
        p->addAttack(att);
    }
}


int main(int argc, char const *argv[]){
    Card* p;
    int choix = 0;

    system("cls");
    std::cout << "Wich type of card to Add\n1)Creature\n2)Power\n3)Energy\n0)End\nChoice :";
    std::cin >> choix;

    switch (choix) {
        case 1:
            p = new CreatureCard();
            creaturerajout(p);
            break;
        case 2:
            p = new PowerCard();
            pouvoirajout(p);
            break;
        case 3:
            p = new EnergyCard();
            energyajout(p);
            break;
        case 0:
            std::cout << "Dommage\n\n";
            break;
        default :
        std::cout << "fail";
    }
    if(choix !=0){
        GameUtils::addCardToGame(p);
    }


    GameUtils::freeCards();

    return 0;
}
