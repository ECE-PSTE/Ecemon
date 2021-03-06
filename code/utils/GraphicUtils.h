#ifndef DEF_GRAPHICUTILS
#define DEF_GRAPHICUTILS

#include <map>
#include <fstream>

#include "Utils.h"
#include "../entities/include/Constants.h"

namespace GraphicUtils {
    static const std::map<int, std::string> loadCardImages(){
        std::map<int, std::string> images;
        std::ifstream file(Constants::DefaultCardImagesFilename().c_str());
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
        else{
            std::cout << "Could not open file : " << Constants::DefaultCardImagesFilename() << std::endl;
        }
        file.close();
        return images;
    }

    const std::map<int, std::string> CardImages = loadCardImages();
};

#endif
