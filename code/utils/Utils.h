#ifndef DEF_UTILS
#define DEF_UTILS

#include <ctime>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

namespace Utils {
    static void initRand(){
        srand(time(NULL));
    }

    static int getRand(int min, int max){
        return min + rand()%(max - min + 1);
    }

    static int toInt(std::string s){
        std::stringstream ss(s);
        int n;
        ss >> n;
        return n;
    }

    static std::string toString(int n){
        std::stringstream ss;
        ss << n;
        return ss.str();
    }

    static bool fileToString(const char* filename, std::string &str){
        std::ifstream file(filename);
        if(file){
            std::string line;
            std::stringstream ss;
            while(!file.eof()){
                getline(file, line);
                ss << line << std::endl;
            }
            str = ss.str();
            file.close();
            return true;
        }
        return false;
    }
}

#endif
