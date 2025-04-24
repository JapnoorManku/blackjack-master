/**
 * @author Japnoor Manku <japnoor.manku@uleth.ca>
 * @date Feb 10, 2025
*/
#ifndef DECK_H
#define DECK_H
#include <vector>
#include "../../include/model/Card.hpp"

class Deck {
 public:
    /**
    * @brief Creates a Deck object
    */
    Deck();

    /**
    * @brief Destructor for the Deck
    */
    virtual ~Deck();

    /**
    * @brief Randomize the order of the deck
    */
    void shuffle();

    /**
    * @brief Deals the top card of the deck, removing it from the deck
    * @return The card which is dealt with
    */
    Card* dealCard();

    /**
    * @brief Size of the deck
    * @return s size of the card deck
    */

    unsigned size();
    /**
    * @brief Add a Card to the deck
    * @param card : The card being added
    */

    void addCard(Card* card);
    /**
    * @brief Resets the deck to an initial state, containing all 52 cards
    * in a standard order
    */

    void reset();

    /**
    * @brief Removes a Card from the deck
    */
    void removeCard(const Card* card);

 private:
    std::vector<Card*> cards;
};

#endif

