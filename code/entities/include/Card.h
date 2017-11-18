#ifndef DEF_CARD
#define DEF_CARD

#include <string>
#include <iostream>
#include <cstdlib>

#include "Constants.h"

class Card {
    protected:
        int m_id;
        std::string m_name;
        std::string m_description;

    public:
        Card();
        Card(const Card &card);
        virtual ~Card();

        virtual void writeCard(std::ostream &os) const;
        virtual void readCard(std::istream &is);
        virtual CardType type() const;

        int getId();
        std::string getName();
        std::string getDescription();

        void setId(int id);
        void setName(std::string name);
        void setDescription(std::string description);

        friend std::ostream& operator<<(std::ostream& os, const Card& card);
        friend std::istream& operator>>(std::istream& is, Card& card);
};

#endif
