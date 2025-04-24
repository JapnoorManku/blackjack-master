// #pragma once // This line does the same a #ifndef #define #endif
#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include <memory>
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "Game.hpp"
#include "../../src/dto/DTO.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GameController : public oatpp::web::server::api::ApiController {
 public:
    GameController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper) {}

 private:
    std::unique_ptr<Game> currentGame;
    oatpp::Object<GameStateDTO> toGameStateDTO
        (const Game* game, bool revealDealer = false) {
        auto state = GameStateDTO::createShared();
        auto playerHandDto = HandDTO::createShared();
        playerHandDto->cards = oatpp::List
            <oatpp::Object<CardDTO>>::createShared();
        for (const auto* card : game->getPlayer()->getHand()) {
            auto cardDto = CardDTO::createShared();
            cardDto->suit = Card::getSuit(card->suit);
            cardDto->rank = Card::getRank(card->rank);
            playerHandDto->cards->push_back(cardDto);
        }
        state->playerHand = playerHandDto;
        state->playerScore = game->getPlayer()->getScore();
        auto dealerHandDto = HandDTO::createShared();
        dealerHandDto->cards = oatpp::List
            <oatpp::Object<CardDTO>>::createShared();
        const auto& dealerHand = game->getDealer()->getHand();
        for (size_t i = 0; i < dealerHand.size(); ++i) {
            auto cardDto = CardDTO::createShared();
            if (i == 1 && !revealDealer) {
                cardDto->suit = "Hidden";
                cardDto->rank = "Hidden";
            } else {
                cardDto->suit = Card::getSuit(dealerHand[i]->suit);
                cardDto->rank = Card::getRank(dealerHand[i]->rank);
            }
            dealerHandDto->cards->push_back(cardDto);
        }
        state->dealerHand = dealerHandDto;
        state->dealerScore = revealDealer ? game->getDealer()->getScore() : 0;
        state->status = "in_progress";
        return state;
    }

 public:
    ENDPOINT("GET", "/game/start", startGame) {
        currentGame = std::make_unique<Game>();
        currentGame->initialDeal();
        auto response = createDtoResponse
        (Status::CODE_200, toGameStateDTO(currentGame.get()));
        response->putHeader("Access-Control-Allow-Origin", "*");
        response->putHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response->putHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");

        return response;
    }

    // Handle OPTIONS preflight request
    ENDPOINT("OPTIONS", "/*", corsOptions) {
        auto response = createResponse(Status::CODE_200, "OK");
        response->putHeader("Access-Control-Allow-Origin", "*");
        response->putHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response->putHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
        return response;
    }


    ENDPOINT("GET", "/game/hit", hit) {
        currentGame->getPlayer()->addCard(currentGame->getDeck().dealCard());
        currentGame->getPlayer()->updateScore();
        currentGame->getDealer()->updateScore();
        currentGame->getDealer()->getScore();
        auto state = toGameStateDTO(currentGame.get());
        if (currentGame->getPlayer()->getScore() > 21) {
            state->status = "player_bust";
            currentGame.reset();
        }
        auto response = createDtoResponse(Status::CODE_200, state);

        response->putHeader("Access-Control-Allow-Origin", "*");
        response->putHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response->putHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
        return response;
    }

    ENDPOINT("GET", "/game/stand", stand) {
        while (currentGame->getDealer()->getScore() < 17) {
            currentGame->getDealer()->addCard
                (currentGame->getDeck().dealCard());
            currentGame->getDealer()->updateScore();
        }
        auto state = toGameStateDTO(currentGame.get(), true);
        int playerScore = currentGame->getPlayer()->getScore();
        int dealerScore = currentGame->getDealer()->getScore();
        if (playerScore > 21) {
            state->status = "dealer_wins";
        } else if (dealerScore > 21 || playerScore > dealerScore) {
            state->status = "player_wins";
        } else if (dealerScore > playerScore) {
            state->status = "dealer_wins";
        } else {
            state->status = "tie";
        }
        currentGame.reset();
        auto response = createDtoResponse(Status::CODE_200, state);
        response->putHeader("Access-Control-Allow-Origin", "*");
        response->putHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response->putHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
        return response;
    }

    ENDPOINT("GET", "/game", getGameState) {
        auto response = createDtoResponse
        (Status::CODE_200, toGameStateDTO(currentGame.get()));
        response->putHeader("Access-Control-Allow-Origin", "*");
        response->putHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response->putHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
        return response;
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif // GAMECONTROLLER_HPP
