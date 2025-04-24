#include "HitTest.hpp"

#include <iostream>
#include <memory>

#include "GameApiTest.hpp"
#include "TestComponent.hpp"
#include "../src/controller/GameController.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"

void HitTest::onRun() {
    // Register test components
    TestComponent component;

    // Create client-server test runner
    oatpp::test::web::ClientServerTestRunner runner;

    // Get object mapper component
    OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                    objectMapper);

    // Add GameController endpoints to the router of the test server
    runner.addController(std::make_shared<GameController>());

    // Run test
    runner.run(
        [this, &runner] {
          /* Get client connection provider for Api Client */
          OATPP_COMPONENT(
              std::shared_ptr<oatpp::network::ClientConnectionProvider>,
              clientConnectionProvider);

          /* Get object mapper component */
          OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                          objectMapper);

          /* Create http request executor for Api Client */
          auto requestExecutor =
              oatpp::web::client::HttpRequestExecutor::createShared(
                  clientConnectionProvider);

          /* Create Test API client */
          auto client =
          GameApiTestClient::createShared(requestExecutor, objectMapper);

          /* Call server API */
          auto response = client->startGame();

          /* Read response body as MessageDto */
          auto message =
          response->readBodyToDto<oatpp::
          Object<GameStateDTO>>(objectMapper.get());

          // Test GET

          /* Assert that server responds with 200 */
          OATPP_ASSERT(response->getStatusCode() == 200);

          response = client->startGame();
          OATPP_ASSERT(response->getStatusCode() == 200);
          message =
          response->readBodyToDto<oatpp::
          Object<GameStateDTO>>(objectMapper. get());
          OATPP_ASSERT(message);
          OATPP_ASSERT(message->playerScore <= 21);
          OATPP_ASSERT(message->dealerScore <= 21);
        },
        std::chrono::minutes(10) /* test timeout */);

    /* wait all server threads finished */
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
