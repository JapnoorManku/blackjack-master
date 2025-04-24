/**
* @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
* @date Feb 10, 2025
*/

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "../model/Card.hpp"

class Hand {
 public:
    /**
    * Creates the object
    */
    Hand();

    /**
    * Gets cards in to a hand and then returns them as a vector
    * @return vector of cards in the hand
    */
    std::vector<Card*> getCards();

    /**
    * Add a card to hand
    * @param a card pointer
    */
    void addCard(Card *card);

    /**
    * returns the calculated value of the hand from its cards
    * @return the value of the hand as an integer
    */
    int getValue();

    /**
    * remove the 1st card from the hand
    */
    void removeCard();

    /**
    * sets the hand to be either active or inactive, detemine if it should draw more cards or not
    * @param 1 if the hand is to be active, 0 if the hand is to be inactive
    */
    void setActive(bool active);

    /**
    * Finds out if the hand is active or not
    * @return 1 if the hand is active, 0 if its inactive
    */
    bool isActive();

 private:
    std::vector<Card*> cards;
    bool currentlyActive;
};

#endif
