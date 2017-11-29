#ifndef DEF_MENU
#define DEF_MENU

#include "../../entities/include/Profile.h"
#include "../../utils/ProfileUtils.h"

typedef struct dataMenu{
    Profile* m_profileUse;
    std::vector<Profile>* m_profileGame;
    bool m_admin;
}s_DataMenu;

int menuChoice(std::vector<int> vectorChoice);

bool menuChoiceGood(std::vector<int> vectorChoice, int lol);

void displayMenuFront(std::string nameMenu);

bool menuPrincipal(s_DataMenu* data);

void switchAdmin(s_DataMenu* data);

void switchProfile(s_DataMenu* data);

bool switchProfileGood(s_DataMenu* data, std::string name);



#endif
