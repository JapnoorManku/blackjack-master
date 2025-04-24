#ifndef GAMESTATETEST_HPP
#define GAMESTATETEST_HPP

#include "oatpp-test/UnitTest.hpp"
#include "GameApiTestClient.hpp"


class GameStateTest : public oatpp::test::UnitTest {
 public:
    GameStateTest() : UnitTest("TEST[Game State Test]") {}
    void onRun() override;
};

#endif //GAMESTATETEST_HPP
