#include "deck.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <memory>
#include "trainerType.h"
#include "trainer.h"
#include "elementalTypeEnum.h"
#include "pokemon.h"
#include "energy.h"
#include "utils.h"

int Deck::available_id = 0;

Deck::Deck() : id{ Deck::available_id }, name{""}, cards{}
{
   Deck::available_id++;
}

Deck::Deck(std::string name) : id{ Deck::available_id }, name{name}, cards{}
{
   Deck::available_id++;
}

void Deck::add_card(std::shared_ptr<Card> card) 
{
   cards.push_back(card);
}

void Deck::remove_card(std::string name) 
{
   auto card_to_remove = remove_if(cards.begin(), cards.end(), [name](auto& card)
      {
         return card->is_same_name(name);
      });

   if (card_to_remove != cards.end())
   {
      cards.erase(card_to_remove, cards.end());
      std::cout << "Card not removed." << std::endl;
   }
   else
   {
      std::cout << "Card not found." << std::endl;
   }
}

int Deck::count(CardType type) const 
{ 
   int total = accumulate(cards.begin(), cards.end(), 0, [type](int accumulator, const std::shared_ptr<Card>& card)
      {
         int amount = card->is_same_type(type) ? card->get_amount() : 0;
         return accumulator + amount;
      });
   return total; 
}

std::list<std::shared_ptr<Card>>::iterator Deck::find_card(std::string name)
{
   std::list<std::shared_ptr<Card>>::iterator it;
   for (it = cards.begin(); it != cards.end(); ++it)
   {
      if (it->get()->is_same_name(name))
         return it;
   }

   return it;
}

void Deck::display() const 
{
   std::cout << "Deck ID: " << id 
             << " Name: " << name 
             << std::endl;
}

void Deck::display_cards() const
{
   display();
   for_each(cards.begin(), cards.end(), [](auto& card)
      {
         card->display();
      });
   int pokemons = count(POKEMON);
   int trainers = count(TRAINER);
   int energies = count(ENERGY);
   std::cout << "Pokemons: " << pokemons << std::endl;
   std::cout << "Trainers: " << trainers << std::endl;
   std::cout << "Energies: " << energies << std::endl;
   std::cout << "Total:    " << pokemons + trainers + energies << std::endl;
}

void Deck::prompt_for_card()
{
   std::string type_string;
   CardType type;

   std::cout << "Enter the type of card: ";
   std::cin >> type_string;
   std::cout << std::endl;

   type = stringToCardType(type_string);

   if (type == TRAINER)
   {
      std::shared_ptr<Trainer> trainer = std::make_shared<Trainer>(type);
      trainer->prompt_for_information();

      cards.push_back(trainer);
   }
   else if (type == POKEMON)
   {
      std::shared_ptr<Pokemon> pokemon = std::make_shared<Pokemon>(type);
      pokemon->prompt_for_information();

      cards.push_back(pokemon);
   }
   else if (type == ENERGY)
   {
      std::shared_ptr<Energy> energy = std::make_shared<Energy>(type);
      energy->prompt_for_information();

      cards.push_back(energy);
   }
}

void Deck::prompt_for_information()
{
   std::cin.ignore();
   std::cout << "Enter the name for the deck: ";
   getline(std::cin, name);
   std::cout << std::endl;
}

bool Deck::is_same_id(int id) const
{
   return this->id == id;
}

std::string Deck::encode() const
{
   std::string encoding = "Deck#" + name + "\n";
   for_each(cards.begin(), cards.end(), [&encoding](auto& card)
      {
         encoding += card->encode() + "\n";
      });
   return encoding;
}

void Deck::decode(std::string encoding)
{
   //          Name
   // Example: Deck#Veracruz
   std::list<std::string> parts = split(encoding, '#');
   std::list<std::string>::iterator it = parts.begin();
   name = *(++it);
}