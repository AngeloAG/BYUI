#include "energy.h"
#include <iostream>

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