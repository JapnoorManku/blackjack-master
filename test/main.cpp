#include <iostream>

#include "StartGameTest.hpp"
#include "HitTest.hpp"
#include "StandTest.hpp"
#include "GameStateTest.hpp"

void runTests() {
  OATPP_RUN_TEST(HitTest);
  OATPP_RUN_TEST(StartGameTest);
  OATPP_RUN_TEST(StandTest);
  OATPP_RUN_TEST(GameStateTest);
}

int main() {
  oatpp::base::Environment::init();

  runTests();

  /* Print how much objects were created during app running, and what have
   * left-probably leaked */
  /* Disable object counting for release builds using '-D
   * OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount()
            << "\n";
  std::cout << "objectsCreated = "
            << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  OATPP_ASSERT(oatpp::base::Environment::getObjectsCount() == 0);

  oatpp::base::Environment::destroy();

  return 0;
}
