#ifndef DEF_GPOWERCARD
#define DEF_GPOWERCARD

#include "GCard.h"
#include "../../entities/include/PowerCard.h"

class GPowerCard : public GCard {
    private:
        void update();

    public:
        GPowerCard();
        GPowerCard(sf::RenderWindow *window, sf::Vector2f size, const Card *card);

        void draw();
    };

#endif
