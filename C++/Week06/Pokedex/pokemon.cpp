#include "pokemon.h"
#include <iostream>
#include <memory>
#include <list>
#include "attack.h"
#include "utils.h"

Pokemon::Pokemon(CardType type) : Card(type), hp{0}, ability{""}, attack{nullptr}, elemental_type{ElementalType::INVALID} {}

Pokemon::Pokemon(std::string name, int amount, int hp, std::string ability, std::shared_ptr<Attack> attack, ElementalType elemental_type)
   : Card(name, POKEMON, amount), hp{hp}, ability{ability}, attack{attack}, elemental_type{elemental_type} {}

void Pokemon::display() const 
{
   std::cout << "Pokemon: " << name
             << " Type: " << elemental_type
             << " Health: " << hp
             << " Ability: " << ability
             << " Amount: " << amount
             << std::endl;
   this->attack->display();
}

void Pokemon::prompt_for_information()
{
   Card::prompt_for_information();
   std::string elemental_type_string;

   std::cin.ignore();
   std::cout << "Enter the elemental type: ";
   getline(std::cin, elemental_type_string);
   std::cout << std::endl;

   std::cout << "Enter the health points: ";
   std::cin >> hp;
   std::cout << std::endl;

   std::cout << "Enter the ability (optional): ";
   getline(std::cin, ability);
   std::cout << std::endl;

   attack = std::make_shared<Attack>();
   attack->prompt_for_information();
   elemental_type = stringToElementalType(elemental_type_string);
}

std::string Pokemon::encode() const
{
   std::string encoding = Card::encode();
   return encoding + "#" + std::to_string(hp) + "#" + ability + "#" + elementalTypeToString(elemental_type) + attack->encode();
}

void Pokemon::decode(std::string encoding)
{
   //           Card Type|Name|Amount|Hp|Ability|Elemental Type|Attack Name|Damage|Cost|Description
   // Example: Pokemon#Dondonzo#4#160#Deep Dive#Water#atack#Revenge#10#2#Do 50 more damage for each tatsugiri
   std::list<std::string> parts = split(encoding, '#');
   std::list<std::string>::iterator it = parts.begin();
   name = *(++it);
   amount = std::stoi(*(++it));
   hp = std::stoi(*(++it));
   ability = *(++it);
   elemental_type = stringToElementalType(*(++it));
   if (it != parts.end())
   {
      std::string attack_name = *(++it);
      int damage = std::stoi(*(++it));
      int cost = std::stoi(*(++it));
      std::string description = *(++it);
      attack = std::make_shared<Attack>(attack_name, damage, cost, description);
   }
}