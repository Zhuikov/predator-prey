#ifndef SETTINGS_H
#define SETTINGS_H
#include "modelpp.h"

class Settings
{
    int field_length;
    int field_height;
    int day_without_meal;
    int num_of_predators;
    int num_of_preys;

    friend class ModelPP;

public:
    Settings();
};

#endif // SETTINGS_H
