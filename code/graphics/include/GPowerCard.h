#ifndef DEF_GPOWERCARD
#define DEF_GPOWERCARD

#include "GCard.h"
#include "../../entities/include/PowerCard.h"

class GPowerCard : public GCard {
    private:
        void update();

    public:
        GPowerCard();
        GPowerCard(const Card* card, sf::RenderWindow* window);

        void draw();
    };

#endif
