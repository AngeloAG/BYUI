#pragma once
#include <memory>
#include "elementalTypeEnum.h"
#include <string>
#include "card.h"

class Attack;

class Pokemon : public Card
{
private:
   int hp;
   std::string ability;
   std::shared_ptr<Attack> attack;
   ElementalType elemental_type;
public:
   Pokemon(CardType type);
   Pokemon(std::string name, int amount, int hp, std::string ability, std::shared_ptr<Attack> attack, ElementalType elemental_type);
   virtual void display() const;
   virtual void prompt_for_information();
};