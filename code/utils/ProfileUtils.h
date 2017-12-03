#ifndef DEF_PROFILEUTILS
#define DEF_PROFILEUTILS

#include <fstream>
#include "../entities/include/Profile.h"
#include "../entities/include/Constants.h"
#include "Utils.h"

namespace ProfileUtils {
    static bool saveProfile(const char *filename, Profile &profile){
        std::ofstream file(filename);
        if(file){
            file << profile;
            file.close();
            return true;
        }
        return false;
    }

    static bool loadProfile(const char *filename, Profile &profile){
        std::ifstream file(filename);
        if(file){
            file >> profile;
            file.close();
            return true;
        }
        return false;
    }

    static bool saveProfiles(std::vector<Profile*> &profiles){
        std::ofstream file(Constants::DefaultProfilesFilename().c_str());
        if(file){
            int length = profiles.size();
            file << length << std::endl;
            for(int i=0 ; i<length ; i++){
                file << *profiles[i];
                if(i!=length-1){
                    file << std::endl;
                }
            }
            file.close();
            return true;
        }
        return false;
    }

    static bool loadProfiles(std::vector<Profile> &profiles){
        std::ifstream file(Constants::DefaultProfilesFilename().c_str());
        if(file){
            std::string line;
            getline(file, line);
            int length = Utils::toInt(line);
            profiles.resize(length);
            for(int i=0 ; i<length ; i++){
                file >> profiles[i];
            }
            file.close();
            return true;
        }
        return false;
    }
}

#endif
