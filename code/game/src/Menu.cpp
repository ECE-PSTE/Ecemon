#include "../include/Menu.h"

int menuChoice(std::vector<int> vectorChoice){
    std::string strChoice;
    int intChoice;

    std::cout << "\n\nChoice : ";
    getline(std::cin, strChoice);

    intChoice = Utils::toInt(strChoice);

    while(!menuChoiceGood(vectorChoice, intChoice)){
        std::cout << "Wrong entry.\nNew choice :";
        getline(std::cin, strChoice);
        intChoice = Utils::toInt(strChoice);
    }
    system(clearConsoleCmd);
    return intChoice;
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
    std::cout << "\n";
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

    std::cout << "\n\n\t1) Play a Game !"
    <<"\n\t2) Change admin mode"
    <<"\n\t3) Add Money Profile"
    <<"\n\t4) Change Profile Use"
    <<"\n\t5) Buy Cards"
    <<"\n\t6) Gestion Collection/Deck"
    <<"\n\t7) Exit Game\n";

    switch (menuChoice({1,2,3,4,5,6,7})) {
        case 1:
            lunchGame(data);
            return true;
            break;
        case 2:
            switchAdmin(data);
            return true;
            break;
        case 3:
            if(data->m_profileUse == NULL){
                std::cout << "\nImpossible : no profil select\n\n";
            }
            else if(!data->m_admin){
                std::cout << "\nImpossible : no admin mode\n\n";
            }
            else{
                int i;
                std::cout<< "How many money add : ";
                std::cin >> i;
                std::cin.ignore();
                data->m_profileUse->addMoney(i);
                std::cout<< "Done, new money on profile : "<< data->m_profileUse->getMoney() <<"\n";
            }
            return true;
            break;
        case 4:
            switchProfile(data);
            return true;
        case 5:
            if(data->m_profileUse == NULL){
                std::cout << "\nImpossible : no profil select";
            }
            else{
                while(buyCards(data)){
                }
            }
            return true;
            break;
        case 6:
            if(data->m_profileUse == NULL){
                std::cout << "\nImpossible : no profil select";
            }
            else{
                while(gestionCollection(data)){
                }
            }
            return true;
            break;
        case 7:
            std::cout << "End of Game, all data Save \n";
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

Profile* askProfileWithName(s_DataMenu* data, std::string name){
    for(auto & elem : *data->m_profileGame){
        if(elem.getName() == name){
            return &elem;
        }
    }
    return NULL;
}

bool buyCards(s_DataMenu* data){
    displayMenuFront(std::string("Shop of Card"));

    std::cout << "\n\nProfil use : " << data->m_profileUse->getName() << "\n\tMoney on user : " << data->m_profileUse->getMoney() << "\n\n"
    << "Price of a random card : " << Constants::DefaultRandomCardPrice() << "\n\n"
    << "\t1) Buy a Card \n\t2) Return";

    switch (menuChoice({2,1})) {
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
        case 2:
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

bool gestionCollection(s_DataMenu* data){
    displayMenuFront(std::string("Gestion Collection"));

    std::cout << "\n\nProfil use : " << data->m_profileUse->getName() << "\n\n"
    << "\t1) Display Collection \n\t2) Gestion Deck\n\t3) Return\n";

    switch (menuChoice({3,1,2})) {
        case 1:
            displayCollection(data->m_profileUse);
            return true;
            break;
        case 2:
            while(gestionDeck(data->m_profileUse)){
            }
            return true;
            break;
        case 3:
            return false;
            break;
        default:
            std::cout << "ERROR ENTER GESTUR COLLECTION MENU\n\n";
            return false;
    }

}

//A paufiner ....
void displayCollection(Profile* p){
    for(const auto & elem : p->getCards().getCards()){
        std::cout << "Id of Card : "<< elem->getId();
        switch (elem->type()) {
            case CardType_Energy:
                std::cout << "\nType of Card : Energy";
                break;
            case CardType_Power:
                std::cout << "\nType of Card : Power";
                break;
            case CardType_Creature:
                std::cout << "\nType of Card : Creature";
                break;
            default :
                std::cout<< "ERROR RECONIZE TYPE CARD DISPLAY IN DISPLAY COLLECTION\n";
        }
        std::cout << "\n\t" << elem->getName() << "\n\n\t" << elem->getDescription()
        << "\n\n\n";
    }
}

bool gestionDeck(Profile* p){
    displayMenuFront(std::string("Gestion Deck"));

    std::cout << "\n\nProfil use : " << p->getName() << "\n\nList of deck in profile : \n";
    displayDecks(p);
    std::cout << "\n\n\t1) Display Deck\n\t2) Modify Deck \n\t3) Creat Deck\n\t4) Delete Deck\n\t5) Return\n";

    switch (menuChoice({5,1,2,3,4})) {
        case 1:
            displayADeck(p);
            return true;
            break;
        case 2:
            modifyDeck(p);
            return true;
            break;
        case 3:
            createDeck(p);
            return true;
            break;
        case 4:
            deleteDeck(p);
            return true;
            break;
        case 5:
            return false;
            break;
        default:
            std::cout << "ERROR ENTER GESTUR COLLECTION MENU\n\n";
            return false;
    }

}

void displayDecks(Profile* p){
    for(const auto & elem : p->getDecks()){
        std::cout << "\t" << elem->getName();
        if(elem->isComplete()){
            std::cout << "\t\tCan be Play";
        }
        std::cout <<"\n";
    }
}

bool checkNameDeck(Profile* p , std::string name){
    for(const auto & elem : p->getDecks()){
        if(elem->getName() == name){
            return false;
        }
    }
    return true;
}

void createDeck(Profile* p){
    std::string name;

    std::cout << "Enter name of Deck : ";
    getline(std::cin, name);

    while(!checkNameDeck(p, name)){
        std::cout << "\nInvalid name, this was already take, other name : ";
        getline(std::cin, name);
    }

    Deck* newDeck;

    do{
        newDeck = new Deck(name);
    }while(newDeck == NULL);

    while(creatDeckInProgresse(p,newDeck)){}

    p->addDeck(newDeck);
}

bool creatDeckInProgresse(Profile* p, Deck* d){
    int nb;

    std::cout << "Numer of card in this Deck : " << d->getCards().size() << "\nNumber of card require to play : " << Constants::DefaultDeckSize() << "\n";

    std::cout << "\nCard in collection : \n";
    displayDeck(p->getpCards());
    std::cout << "Card in created Deck : \n";
    displayDeck(d);

    std::cout<<"\nEnter a Id positive to add the card and the Negative Id to delete the Card of Deck\n\tAnd 0 to stop and retrun menu\n\nNumber : ";
    std::cin >> nb;

    if(nb>0){
        for(int i = 0 ; i < p->getpCards()->getCards().size() ; i ++){
            if(p->getpCards()->getCards()[i]->getId() == nb){
                d->addCard(p->getpCards()->getCards()[i]);
                p->getpCards()->removeCard(p->getpCards()->getCards()[i]);
                system(clearConsoleCmd);
                std::cout << "Add Done\n\n";
                return true;
            }
        }
        system(clearConsoleCmd);
        std::cout << "No add of a no existing ID in collection\n\n";
        return true;
    }
    if(nb<0){
        nb *= -1;
        for(int i = 0 ; i < d->getCards().size() ; i ++){
            if(d->getCards()[i]->getId() == nb){
                p->getpCards()->addCard(d->getCards()[i]);
                d->removeCard(d->getCards()[i]);
                system(clearConsoleCmd);
                std::cout << "Delete Done\n\n";
                return true;
            }
        }
        system(clearConsoleCmd);
        std::cout << "No delete of a no existing ID in collection\n\n";
        return true;
    }
    system(clearConsoleCmd);
    std::cin.ignore();
    std::cout<< "Deck Save in your profile\n\n";

    return false;
}

void displayDeck(Deck* d){
    for(const auto & elem : d->getCards()){
        std::cout << "\t" << elem->getId() << "-  " << elem->getName() <<"\n";
    }
    std::cout << "\n";
}

void modifyDeck(Profile* p){
    std::string name;

    std::cout << "Profil use : " << p->getName() << "\n\nList of deck in profile : \n";
    displayDecks(p);

    std::cout << "\n\nEnter name of Deck : ";
    getline(std::cin, name);

    while(checkNameDeck(p, name)){
        std::cout << "\nInvalid name, this deck doesnt exist, other name : ";
        getline(std::cin, name);
    }

    for(auto & elem : p->getDecks()){
        if(elem->getName() == name){
            while(creatDeckInProgresse(p,elem)){}
            break;
        }
    }


}

void displayADeck(Profile* p){
    std::string name;

    std::cout << "Profil use : " << p->getName() << "\n\nList of deck in profile : \n";
    displayDecks(p);

    std::cout << "\n\nEnter name of Deck : ";
    getline(std::cin, name);

    while(checkNameDeck(p, name)){
        std::cout << "\nInvalid name, this deck doesnt exist, other name : ";
        getline(std::cin, name);
    }

    for(auto & elem : p->getDecks()){
        if(elem->getName() == name){
            displayDeck(elem);
            break;
        }
    }
    ;
}

void deleteDeck(Profile* p){
    std::string name;

    std::cout << "Profil use : " << p->getName() << "\n\nList of deck in profile : \n";
    displayDecks(p);

    std::cout << "\n\nEnter name of Deck to delete : ";
    getline(std::cin, name);

    while(checkNameDeck(p, name)){
        std::cout << "\nInvalid name, this deck doesnt exist, other name : ";
        getline(std::cin, name);
    }

    for(int i = 0; i < p->getpDecks()->size() ; i++){
        if(p->getDecks()[i]->getName() == name){
            emptyDeckIntoCollection(p, p->getDecks()[i]);
            p->getpDecks()->erase(p->getpDecks()->begin() + i);
            break;
        }
    }
}

void emptyDeckIntoCollection(Profile* p,Deck* d){
        p->getpCards()->addCards(d->getCards());
        delete d;
}

void lunchGame(s_DataMenu* data){
    std::string nameDeckP1;
    std::string nameDeckP2;

    Profile* profileP1 = NULL;
    Profile* profileP2 = NULL;

    loadProfileAndDeck(data, &profileP1, &nameDeckP1);
    loadProfileAndDeck(data, &profileP2, &nameDeckP2);

    if(profileP1 == profileP2 && nameDeckP1 == nameDeckP2){
        system(clearConsoleCmd);
        std::cout << "You can play with the same profile but it be must between two diffrent Deck\n";
    }
    else{
        system(clearConsoleCmd);
        std::cout << "Game in progress...\n";
        gameLoop(profileP1, nameDeckP1, profileP2, nameDeckP2);
        std::cout<< "End of game !\n\n";
    }

}

void loadProfileAndDeck(s_DataMenu* data, Profile** pPlay, std::string* nNameDeck){
    std::string nameProfile;
    *nNameDeck = "";

    std::cout << "Enter one of this profile's name : \n";
    for(auto & elem : *data->m_profileGame){
        std::cout << "\t- " << elem.getName() << "\n";
    }
    std::cout << "\nName of profile To play with: ";
    getline(std::cin, nameProfile);
    *pPlay  = askProfileWithName(data, nameProfile);
    while(*pPlay == NULL){
        std::cout << "\nThis profile name doesnt exist, enter a new name of profile To play with: ";
        getline(std::cin, nameProfile);
        *pPlay  = askProfileWithName(data, nameProfile);
    }

    std::cout << "This is the list of deck who can be play :\n";
    for(const auto & elem : (*pPlay)->getDecks()){
        std::cout << "\t" << elem->getName();
        if(elem->isComplete()){
            std::cout << "\t" << "Can Be Play";
        }
        std::cout <<"\n";
    }

    do{
        std::cout << "\nName of deck To play with: ";
        getline(std::cin, nameProfile);
        for(const auto & elem : (*pPlay)->getDecks()){
            if(!elem->isComplete() && elem->getName() == nameProfile){
                std::cout << "Deck is existe but not complet to be play in a game\n\n";
                break;
            }
            else if(elem->isComplete() && elem->getName() == nameProfile){
                *nNameDeck = nameProfile;
                std::cout << "Deck Found ! This player is ready\n\n";
                break;
            }
        }
    }while(*nNameDeck == "");
}
