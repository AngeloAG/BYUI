#include "card.h"
#include <iostream>

Card::Card(CardType type) : name{""}, type{type}, amount{0} {}

Card::Card(std::string name, CardType type, int amount) : name{name}, type{type}, amount{amount} {}

bool Card::is_same_name(std::string name) const 
{
   return this->name == name;
}

bool Card::is_same_type(CardType type) const
{
   return this->type == type;
}

int Card::get_amount() const
{
   return amount;
}

void Card::prompt_for_information()
{
   std::cin.ignore();
   std::cout << "Enter the name: ";
   getline(std::cin, name);
   std::cout << std::endl;

   std::cout << "Enter the amount of copies of this card: ";
   std::cin >> amount;
   std::cout << std::endl;
}

std::string Card::encode() const
{
   return cardTypeToString(type) + "#" + name + "#" + std::to_string(amount);
}

void Card::add(int amount)
{
   this->amount += amount;
}

void Card::remove(int amount)
{
   if(this->amount > 0)
      this->amount -= amount;
}