#pragma once
#include <string>
#include "CardTypeEnum.h"

class Card
{
protected:
   std::string name;
   CardType type;
   int amount;

public:
   Card(CardType type);
   Card(std::string name, CardType type, int amount);
   virtual void display() const = 0;
   bool is_same_name(std::string name) const;
   bool is_same_type(CardType type) const;
   int get_amount() const;
   virtual void prompt_for_information();
   virtual std::string encode() const;
   virtual void decode(std::string encoding) = 0;
};