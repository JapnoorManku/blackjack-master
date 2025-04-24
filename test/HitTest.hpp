#ifndef HITTEST_HPP
#define HITTEST_HPP

#include "oatpp-test/UnitTest.hpp"
#include "GameApiTestClient.hpp"

class HitTest : public oatpp::test::UnitTest {
 public:
    HitTest() : UnitTest("TEST[Hit Test]") {}
    void onRun() override;
};

#endif //HITTEST_HPP
