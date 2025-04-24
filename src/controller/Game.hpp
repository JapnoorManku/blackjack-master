/**
 * @author Jack Simonton <Jack.Simonton@uleth.ca>
 * @date Spring 2025
*/

/**
 * @file Game.hpp
 * @brief Game class for controlling round of Black Jack
 * Acts as the controller in MVC
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include "../../include/model/Deck.hpp"
#include "../../include/view/UI.hpp"
#include "../../include/model/Player.hpp"
#include "../../include/model/CPU.hpp"

/**
 * @class Game
 * @brief Controller class for Black Jack
 */
class Game {
 public:
    /**
     * @brief Constructs Game Object
     * @param ui pointer to UI object
     */
    //explicit Game(UI* ui);

    /**
    * @brief Copy Constructor
    */
    Game();

    /**
    * @brief Assignment Operator
    */
    Game& operator=(Game other);\

    /**
    * @brief Copy Constructor
    */
    //Game(const Game& other);

    /**
     * @brief Game Destructor
     */
    ~Game();

    /**
     * @brief Plays a round of Blackjack.
     *
     * This controls the overall game flow
     * deals the initial cards, manages turns, and determines the winner
     */
    void play();
   /**
     * @brief Deals the initial two cards to both the player and the dealer
     */
    void initialDeal();

     /**
     @brief Dtermine the winner of the round
      * Compares the player's and dealer's scores and delegates the winner display to the UI
      */
    void determineWinner();

     /**
      * @brief Builds a Hand object from a vector of Card pointers
      * @param cards A vector containing pointers to Card objects
      * @return A Hand object populated with the given cards
      */
    Hand buildHand(const std::vector<Card*>& cards);

    Player* getPlayer() const { return player; }
    CPU* getDealer() const { return dealer; }
    Deck& getDeck() { return deck; }

 protected:
    Deck deck;
    UI* ui;
    Player* player;
    CPU* dealer;
};

#endif
