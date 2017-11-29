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
    system("cls");
    for(int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout<<"\n\n\t\tPrincipal Menu\n\n";
    for(int i = 0; i < 50; i++)
        std::cout << "#";

    std::cout << "\n\nAdmin mode : " << m_admin;

    std::cout << "\n\n\t1) Switch Mode Admin\n\n\t2) Switch Profile Use\n\n\t0) Quit Console Mode\n\nChoice :";
}

bool Menu::switchMenu(){

    int choice;

    std::cin >> choice;
    std::cin.ignore();

    while(choice != 1 && choice != 0){
        std::cout << "Wrong type\nNew Choice : ";
        std::cin >> choice;
    }

    switch (choice) {
        case 1:
            switchAdmin();
            break;
        case 2:
            MenuSwitchProfil m1(m_profileUse, m_admin);
            do{
                m1.displayMenu();
            }while(m1.switchMenu());
            m_profileUse = m1.getProfile();
            break;
        case 0:
            return false;
            break;
        default:
            std::cout << "ERROR SWITCH CHOICE MENU\n\n";
    }

    return true;
}
