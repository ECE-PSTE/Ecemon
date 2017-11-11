#ifndef DEF_CARD
#define DEF_CARD

#include <string>
#include "CardType.h"

class Card {
    protected:
        int m_id;
        CardType m_cardType;
        std::string m_name;
        std::string m_description;

    public:
        Card();
        virtual ~Card();

        int getId();
        CardType getCardType();
        std::string getName();
        std::string getDescription();

        void setId(int id);
        void setCardType(CardType type);
        void setName(std::string name);
        void setDescription(std::string description);
};

#endif
