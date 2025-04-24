/**
* @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>, Jack Simonton <jack.simonton@uleth.ca>, Japnoor Manku <japnoor.manku@uleth.ca>, John S. Anvik <j.anvik@uleth.ca>
* @date Feb 15, 2025
*/

#include <string>
#include <sstream>
#include <iostream>
#include "../../include/view/UI.hpp"

void UI::displayHand(const std::string& owner, Hand* hand) {
    std::vector<Card*> cards = hand->getCards();
    std::cout << owner << "'s hand: ";
    for (Card* card : cards) {
        std::cout << Card::getRank(card->rank) << " of "
         << Card::getSuit(card->suit) << ", ";
    }
    std::cout << "(Value: " << hand->getValue() << ")\n";
}

void UI::help() {
    std::cout << "Blackjack Help:\n";
    std::cout << "- Try to get as close to 21 as" <<
    "possible without exceeding it.\n";
    std::cout << "- Aces can be worth 1 or 11," <<
     "depending on the situation.\n";
    std::cout << "- Face cards (King, Queen, Jack)" <<
     "are worth 10 points.\n";
    std::cout << "- You can either 'Hit' to take another" <<
     "card or 'Stand' to keep your hand.\n";
}

std::string UI::getAction(Hand* hand) {
    std::string choice;
    std::cout << "Enter action (0: Hit, 1: Stand, 2: Help): ";
    std::cin >> choice;
    return choice;
}

void UI::displayWinner(std::vector<Player*> winners) {
    if (winners.empty()) {
        std::cout << "No winners this round.\n";
    } else {
        std::cout << "Winner(s): ";
        for (Player* player : winners) {
            std::cout << player->getName() << " ";
        }
        std::cout << "\n";
    }
}

// bool UI::decideAceValue(Hand* hand) {
//     std::string choice;
//     std::cout << "You have an Ace. Do you want" <<
//      "it to be worth 1 or 11? (1/11): ";
//     std::cin >> choice;
//     return choice == '1';
// }

bool UI::playAgain() {
    std::string choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return choice == "y" || choice == "Y";
}

void UI::displayDealerHand(Hand* hand, bool revealAll) {
    std::vector<Card*> cards = hand->getCards();
    std::cout << "Dealer's hand: ";
    if (cards.empty()) {
        std::cout << "Empty hand.\n";
    } else {
        if (!revealAll) {
            std::cout << Card::getRank(cards[0]->rank) << " of "
                      << Card::getSuit(cards[0]->suit) << ", [Hidden]\n";
        } else {
            for (Card* card : cards) {
                std::cout << Card::getRank(card->rank) << " of "
                          << Card::getSuit(card->suit) << ", ";
            }
            std::cout << "(Value: " << hand->getValue() << ")\n";
        }
    }
}
