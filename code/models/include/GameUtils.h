#ifndef DEF_GAMEUTILS
#define DEF_GAMEUTILS

#include <vector>
#include <fstream>

#include "Game.h"
#include "../../entities/include/Profile.h"

namespace GameUtils {
    bool SaveProfile(const char *filename, Profile &profile){
        std::ofstream file(filename);
        if(file){
            file << profile;
            file.close();
            return true;
        }
        return false;
    }

    bool LoadProfile(const char *filename, Profile &profile){
        std::ifstream file(filename);
        if(file){
            file >> profile;
            file.close();
            return true;
        }
        return false;
    }

    bool AddCardToGame(Card *card){
        std::ofstream file(Constants::DefaultCardsFilename().c_str(), std::ios::app);
        if(file){
            file << card->type() << std::endl;
            card->writeCard(file);
            file.close();
            return true;
        }
        else{
            return false;
        }
    }

    std::vector<const Card*> CardsVector(){
        std::vector<const Card*> cards;
        for(auto it : Game::Cards){
            cards.push_back(it.second);
        }
        return cards;
    }

    void FreeCards(){
        for(auto it : Game::Cards){
            delete it.second;
        }
    }
};


#endif
