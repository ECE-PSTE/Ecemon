#include <iostream>

#include "include\Deck.h"
#include "src\Deck.cpp"

#include "include\Card.h"
#include "src\Card.cpp"

#include "include\Profil.h"
#include "src\Profil.cpp"

#include "include\EnergyCard.h"
#include "src\EnergyCard.cpp"


#include "include\Sauvegarde.h"
#include "src\Sauvegarde.cpp"


int main(int argc, char const *argv[]) {

    Sauvegarde sauv1 = Sauvegarde();

    sauv1.saveSauvegarde();

    return 0;
}
