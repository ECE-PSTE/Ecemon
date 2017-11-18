#ifndef DEF_UTILS
#define DEF_UTILS

#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <cstdlib>

namespace Utils {
    inline void initRand(){
        srand(time(NULL));
    }

    inline int getRand(int min, int max){
        return min + rand()%(max - min + 1);
    }
}

#endif
