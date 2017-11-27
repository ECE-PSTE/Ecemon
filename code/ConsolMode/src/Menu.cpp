#include "../include/Menu.h"

Menu::Menu(): m_profileUse(NULL), m_admin(false){
    //https://www.youtube.com/watch?v=dQw4w9WgXcQ
}

Menu::~Menu(){
    //https://www.youtube.com/watch?v=dv13gl0a-FA
}

bool Menu::switchAdminOn(std::string password){
    if(Constants::DefaultPasswordAdmin() == password){
        setAdmin(true);
        return true;
    }

    return false;
}

void Menu::switchAdmin(){
    if(getAdmin()){
        setAdmin(false);
    }
    else{
        std::string mdp;

        std::cout << "Password please : ";
        getline(std::cin, mdp);
        if(switchAdminOn(mdp)){
            std::cout<<"Succes, you are admin now !\n\n";
        }
        else{
            std::cout << "Wrong password... nice try !\n\n";
        }
    }
}

void Menu::displayMenu(){
    for(int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout<<"\n\n\t\tPrincipal Menu\n\n";
    for(int i = 0; i < 50; i++)
        std::cout << "#";
}
