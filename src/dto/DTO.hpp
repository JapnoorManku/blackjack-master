#ifndef DTO_HPP
#define DTO_HPP
#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class CardDTO : public oatpp::DTO {
    DTO_INIT(CardDTO, DTO)
    DTO_FIELD(String, suit);
    DTO_FIELD(String, rank);
};

class HandDTO : public oatpp::DTO {
    DTO_INIT(HandDTO, DTO)
    DTO_FIELD(List<Object<CardDTO>>, cards);
};

class GameStateDTO : public oatpp::DTO {
    DTO_INIT(GameStateDTO, DTO)
    DTO_FIELD(Object<HandDTO>, playerHand);
    DTO_FIELD(Object<HandDTO>, dealerHand);
    DTO_FIELD(Int32, playerScore);
    DTO_FIELD(Int32, dealerScore);
    DTO_FIELD(String, status);
};

#include OATPP_CODEGEN_END(DTO)

#endif
