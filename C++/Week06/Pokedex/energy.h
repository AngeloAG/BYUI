#pragma once
#include "card.h"
#include "elementalTypeEnum.h"


class Energy : public Card
{
private: 
   ElementalType elemental_type;

public:
   Energy(CardType type);
   Energy(std::string name, int amount, ElementalType elemental_type);
   virtual void display() const;
   virtual void prompt_for_information();
   virtual std::string encode() const;
   virtual void decode(std::string encoding);
};