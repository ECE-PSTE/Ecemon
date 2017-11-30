#include <iostream>

#include "include/Menu.h"
#include "../../utils/ProfileUtils.h"
#include <time.h>


int main(int argc, char const *argv[]) {

        srand(time(NULL));

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

        std::vector<Profile*> vecpProf;
        for(auto & elem : vecProf){
            vecpProf.push_back(&elem);
        }

        if(!ProfileUtils::saveProfiles(vecpProf)){
            std::cout << "Error saving vector profile\n\n";
        }


    return 0;
}
