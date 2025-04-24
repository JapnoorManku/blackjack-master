/**
* @author Jack Simonton, Suwinya Rajapakse, John S. Anvik, <jack.simonton@uleth.ca>, suwinya.rajapakse@uleth.ca> <j.anvik@uleth.ca>
*/
#ifndef GAMEAPITEST_HPP
#define GAMEAPITEST_HPP

#include "../src/controller/GameController.hpp"
#include "../src/dto/DTO.hpp"
#include "oatpp-test/UnitTest.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/web/server/HttpRequestHandler.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class GameApiTestClient : public oatpp::web::client::ApiClient {
    API_CLIENT_INIT(GameApiTestClient)

    API_CALL("GET", "/game/start", startGame)
    API_CALL("GET", "/game/hit", hit)
    API_CALL("GET", "/game/stand", stand)
};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)

#endif
