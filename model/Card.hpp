/**
* @file Card.hpp
* @brief Defines the Card class.
*
* @author Jack Simonton <jack.simonton@uleth.ca>
* @date Spring 2025
*/

#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>

/**
* @class Card
* @brief Represents a single playing card with a suit and rank
*/
class Card {
 public:
    /**
    * @enum Suit
    * @brief Represents the four suits in a standard deck
    */
    enum Suit { CLUB, DIAMOND, SPADE, HEART };

    /**
    * @enum Rank
    * @brief Represents the ranks in a standard deck
    */
    enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                 EIGHT, NINE, TEN, JACK, QUEEN, KING };

    /**
    * @brief Constructs a Card with the given suit and rank
    * @param s The suit of the card
    * @param r The rank of the card
    */
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    /**
    * @brief Gets the string representation of a rank
    * @param r The rank to convert
    * @return The rank as a string
    */
    static std::string getRank(Card::Rank r);

    /**
    * @brief Gets the string representation of a suit
    * @param s The suit to convert
    * @return The suit as a string
    */
    static std::string getSuit(Card::Suit s);

    /**
    * @brief Gets the next rank in sequence
    * @param r The current rank
    * @return The next rank
    */
    static Rank nextRank(Rank r);

    /**
    * @brief Gets the value of the card
    * @return The integer value of the card
    */
    virtual int getValue();

    const Suit suit;
    const Rank rank;

    /**
    * @brief Overloads the << operator to print the card
    * @param os The output stream
    * @param c The card to print
    * @return The modified output stream
    */
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
    bool operator==(const Card& other) const;
    // virtual void someFunction() = 0;
};

#endif
