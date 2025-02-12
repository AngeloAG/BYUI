#pragma once
#include<string>

enum CardType { TRAINER, POKEMON, ENERGY, INVALID_CARD };

std::string cardTypeToString(CardType type);

CardType stringToCardType(std::string type);