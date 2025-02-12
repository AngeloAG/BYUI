/*
* Author: Angelo Arellano Gaona
*/


#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include "deck.h"

using namespace std;
const std::string FILENAME = "save.txt";

list<Deck>::iterator find_deck(list<Deck>&, int);
int prompt_for_deck_id();

int main()
{
   list<Deck> decks;

   bool keep_asking = true;
   while (keep_asking)
   {
      int choice = 9;
      cout << endl;
      cout << "Account Menu:\n"
         << "0. Quit Program\n"
         << "1. Display  decks\n"
         << "2. Add a card to a deck\n"
         << "3. Remove card from deck\n"
         << "4. Add new deck\n"
         << "5. Find deck by ID\n"
         << "6. Remove deck\n"
         << "7. Display cards from deck\n"
         << "Your choice: ";
      cin >> choice;
      cout << endl;

      switch (choice)
      {
      case 0:
         cout << "Thanks for using the pokedex";
         keep_asking = false;
         break;
      case 1:
      {
         for_each(decks.begin(), decks.end(), [](auto& deck)
            {
               deck.display();
            });
         break;
      }
      case 2:
      {
         int id_to_find = prompt_for_deck_id();
         list<Deck>::iterator deckIt = find_deck(decks, id_to_find);
         if (deckIt != decks.end())
         {
            cout << "Found deck: ";
            deckIt->display();
            cout << endl;
            deckIt->prompt_for_card();
         }
         else
         {
            cout << "Deck not found." << endl;
         }
         break;
      }
      case 3:
      {
         int id_to_find = prompt_for_deck_id();
         list<Deck>::iterator deckIt = find_deck(decks, id_to_find);
         if (deckIt != decks.end())
         {
            cout << "Found deck: ";
            deckIt->display();
            cout << endl;
            string card_to_remove;
            std::cout << "Enter the card name to remove: ";
            std::cin >> card_to_remove;
            std::cout << std::endl;

            deckIt->remove_card(card_to_remove);
         }
         else
         {
            cout << "Deck not found." << endl;
         }
         break;
      }
      case 4:
      {
         Deck new_deck;
         new_deck.prompt_for_information();
         decks.push_back(new_deck);
         break;
      }
      case 5:
      {
         int id_to_find = prompt_for_deck_id();
         list<Deck>::iterator deckIt = find_deck(decks, id_to_find);
         if (deckIt != decks.end())
         {
            cout << "Found deck: ";
            deckIt->display();
            cout << endl;
         }
         else
         {
            cout << "Deck not found." << endl;
         }
         break;
      }
      case 6:
      {
         int id_to_find = prompt_for_deck_id();
         auto decks_end = remove_if(decks.begin(), decks.end(), [id_to_find](auto& deck)
            {
               return deck.is_same_id(id_to_find);
            });
         if (decks_end != decks.end())
            decks.erase(decks_end, decks.end());
         else
            cout << "Deck not found." << endl;
         break;
      }
      case 7:
      {
         int id_to_find = prompt_for_deck_id();
         list<Deck>::iterator deckIt = find_deck(decks, id_to_find);
         if (deckIt != decks.end())
         {
            cout << "Found deck: ";
            deckIt->display_cards();
            cout << endl;
         }
         else
         {
            cout << "Deck not found." << endl;
         }
         break;
      }
      case 8:
      {
         ifstream file(FILENAME);
         if (file.is_open())
         {
            string line;
            while (std::getline(file, line))
            {
               // using printf() in all tests for consistency
               printf("%s", line.c_str());
            }
            file.close();
         }
      }
      case 9:
      {
         ofstream file(FILENAME);
         if (file.is_open())
         {
            for_each(decks.begin(), decks.end(), [](auto& deck)
               {
                  deck.display();
               });
         }
      }
      default:
         cout << "Invalid option, try again." << endl;
         break;
      }
   }
}

/*
* function to find a deck in a list of decks
*/
list<Deck>::iterator find_deck(list<Deck>& decks, int id_to_find)
{
   list<Deck>::iterator it;
   for (it = decks.begin(); it != decks.end(); ++it)
   {
      if (it->is_same_id(id_to_find))
         return it;
   }

   return it;
}

/*
* function to reuse the prompting mechanism
*/
int prompt_for_deck_id()
{
   int id_to_find = 0;
   cout << "Enter the Id of the deck to find: ";
   cin >> id_to_find;
   cout << endl;
   return id_to_find;
}