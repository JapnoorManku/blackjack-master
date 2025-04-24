#include "../../include/model/Card.hpp"

const std::vector<std::string> rankNames = {
    "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN",
    "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"
};

const std::vector<std::string> suitNames = {
    "CLUB", "DIAMOND", "SPADE", "HEART"
};

std::string Card::getRank(Card::Rank r) {
    return rankNames.at(r);
}

std::string Card::getSuit(Card::Suit s) {
    return suitNames.at(s);
}

int Card::getValue() {
    return (rank >= TEN) ? 10 : rank + 1;
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    return os << rankNames.at(c.rank) << " of " << suitNames.at(c.suit);
}
bool Card::operator==(const Card& other) const {
    return (this->rank == other.rank && this->suit == other.suit);
}

// void Card::someFunction() {
//     // Implementation here
// }
