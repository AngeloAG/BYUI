#pragma once
#include "card.h"
#include "trainerType.h"

class Trainer : public Card
{
private:
   std::string effect;
   TrainerType trainer_type;
public:
   Trainer(CardType type);
   Trainer(std::string name, int amount, std::string effect, TrainerType trainer_type);
   virtual void display() const;
   virtual void prompt_for_information();
   virtual std::string encode() const;
   virtual void decode(std::string encoding);
};