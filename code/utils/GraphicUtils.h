#ifndef DEF_GAME
#define DEF_GAME

#include <map>
#include <fstream>

#include "Utils.h"

namespace GraphicUtils {
    inline const std::map<int, std::string> loadCardImages(){
        std::map<int, std::string> images;
        std::ifstream file("CardImages"));
        if(file){
            std::string line;
            int nbCards;

            getline(file, line);
            nbCards = Utils::toInt(line);

            int id;
            for(int i=0 ; i<nbCards ; i++){
                getline(file, line);
                id = Utils::toInt(line);
                getline(file, line);
                images[id] = line;
            }
        }
        file.close();
        return images;
    }

    const std::map<int, std::string> CardImages = loadCardImages();
};

#endif
