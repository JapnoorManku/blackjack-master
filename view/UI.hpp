/**
* @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
* @date Feb 10, 2025
*/

#ifndef UI_H
#define UI_H

#include <vector>
#include <string>
#include "../../include/model/Player.hpp"
#include "../../include/model/Hand.hpp"

class UI {
 public:
    virtual ~UI() {}

    /**
    * @brief Method to display players hand
    * @param hand is the hand to be displaied
    */
    virtual void displayHand(const std::string& owner, Hand* hand);

    /**
    * @brief Method to display the Dealers Hand
    */
    virtual void displayDealerHand(Hand* hand, bool revealAll);

    /**
    * @brief Display help if helps needed
    */
    virtual void help();

    /**
    * @brief Asks for the players choice
    * @return 0 for hit, 1 ofr stand, 2 to diplay help
    */
    virtual std::string getAction(Hand* hand);

    /**
    * @brief Display the winner
    * @param the winner to be displayed
    */
    virtual void displayWinner(std::vector<Player*> winner);

    /**
    * @brief Lets the player decide if Ace is 1 or 11
    * @param the hand that has the Ace for the player to make their decision
    * @return 1 if Ace is 1, 0 if Ace is 11
    */
    bool decideAceValue(Hand* hand);

    /**
    * @brief Ask if the player want to play again
    * @return true if the player wants to play again if not false
    */
    virtual bool playAgain();
};

#endif
