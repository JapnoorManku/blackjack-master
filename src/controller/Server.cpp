/**
* @author Suwinya Rajapakse <suwinya.rajapakse@uleth.ca>
* @date March 15, 2025
*/

#include "ServerComponent.hpp"
#include "GameController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/network/Server.hpp"

/** 
 * @brief Initialize and runs the game server
 */

void run() {
    ServerComponent components;

    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>,
                    connectionProvider);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>,
                    connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>,
                    router);

    /* Register the controller */
    auto gameController = std::make_shared<GameController>();
    router->addController(gameController);

    /* Create and run server */
    oatpp::network::Server server(connectionProvider, connectionHandler);
    OATPP_LOGI("Server", "Running on port %s...",
        connectionProvider->getProperty("port").toString()->c_str());
    server.run();
}

/**
 * @brief Entry point
 * @return exit status code
 */
int main() {
    oatpp::base::Environment::init();
    run();
    oatpp::base::Environment::destroy();
    return 0;
}
