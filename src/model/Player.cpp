/**
 * @author John S. Anvik <j.anvik@uleth.ca>
 * @date Spring 2025
*/

#include "../../include/model/Player.hpp"

Player::Player(const std::string& name) : name(name), score(0), hit(false) {}

void Player::addCard(Card* card) {
    hand.push_back(card);
}

std::vector<Card*> Player::getHand() {
    return hand;
}

int Player::updateScore() {
    score = 0;
    for (int i = 0; i < hand.size(); ++i) {
        score += hand[i]->getValue();
    }
    return score;
}

int Player::getScore() {
    return score;
}

std::string Player::getName() {
    return name;
}

// bool Player::getHitState() {
//     return hit;
// }

// bool Player::setHitState(bool hit_state) {
//     hit = hit_state;
//     return hit;
// }

void Player::clearHand() {
    for (Card* card : hand) {
        delete card;
    }
    hand.clear();
    score = 0;
}
