#ifndef DEF_MENU
#define DEF_MENU

#include "../../entities/include/Profile.h"
#include "../../utils/ProfileUtils.h"
#include "../src/game.cpp"
#include "../src/gameMulti.cpp"

static const char* clearConsoleCmd = "clear";

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

bool buyCards(s_DataMenu* data);

bool buyCardsGood(s_DataMenu* data);

bool gestionCollection(s_DataMenu* data);

void displayCollection(Profile* p);

bool gestionDeck(Profile* p);

void displayDecks(Profile* p);

void createDeck(Profile* p);

bool creatDeckInProgresse(Profile* p, Deck* d);

bool checkNameDeck(Profile* p , std::string name);

void displayDeck(Deck* d);

void modifyDeck(Profile* p);

void displayADeck(Profile* p);

void deleteDeck(Profile* p);

void emptyDeckIntoCollection(Profile* p,Deck* d);

void lunchGame(s_DataMenu* data);

void launchMultiplayerGame(s_DataMenu* data);

void loadProfileAndDeck(s_DataMenu* data, Profile** pPlay, std::string* nNameDeck);

Profile* askProfileWithName(s_DataMenu* data, std::string name);



#endif
