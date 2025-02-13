#pragma once
#include <string>

class Attack
{
private:
   std::string name;
   int damage;
   int energy_cost;
   std::string description;

public:
   Attack();
   Attack(std::string name, int damage, int energy_cost, std::string description);
   void display() const;
   void prompt_for_information();
   std::string encode() const;
};