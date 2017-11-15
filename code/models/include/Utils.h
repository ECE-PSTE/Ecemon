#ifndef DEF_UTILS
#define DEF_UTILS

#include <vector>
#include <fstream>

#include "../../entities/include/Game.h"
#include "../../entities/include/Profile.h"
#include "../../entities/include/Constants.h"

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
        for(auto it : Game::Cards){
            cards.push_back(it.second);
        }
        return cards;
    }

    void deleteAllCards(){
        for(auto it : Game::Cards){
            delete it.second;
        }
    }
};


#endif
