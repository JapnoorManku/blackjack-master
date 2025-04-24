/**
* @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
* @date Feb 15, 2025
*/

#include <algorithm>
#include "../../include/model/Hand.hpp"

Hand::Hand() : currentlyActive(true) {}

std::vector<Card*> Hand::getCards() {
    return cards;
}

void Hand::addCard(Card *card) {
    cards.push_back(card);
}

int Hand::getValue() {
    int value = 0;
    int aceCount = 0;

    for (Card* card : cards) {
        switch (card->rank) {
            case Card::ACE:
                aceCount++;
                value += 11;
                break;
            case Card::TWO: case Card::THREE: case Card::FOUR: case Card::FIVE:
            case Card::SIX: case Card::SEVEN: case Card::EIGHT: case Card::NINE:
                value += (card->rank + 1);
                break;
            case Card::TEN: case Card::JACK: case Card::QUEEN: case Card::KING:
                value += 10;
                break;
        }
    }

    while (value > 21 && aceCount > 0) {
        value -= 10;
        aceCount--;
    }

    return value;
}

// void Hand::removeCard() {
//     if (!cards.empty()) {
//         cards.erase(cards.begin());
//     }
// }

// void Hand::setActive(bool active) {
//     currentlyActive = active;
// }

// bool Hand::isActive() {
//     return currentlyActive;
// }
