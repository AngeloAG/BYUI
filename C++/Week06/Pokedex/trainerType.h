#pragma once
#include <string>

enum TrainerType { SUPPORTER, ITEM, STADIUM, TOOL, INVALID_TRAINER };

std::string trainerTypeToString(TrainerType type);

TrainerType stringToTrainerType(std::string type);