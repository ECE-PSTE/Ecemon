#ifndef DEF_UTILS
#define DEF_UTILS

#include <ctime>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

namespace Utils {
    inline void initRand(){
        srand(time(NULL));
    }

    inline int getRand(int min, int max){
        return min + rand()%(max - min + 1);
    }

    inline int toInt(std::string s){
        std::stringstream ss(s);
        int n;
        ss >> n;
        return n;
    }
}

#endif
