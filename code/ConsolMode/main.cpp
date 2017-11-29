#include <iostream>

#include "include/Menu.h"
#include "../../utils/ProfileUtils.h"

int main(int argc, char const *argv[]) {

        s_DataMenu data;

        std::vector<Profile> vecProf;

        if(!ProfileUtils::loadProfiles(vecProf)){
            std::cout << "Error loading vector profile\n\n";
        }

        data.m_profileGame = &vecProf;
        data.m_profileUse = &vecProf[1];
        data.m_admin = false;

        while(menuPrincipal(&data)){
            std::cout << "\n\n\n\n";
        }

        if(!ProfileUtils::saveProfiles(vecProf)){
            std::cout << "Error saving vector profile\n\n";
        }


    return 0;
}
