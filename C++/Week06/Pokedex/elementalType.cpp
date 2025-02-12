#include "elementalTypeEnum.h"

std::string elementalTypeToString(ElementalType type)
{
   switch (type)
   {
   case GRASS:
      return "Grass";
   case ELECTRIC:
      return "Electric";
   case DRAGON:
      return "Dragon";
   case WATER:
      return "Water";
   case FIRE:
      return "Fire";
   case STEEL:
      return "Steel";
   case FIGHTING:
      return "Fighting";
   case PSYCHIC:
      return "Psychic";
   case DARK:
      return "Dark";
   case COLORLESS:
      return "Colorless";
   default:
      return "Unknown";
   }
}

ElementalType stringToElementalType(std::string type)
{
   if (type == "Grass" || type == "grass")
      return GRASS;
   else if (type == "Electric" || type == "electric")
      return ELECTRIC;
   else if (type == "Dragon" || type == "dragon")
      return DRAGON;
   else if (type == "Water" || type == "water")
      return WATER;
   else if (type == "Fire" || type == "fire")
      return FIRE;
   else if (type == "Steel" || type == "steel")
      return STEEL;
   else if (type == "Fighting" || type == "fighting")
      return FIGHTING;
   else if (type == "Psychic" || type == "psychic")
      return PSYCHIC;
   else if (type == "Dark" || type == "dark")
      return DARK;
   else if (type == "Colorless" || type == "colorless")
      return COLORLESS;
   return INVALID;
}
