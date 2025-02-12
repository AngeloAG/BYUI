#include "pokemon.h"
#include <iostream>
#include <memory>
#include "attack.h"

Pokemon::Pokemon(CardType type) : Card(type), hp{0}, ability{""}, attack{nullptr}, elemental_type{ElementalType::INVALID} {}

Pokemon::Pokemon(std::string name, int amount, int hp, std::string ability, std::shared_ptr<Attack> attack, ElementalType elemental_type)
   : Card(name, POKEMON, amount), hp{hp}, ability{ability}, attack{attack}, elemental_type{elemental_type} {}

void Pokemon::display() const 
{
   std::cout << "Pokemon: " << name
             << " Type: " << elemental_type
             << " Health: " << hp
             << " Ability: " << ability
             << std::endl;
   this->attack->display();
   std::cout << "Amount: " << amount;
}

void Pokemon::prompt_for_information()
{
   Card::prompt_for_information();
   std::string elemental_type_string;

   std::cin.ignore();
   std::cout << "Enter the elemental type: ";
   getline(std::cin, elemental_type_string);
   std::cout << std::endl;

   elemental_type = stringToElementalType(elemental_type_string);

   std::cout << "Enter the health points: ";
   std::cin >> hp;
   std::cout << std::endl;

   std::cin.ignore();
   std::cout << "Enter the ability (optional): ";
   getline(std::cin, ability);
   std::cout << std::endl;

   attack = std::make_shared<Attack>();
   attack->prompt_for_information();
}