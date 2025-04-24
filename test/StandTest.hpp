#ifndef STANDTEST_HPP
#define STANDTEST_HPP

#include <iostream>
#include <memory>

#include "GameApiTestClient.hpp"
#include "TestComponent.hpp"
#include "../src/controller/GameController.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"

class StandTest : public oatpp::test::UnitTest {
 public:
    StandTest() : UnitTest("StandTest") {}
    void onRun() override;
};

#endif // STANDTEST_HPP
