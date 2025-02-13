#pragma once
#include <memory>
#include <list>
#include "card.h"

class Deck
{
private:
   std::string name;
   std::list<std::shared_ptr<Card>> cards;
   static int available_id;
   int id;

public:
   Deck();
   Deck(std::string name);
   void add_card(std::shared_ptr<Card> card);
   void remove_card(std::string name);
   int count(CardType type) const;
   std::list<std::shared_ptr<Card>>::iterator find_card(std::string name);
   void display() const;
   void display_cards() const;
   void prompt_for_card();
   void prompt_for_information();
   bool is_same_id(int id) const;
   std::string encode() const;
   void decode(std::string encoding);
};