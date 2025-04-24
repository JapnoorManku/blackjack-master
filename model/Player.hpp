/**
 * @author John S. Anvik <j.anvik@uleth.ca>
 * @date Spring 2025
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <list>
#include <vector>
#include "../model/Card.hpp"
#include "../model/Hand.hpp"

class Player {
 public:
    /**
     * @brief Constructor
     * @param name name of the player
    */

    explicit Player(const std::string& name);

    /**
     * @brief Destructor for Player
    */

    virtual ~Player() { clearHand(); }

    /**
     * @brief Adds a card to the player's hand
     * @param card Pointer to card to add to the player's hand
     */

    void addCard(Card* card);

    /**
     * @brief Returns the player's hand
     */

    std::vector<Card*> getHand();

    /**
     *  @brief Recount player's hand to update score (Reevaluate Ace values)
     */

    int updateScore();

    /**
     * @brief Returns total value of cards in player's hand (score)
     */

    int getScore();

    /**
     * @brief Returns name of player
     */

    std::string getName();

    /**
     * @brief set's players hit state to true if they will hit (draw again), false if they will stand (not draw again)
     * @param hit_state set to true if they will hit (draw again), false if they will stand (not draw again)
     */

    bool setHitState(bool hit_state);

    /**
     * @brief returns true if player will hit (draw again), false if they will stand (not draw again)
     */

    bool getHitState();

    /**
     * @brief Clears the hand so player or cpu can get new cards.
    */

    void clearHand();

 private:
    const std::string name;
    unsigned int score = 0;
    bool hit;
    std::vector<Card*> hand;
};

#endif
