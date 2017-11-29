#include "../include/Menu.h"

int menuChoice(std::vector<int> vectorChoice){
    int choice;

    std::cout << "\n\nChoice : ";
    std::cin >> choice;

    while(!menuChoiceGood(vectorChoice, choice)){
        std::cout << "Wrong entry.\nNew choice :";
        std::cin >> choice;
    }
    return choice;
}

bool menuChoiceGood(std::vector<int> vectorChoice, int lol){
    for(const auto & elem : vectorChoice){
        if(elem == lol){
            return true;
        }
    }

    return false;
}

void displayMenuFront(std::string nameMenu){
    for(int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout << "\n\t\t"<< nameMenu << "\n";
    for(int i = 0; i < 50; i++)
        std::cout << "#";
    std::cout<<"\n\n";
}

bool menuPrincipal(s_DataMenu* data){
    displayMenuFront(std::string("Menu Principal"));

    std::cout << "\nAdmin mode : " << data->m_admin << "\nProfile in progress : ";
    if(data->m_profileUse != NULL){
        std::cout << data->m_profileUse->getName();
    }

    std::cout << "\n\n\t1) Change admin mode"
    <<"\n\t2) Add Money Profile"
    <<"\n\t3) Change Profile Use"
    << "\n\t0) Exit Game\n"
    ;

    switch (menuChoice({0,1,2,3})) {
        case 1:
            switchAdmin(data);
            return true;
            break;
        case 2:
            if(data->m_profileUse == NULL){
                std::cout << "\nImpossible : no profil select";
            }
            else if(!data->m_admin){
                std::cout << "\nImpossible : no admin mode";
            }
            else{
                int i;
                std::cout<< "How many money add : ";
                std::cin >> i;
                data->m_profileUse->addMoney(i);
                std::cout<< "Done, new money on profile : "<< data->m_profileUse->getMoney() <<"\n";
            }
            return true;
            break;
        case 3:
            switchProfile(data);
            return true;
        case 0:
            return false;
            break;
        default :
            std::cout << "ERROR ENTER MENU PRINCIPAL\n\n";
            return false;
    }

}

void switchAdmin(s_DataMenu* data){

    if(data->m_admin){
        data->m_admin = false;
        std::cout << "Admin mode switch succes\n";
    }
    else{
        std::string pass;
        std::cout<< "\nEnter the password : ";
        std::cin.ignore();
        getline(std::cin, pass);

        if(pass == Constants::DefaultPasswordAdmin()){
            data->m_admin = true;
            std::cout << "Admin mode switch succes\n";
        }
        else{
            std::cout << "Wrong Password\n\n";
        }
    }
}

void switchProfile(s_DataMenu* data){
    std::string nameP;

    std::cout<< "\n\nThis is the list of profile :\n\n";
    for(auto & elem : *data->m_profileGame){
        std::cout << "\t" << elem.getName() << "\n";
    }

    std::cout << "\nName of profile to use : ";
    std::cin.ignore();
    getline(std::cin, nameP);

    if(switchProfileGood(data, nameP)){
        std::cout << "Changement Succes \n";
    }
    else{
        std::cout<< "Invalide name of profile\n";
    }
}

bool switchProfileGood(s_DataMenu* data, std::string name){
    for(auto & elem : *data->m_profileGame){
        if(elem.getName() == name){
            data->m_profileUse = &elem;
            return true;
        }
    }

    return false;
}
