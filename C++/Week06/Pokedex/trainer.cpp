#include "trainer.h"
#include <iostream>
#include <list>
#include "utils.h"

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

   std::cout << "Enter the effect: ";
   getline(std::cin, effect);
   std::cout << std::endl;

   trainer_type = stringToTrainerType(trainer_type_string);
}

std::string Trainer::encode() const
{
   std::string encoding = Card::encode();
   return encoding + "#" + trainerTypeToString(trainer_type) + "#" + effect;
}

void Trainer::decode(std::string encoding)
{
   //           Card Type|Name|Amount|Trainer Type|Effect
   // Example: Trainer#Kofu#4#Supporter#Shuffle your hand
   std::list<std::string> parts = split(encoding, '#');
   std::list<std::string>::iterator it = parts.begin();
   name = *(++it);
   amount = std::stoi(*(++it));
   trainer_type = stringToTrainerType(*(++it));
   effect = *(++it);
}