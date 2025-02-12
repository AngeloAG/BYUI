#include "trainer.h"
#include <iostream>

Trainer::Trainer(CardType type) : Card(type), effect{""}, trainer_type{TrainerType::INVALID_TRAINER} {}

Trainer::Trainer(std::string name, int amount, std::string effect, TrainerType trainer_type) 
   : Card(name, TRAINER, amount), effect{effect}, trainer_type{trainer_type} {}

void Trainer::display() const 
{
   std::cout << "Trainer: " << name 
             << ", Type: " << trainerTypeToString(trainer_type)
             << ", Effect: " << effect
             << ", Amount: " << amount
             << std::endl;
}

void Trainer::prompt_for_information()
{
   Card::prompt_for_information();
   std::string trainer_type_string;

   std::cin.ignore();
   std::cout << "Enter the type of trainer: ";
   getline(std::cin, trainer_type_string);
   std::cout << std::endl;

   trainer_type = stringToTrainerType(trainer_type_string);

   std::cin.ignore();
   std::cout << "Enter the effect: ";
   getline(std::cin, effect);
   std::cout << std::endl;
}