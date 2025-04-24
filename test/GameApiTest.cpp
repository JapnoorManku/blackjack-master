#include <iostream>
#include <memory>
#include "oatpp-test/UnitTest.hpp"
#include "GameApiTest.hpp"
#include "GameApiTestClient.hpp"
#include "../src/controller/GameController.hpp"
#include "../src/dto/DTO.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "oatpp-test/web/ClientServerTestRunner.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"

//     void GameApiTest::onRun() override {
//     // Test for adding a player
//     {
//     /* Register test components */
//     TestComponent component;

//     /* Create client-server test runner */
//     oatpp::test::web::ClientServerTestRunner runner;

//     /* Get object mapper component */
//     OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
//                 objectMapper);

//       /* Add CircleController endpoints to the router of the test server */
//     runner.addController(std::make_shared<CGameController>());

//     auto playerDTO = PlayerDTO::createShared();
//         playerDTO->name = "Test Player";
//         playerDTO->score = 0;
//         playerDTO->hand = List<CardDTO>::createShared();

//         auto response = testClient->callPOST("/player", playerDTO);
//         OATPP_ASSERT(response->getStatusCode() == 200);
//     }

//     // Test for starting the game
//     {
//         auto response = testClient->callPOST("/game/start", nullptr);
//         OATPP_ASSERT(response->getStatusCode() == 200);
//     }

//     // Test for drawing a card
//     {
//         auto response = testClient->callPOST("/game/draw", nullptr);
//         OATPP_ASSERT(response->getStatusCode() == 200);
//     }
// }
