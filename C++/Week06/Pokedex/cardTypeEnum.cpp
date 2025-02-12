#include "cardTypeEnum.h"

std::string cardTypeToString(CardType type)
{
   switch (type)
   {
   case TRAINER:
      return "Trainer";
   case POKEMON:
      return "Pokemon";
   case ENERGY:
      return "Energy";
   case INVALID_CARD:
      return "Invalid";
   default:
      return "Unknown";
   }
}

CardType stringToCardType(std::string type)
{
   if (type == "Trainer" || type == "trainer")
      return TRAINER;
   else if(type == "Pokemon" || type == "pokemon")
      return POKEMON;
   else if(type == "Energy" || type == "energy") 
      return ENERGY;
   return INVALID_CARD;
}
