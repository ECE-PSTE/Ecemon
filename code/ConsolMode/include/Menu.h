#ifndef DEF_MENU
#define DEF_MENU

#include "../../entities/include/Profile.h"

class Menu {
    private:
        Profile* m_profileUse;
        bool m_admin;

        void setAdmin(bool val){m_admin = val;};
        bool switchAdminOn(std::string password);

    public:
        Menu();
        virtual ~Menu ();

        Profile* getProfile() const {return m_profileUse;}
        bool getAdmin() const {return m_admin;}

        void setProfileUse(Profile* val){m_profileUse = val} 

        virtual void displayMenu();

        virtual bool switchMenu();

        void switchAdmin();
};


#endif
