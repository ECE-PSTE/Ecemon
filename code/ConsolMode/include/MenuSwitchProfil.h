#include "Menu.h"

class MenuSwitchProfil : public Menu{

    private:
        /* data */

    public:
        MenuSwitchProfil(Profil* profileUSe, bool admin);
        virtual ~MenuSwitchProfil();

        void switchProfil();

        void displayMenu();

        bool switchMenu();
};
