#include <iostream>

#include "include/Menu.h"

int main(int argc, char const *argv[]) {

    Menu m1;

    do{
        m1.displayMenu();
    }while(m1.switchMenu());

    return 0;
}
