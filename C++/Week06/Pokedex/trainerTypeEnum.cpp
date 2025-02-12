#include "trainerType.h"

std::string trainerTypeToString(TrainerType type)
{
   switch (type)
   {
   case SUPPORTER:
      return "Supporter";
   case ITEM:
      return "Item";
   case STADIUM:
      return "Stadium";
   case TOOL:
      return "Tool";
   default:
      return "Unknown";
   }
}

TrainerType stringToTrainerType(std::string type)
{
   if (type == "Supporter" || type == "supporter")
      return SUPPORTER;
   else if (type == "Item" || type == "item")
      return ITEM;
   else if (type == "Stadium" || type == "stadium")
      return STADIUM;
   else if (type == "Tool" || type == "tool")
      return TOOL;
   return INVALID_TRAINER;
}