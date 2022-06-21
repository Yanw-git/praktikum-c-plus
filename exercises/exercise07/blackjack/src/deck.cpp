/**
 * @file deck.cpp
 */

#include "deck.h"
#include <iostream>

std::mt19937 Deck::re(std::random_device{}());  //initialition static Variabemember: Datentype Class::variable=...

void Deck::fill(size_t packs)
{
    this->cards.reserve(52 * packs);
    for (size_t i = 0; i < 4 * packs; ++i)
    {
        // Add numbered cards and aces:  //2~11:1-10,A 
        for (size_t i = 2; i < 12; ++i)
            this->cards.push_back(i);
        // Add face cards except aces:   //JQK(10)
        for (size_t i = 0; i < 3; ++i)
            this->cards.push_back(10);
    }
}

InfiniteDeck::InfiniteDeck()
{
    this->fill(1);
    this->dist = std::uniform_int_distribution<size_t> (0, this->cards.size() - 1);   //dist initialierung way
}

size_t InfiniteDeck::getRandomCard()
{    
    auto idx = this->dist(this->re);
    return this->cards[idx];
}

// TODO: Complete the following constructor
LimitedDeck::LimitedDeck(size_t d)
{
	Deck::fill(d);
	std::shuffle (cards.begin(), cards.end(), re);
}

size_t LimitedDeck::getRandomCard()
{
    // TODO: Add code here
  size_t last_card=cards.back();
   cards.pop_back();
   // Dummy return:
    return last_card;
}

void LimitedDeck::resetCards()
{
    // TODO: Add code here
    while(1)
    {
     discarded.push_back(getRandomCard());
    }
    std::vector<size_t>::iterator iter;
    for(iter=discarded.begin();iter!=discarded.end();++iter)
    {
        cards.push_back(*iter);     
    } 
    std::shuffle (cards.begin(), cards.end(), re);   
    discarded.clear();
}
