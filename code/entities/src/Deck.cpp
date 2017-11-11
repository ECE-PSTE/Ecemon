#include "../include/Deck.h"

Deck::Deck() : m_nom("Deck Default")
{
}

Deck::Deck(std::string nom) : m_nom(nom)
{
}

Deck::~Deck()
{
}

bool Deck::complet()
{
  if(getpVecteurIdCardDeck()->size() == NB_CARD_DECK)
  {
    return true;
  }

  return false;
}
