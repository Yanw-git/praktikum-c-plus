/**
 * @file player.cpp
 */

#include "player.h"

Player::Player(Deck* d) : deck(d)
{}

size_t Player::getHandValue() const    //accuculate sum
{
    // TODO: Add code here
    size_t sum = 0;
    for (size_t i = 0;i < cards.size();++i)
    {//std::cout<<cards[i]<<std::endl;
        sum += cards[i];
    }
    // Dummy return:
    return sum;
}

bool Player::isBust() const
{
    // TODO: Add code here
    size_t karte_sum = getHandValue();
    if (karte_sum > 21)
        // Dummy return:
        return true;
}

bool Player::hasBlackjack() const
{
    // TODO: Add code here
    size_t kartesum = getHandValue();
    if (cards.size() == 2 && kartesum == 21)
        // Dummy return:
        return true;
}

bool Player::devaluateAce()
{
    // TODO: Add code here
    std::vector<size_t>::iterator Ace;
    Ace = find(cards.begin(), cards.end(), 11);
    if (Ace != cards.end()) //find 11!
    {
        *Ace = 1;
        return true;
    }
    else
        // Dummy return:
        return false;
}

void Player::takeHit()
{
    // TODO: Add code here
    cards.push_back(deck->getRandomCard());
    while (this->isBust())    //cards sum>21
    {
        devaluateAce();     // have A 
        if (!devaluateAce()) //in cards have no A, do nothing exit
            break;
    }

}

void Player::playTurn()
{
    while (!this->isBust() && this->evaluateHand())
        this->takeHit();
}

void Player::resetHand()
{
    this->cards.clear();
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << player.getHandValue();
    os << " (";
    for (size_t card : player.cards)
        os << " " << card;
    os << " " << ")";
    return os;
}

std::unique_ptr<Player> Player::create(PlayerType type, Deck* deck)
{
    // TODO: Implement this factory method
if (type== PlayerType::automated) return std::make_unique<AutomatedPlayer>(deck);
    else if (type == PlayerType::manual) return std::make_unique<ManualPlayer>(deck);
    else {
        std::cout << "No such player type" << std::endl;
    // Dummy return:
    return nullptr;
    }
}

// TODO: Implement the evaluateHand method for both AutomatedPlayer and ManualPlayer
bool AutomatedPlayer::evaluateHand() 
{
    if (this->getHandValue() < 17)       //abgeleitete class verwendet basis methode
    {
        deck1->getRandomCard();
        return true;
    }
    else
        return false;
}

bool ManualPlayer::evaluateHand() 
{
    std::cout << "Your Hand: " << * this << std::endl;
    std::string drawCard = "y";
    std::cout << "another card? (y/n)" << std::endl;
    std::cin >> drawCard;
    return drawCard == "y";
}
