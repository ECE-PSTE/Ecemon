#ifndef DEF_PROFILEUTILS
#define DEF_PROFILEUTILS

#include <fstream>
#include "../entities/include/Profile.h"

namespace ProfileUtils {
    bool saveProfile(const char *filename, Profile &profile){
        std::ofstream file(filename);
        if(file){
            file << profile;
            file.close();
            return true;
        }
        return false;
    }

    bool loadProfile(const char *filename, Profile &profile){
        std::ifstream file(filename);
        if(file){
            file >> profile;
            file.close();
            return true;
        }
        return false;
    }
}

#endif
