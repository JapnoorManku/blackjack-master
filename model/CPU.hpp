/**
 * @author John S. Anvik <j.anvik@uleth.ca>
 * @author Jack Simonton <jack.simonton@uleth.ca>
 * @date Spring 2025
*/

#ifndef CPU_HPP
#define CPU_HPP
#include "../model/Player.hpp"

class CPU : public Player {
 public:
    CPU() : Player("Dealer") {}
};

#endif // CPU_HPP
