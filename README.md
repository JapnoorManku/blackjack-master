Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Version: c++14
  * Style Check: cpplint 1.6.1
  * Static Check: cppcheck 1.90

Certain assumptions have been made:
* One repo contains the files for one project.
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file and the name of the file starts with a capital letter.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.

Sprint 1 Review - - 

Model
* Card - Jack
* CPU - Jack, John
* Deck - Japnoor
* Hand - Suwinya
* Player - John

View 
* UI - Suwinya

Controller
* Game - Jack

Tests
* MockGame - Jack, John
* MockUI - Jack
* testCard - John
* testCPU
* testDeck
* testGame
* testHand
* testPlayer
* testUI

Sprint 2 Review - -

Connect to the following endpoints
* This is out endpoint number: http://localhost:8600
 * This must be the first one http://localhost:8600/game/start
 * Afther this: http://localhost:8600/game/hit Or
 * This: http://localhost:8600/game/stand
* This is a check endpoint: http://localhost:8600/game

Controller
* GameController - Jack
* Server.cpp - Suwinya
* ServerComponent - Jack, Suwinya
* DTO - Jack, Japnoor,

Makefile - Jack, Japnoor, John, Suwinya

Tests
* GameApiTest - Suwinya
* GameStateTest - John
* HitTest - John
* StandTest - John
* StartGameTest - John

Examples Json output: 
* playerHand:
  * cards:
    * 0:
      * suit: "CLUB"
      * rank: "SEVEN"
    * 1:
      * suit: "SPADE"
      * rank: "TWO"
* dealerHand:
  * cards:
    * 0:
      * suit: "DIAMOND"
      * rank: "QUEEN"
    * 1:
      * suit: "HIDDEN"
      * rank: "HIDDEN"
* playerScore: 9
* dealerScore: 0
* status: "in_progress"