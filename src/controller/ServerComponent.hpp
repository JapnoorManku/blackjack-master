/**
 * @author Jack Simonton <Jack.Simonton@uleth.ca>
 * @date Spring 2025
*/
#ifndef SERVERCOMPONENT_HPP
#define SERVERCOMPONENT_HPP

#include <memory>
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/core/macro/component.hpp"

class ServerComponent {
 public:
    OATPP_CREATE_COMPONENT(std::shared_ptr
        <oatpp::network::ServerConnectionProvider>,
         serverConnectionProvider)([] {
        return oatpp::network::tcp::server::ConnectionProvider::createShared
        ({"0.0.0.0", 8600, oatpp::network::Address::IP_4});
    }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>,
                            httpRouter)([] {
        return oatpp::web::server::HttpRouter::createShared();
    }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>,
         serverConnectionHandler)([] {
        OATPP_COMPONENT(std::shared_ptr
            <oatpp::web::server::HttpRouter>, router);
        return oatpp::web::server::HttpConnectionHandler::createShared(router);
    }());

    OATPP_CREATE_COMPONENT(std::shared_ptr
        <oatpp::data::mapping::ObjectMapper>, objectMapper)([] {
        return std::make_shared<oatpp::parser::json::mapping::ObjectMapper>();
    }());
};

#endif
