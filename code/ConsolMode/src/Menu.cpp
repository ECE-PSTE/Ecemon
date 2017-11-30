#include "../include/Menu.h"

int menuChoice(std::vector<int> vectorChoice){
    int choice;

    std::cout << "\n\nChoice : ";
    std::cin >> choice;

    while(!menuChoiceGood(vectorChoice, choice)){
        std::cout << "Wrong entry.\nNew choice :";
        std::cin >> choice;
    }
    system("cls");
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
    <<"\n\t4) Buy Cards"
    << "\n\t0) Exit Game\n"
    ;

    switch (menuChoice({0,1,2,3,4})) {
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
        case 4:
            if(data->m_profileUse == NULL){
                std::cout << "\nImpossible : no profil select";
            }
            else{
                while(buyCards(data)){
                    std::cout << "\n\n";
                }
            }
            return true;
            break;
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

bool buyCards(s_DataMenu* data){
    displayMenuFront(std::string("Shop of Card"));

    std::cout << "\n\nProfil use : " << data->m_profileUse->getName() << "\n\tMoney on user : " << data->m_profileUse->getMoney() << "\n\n"
    << "Price of a random card : " << Constants::DefaultRandomCardPrice() << "\n\n"
    << "\t1) Buy a Card \n\t0) Return";

    switch (menuChoice({0,1})) {
        case 1:
            if(buyCardsGood(data)){
                int i = Utils::getRand(1, GameUtils::Cards.size());
                data->m_profileUse->addMoney(-(Constants::DefaultRandomCardPrice()));
                data->m_profileUse->getpCards()->addCard(GameUtils::Cards.at(i));
                std::cout << "\n\nCard win :\n\tCard id : " << i << "\n\tCard name : " <<  GameUtils::Cards.at(i)->getName()
                << "\n\tDescription : " << GameUtils::Cards.at(i)->getDescription();

            }
            else{
                std::cout << "\n\nNo enought money sorry";
            }
            return true;
            break;
        case 0:
            return false;
            break;
        default:
            std::cout << "ERROR NUMBER CHOICE MENU STORE\n\n";
    }



}

bool buyCardsGood(s_DataMenu* data){
    if(data->m_profileUse->getMoney() >= Constants::DefaultRandomCardPrice()){
        return true;
    }
    return false;
}
