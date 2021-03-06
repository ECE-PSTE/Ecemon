#ifndef DEF_CARD
#define DEF_CARD

#include "Constants.h"
#include "../../utils/Utils.h"

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

        int getId() const;
        std::string getName() const;
        std::string getDescription() const;

        void setId(int id);
        void setName(std::string name);
        void setDescription(std::string description);

        friend std::ostream& operator<<(std::ostream& os, const Card& card);
        friend std::istream& operator>>(std::istream& is, Card& card);
};

#endif
