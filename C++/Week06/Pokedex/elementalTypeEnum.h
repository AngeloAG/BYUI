#pragma once
#include<string>

enum ElementalType { GRASS, ELECTRIC, DRAGON, WATER, FIRE, STEEL, FIGHTING, PSYCHIC, DARK, COLORLESS, INVALID };

std::string elementalTypeToString(ElementalType type);

ElementalType stringToElementalType(std::string type);