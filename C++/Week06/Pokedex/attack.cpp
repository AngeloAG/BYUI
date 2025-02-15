#include "attack.h"
#include <iostream>

Attack::Attack() : name{""}, damage{0}, energy_cost{0}, description{""} {}

Attack::Attack(std::string name, int damage, int energy_cost, std::string description)
   : name{name}, damage{damage}, energy_cost{energy_cost}, description{description}
{}

void Attack::display() const
{
   std::cout << "      Attack: " << name
             << " Damage: " << damage
             << " Energy: " << energy_cost
             << " Desc: " << description
             << std::endl;
}

void Attack::prompt_for_information()
{
   std::cout << "Enter the name of the attack: ";
   getline(std::cin, name);
   std::cout << std::endl;

   std::cout << "Enter the damage: ";
   std::cin >> damage;
   std::cout << std::endl;

   std::cout << "Enter the energy cost: ";
   std::cin >> energy_cost;
   std::cout << std::endl;

   std::cin.ignore();
   std::cout << "Enter the description: ";
   getline(std::cin, description);
   std::cout << std::endl;
}

std::string Attack::encode() const
{
   return "#" + name + "#" + std::to_string(damage) + "#" + std::to_string(energy_cost) + "#" + description;
}