#include "energy.h"
#include <iostream>
#include <list>
#include "utils.h"

Energy::Energy(CardType type) : Card(type), elemental_type{ElementalType::INVALID} {}

Energy::Energy(std::string name, int amount, ElementalType elemental_type) : Card(name, ENERGY, amount), elemental_type{elemental_type} {}

void Energy::display() const 
{
   std::cout << elementalTypeToString(elemental_type) 
             << " Energy." 
             << " Amount: " << amount
             << std::endl;
}

void Energy::prompt_for_information() 
{
   Card::prompt_for_information();
   std::string elemental_type_string;

   std::cin.ignore();
   std::cout << "Enter the elemental type: ";
   getline(std::cin, elemental_type_string);
   std::cout << std::endl;

   elemental_type = stringToElementalType(elemental_type_string);
}

std::string Energy::encode() const
{
   std::string encoding = Card::encode();
   return encoding + "#" + elementalTypeToString(elemental_type);
}

void Energy::decode(std::string encoding)
{
   //           Card Type|Name|Amount|Elemental Type 
   // Example: Energy#Water Energy#10#Water
   std::list<std::string> parts = split(encoding, '#');
   std::list<std::string>::iterator it = parts.begin();
   name = *(++it);
   amount = std::stoi(*(++it));
   elemental_type = stringToElementalType(*(++it));
}