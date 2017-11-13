#ifndef DEF_UTILS
#define DEF_UTILS

#include <vector>
#include <fstream>

#include "../../entities/include/Constants.h"
#include "../../entities/include/Profile.h"

namespace Utils{
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

    std::vector<const Card*> getAllCards(){
        std::vector<const Card*> cards;
        for(auto it : CARDS){
            cards.push_back(it.second);
        }
        return cards;
    }

    void deleteAllCards(){
        for(auto it : CARDS){
            delete it.second;
        }
    }
};


#endif
