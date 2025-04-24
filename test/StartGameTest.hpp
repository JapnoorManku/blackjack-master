#ifndef STARTGAMETEST_HPP
#define STARTGAMETEST_HPP

#include "oatpp-test/UnitTest.hpp"
#include "GameApiTestClient.hpp"


class StartGameTest : public oatpp::test::UnitTest {
 public:
    StartGameTest() : UnitTest("TEST[Start Game Test]") {}
    void onRun() override;
};

#endif //STARTGAMETEST_HPP
