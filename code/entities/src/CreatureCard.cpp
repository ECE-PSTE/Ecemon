#include "../include/CreatureCard.h"

CreatureCard::CreatureCard(){
    m_life = Constants::DefaultCreatureLife();
}

CreatureCard::CreatureCard(int id){
    m_id = id;
    m_life = Constants::DefaultCreatureLife();
}

CreatureCard::~CreatureCard(){
}

void CreatureCard::writeCard(std::ostream &os) const{
    Card::writeCard(os);
    os << m_life << std::endl;
    os << m_attacks.size() << std::endl;
    for(auto attack : m_attacks){
        os << attack << std::endl;
    }
}

void CreatureCard::readCard(std::istream &is){
    Card::readCard(is);
    std::string line;
    getline(is, line);
    m_life = Utils::toInt(line);
    getline(is, line);
    int length = Utils::toInt(line);
    Attack attack;
    for(int i=0 ; i<length ; i++){
        is >> attack;
        m_attacks.push_back(attack);
    }
}

CardType CreatureCard::type() const{
    return CardType_Creature;
}

int CreatureCard::getLife() const{
    return m_life;
}

std::vector<Attack> CreatureCard::getAttacks() const{
    return m_attacks;
}

void CreatureCard::setLife(int life){
    m_life = life;
}

void CreatureCard::addAttack(Attack attack){
    m_attacks.push_back(attack);
}
