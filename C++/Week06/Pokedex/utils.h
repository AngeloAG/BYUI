#pragma once
#include <list>
#include <string>
#include <sstream>

inline std::list<std::string> split(const std::string& string_to_split, char delimiter)
{
   std::list<std::string> parts;
   std::stringstream string_stream (string_to_split);
   std::string element;

   while (getline(string_stream, element, delimiter))
   {
      element.erase(std::remove(element.begin(), element.end(), '\n'), element.cend());
      parts.push_back(element);
   }

   return parts;
}