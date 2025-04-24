/**
 * @author Jack Simonton <Jack.Simonton@uleth.ca>
 * @date Spring 2025
*/

#include "Game.hpp"

// Game::Game() {}

Game::Game() : ui(ui) {
    player = new Player("Player");
    dealer = new CPU();
}

Game::~Game() {
    delete player;
    delete dealer;
}

Hand Game::buildHand(const std::vector<Card*>& cards) {
    Hand hand;
    for (Card* card : cards) {
        hand.addCard(card);
    }
    return hand;
}

void Game::initialDeal() {
    player->addCard(deck.dealCard());
    dealer->addCard(deck.dealCard());
    player->addCard(deck.dealCard());
    dealer->addCard(deck.dealCard());
    player->updateScore();
    dealer->updateScore();
}

void Game::determineWinner() {
    int playerScore = player->getScore();
    int dealerScore = dealer->getScore();
    std::vector<Player*> winners;
    if (playerScore == 21) {
        winners.push_back(player);
    } else if (playerScore > 21) {
        winners.push_back(dealer);
    } else if (dealerScore > 21) {
        winners.push_back(player);
    } else if (playerScore > dealerScore) {
        winners.push_back(player);
    } else if (dealerScore > playerScore) {
        winners.push_back(dealer);
    } else {
        winners.push_back(player);
        winners.push_back(dealer);
    }

    ui->displayWinner(winners);
}

void Game::play() {
    bool playing = true;

    while (playing) {
        player->clearHand();
        dealer->clearHand();
        //deck.reset();
        if (deck.size() < 10) {
            deck.reset();
        }
        initialDeal();
        Hand dealerHand = buildHand(dealer->getHand());
        ui->displayDealerHand(&dealerHand, false);
        Hand playerHand = buildHand(player->getHand());
        ui->displayHand("Player", &playerHand);
        bool playerBusted = false;
        bool playerStands = false;

        while (!playerBusted && !playerStands) {
            Hand tempHand = buildHand(player->getHand());
            std::string action = ui->getAction(&tempHand);

            if (action == "0") {
                player->addCard(deck.dealCard());
                player->updateScore();
                tempHand = buildHand(player->getHand());
                ui->displayHand("Player", &tempHand);
                if (player->getScore() > 21) {
                    playerBusted = true;
                }
            } else if (action == "1") {
                playerStands = true;
            } else if (action == "2") {
                ui->help();
            }
        }

        dealerHand = buildHand(dealer->getHand());
        ui->displayDealerHand(&dealerHand, true);

        if (!playerBusted) {
            while (dealer->getScore() < 17) {
                dealer->addCard(deck.dealCard());
                dealer->updateScore();
                dealerHand = buildHand(dealer->getHand());
                ui->displayDealerHand(&dealerHand, true);
            }
        }
        determineWinner();
        playing = ui->playAgain();
    }
}
