#include <algorithm>
#include <random>
#include "../../include/model/Deck.hpp"

Deck::Deck() {
    reset();
}

Deck::~Deck() {
    for (auto card : cards) {
      delete card;
  }
  cards.clear();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card* Deck::dealCard() {
    if (cards.empty()) {
        return nullptr;
    }
    Card* dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

unsigned Deck::size() {
    return cards.size();
}

void Deck::addCard(Card* card) {
    cards.push_back(card);
}

void Deck::reset() {
    for (int i = 0; i < cards.size(); i++) {
      delete cards[i];
    }
  cards.clear();
  for (int suit = 0; suit < 4; ++suit) {
    for (int rank = 0; rank < 13; ++rank) {
      cards.push_back(new Card(static_cast<Card::Suit>(suit),
                               static_cast<Card::Rank>(rank)));
    }
  }
    shuffle();
}

// void Deck::removeCard(const Card* card) {
//     auto it = std::find_if(cards.begin(), cards.end(),
//      [card](Card* c) { return *c == *card; });
//     if (it != cards.end()) {
//         delete *it;
//         cards.erase(it);
//     }
// }
