#include <iostream>
#include <time.h>

#include "include/Menu.h"
#include "../../utils/ProfileUtils.h"
#include "../Socket/lib/SocketClient.h"

int main(int argc, char const *argv[]) {
        srand(time(NULL));

        s_DataMenu data;

        std::vector<Profile> vecProf;

        if(!ProfileUtils::loadProfiles(vecProf)){
            std::cout << "Error loading vector profile\n\n";
        }

        data.m_profileGame = &vecProf;
        data.m_profileUse = &vecProf[0];
        data.m_admin = false;

        while(menuPrincipal(&data));

        std::vector<Profile*> vecpProf;
        for(auto & elem : vecProf){
            vecpProf.push_back(&elem);
        }

        if(!ProfileUtils::saveProfiles(vecpProf)){
            std::cout << "Error saving vector profile\n\n";
        }

        GameUtils::freeCards();

    return 0;
}
