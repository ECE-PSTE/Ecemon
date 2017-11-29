#include "../include/MenuSwitchProfil.h"

MenuSwitchProfil::MenuSwitchProfil(Profil* profileUSe, bool admin): m_profileUse(profileUSe), m_admin(admin){
    //https://www.youtube.com/watch?v=dQw4w9WgXcQ
}

MenuSwitchProfil::~MenuSwitchProfil(){
    //https://www.youtube.com/watch?v=dv13gl0a-FA
}

void MenuSwitchProfil::displayMenu(){
    system("cls");
    for(int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout<<"\n\n\t\tSwitch Profil Menu\n\n";
    for(int i = 0; i < 50; i++)
        std::cout << "#";

    std::cout << "\n\nAdmin mode : " << m_admin;

    std::cout << "\n\n\t1) Switch Profil\n\n\t2) Switch Admin\n\n\t0) Return\n\nChoice :";
}

bool MenuSwitchProfil::switchMenu(){

    int choice;

    std::cin >> choice;
    std::cin.ignore();

    while(choice != 1 && choice != 0){
        std::cout << "Wrong type\nNew Choice : ";
        std::cin >> choice;
    }

    switch (choice) {
        case 1:
            switchProfil();
            break;
        case 2:
            switchAdmin();
            break;
        case 0:
            return false;
            break;
        default:
            std::cout << "ERROR SWITCH CHOICE MENUSWITCHPROFIL\n\n";
    }

    return true;
}
