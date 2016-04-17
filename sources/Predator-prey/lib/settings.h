#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
    int field_length;
    int field_height;
    int moves_without_meal;
    int max_moves_without_meal;
    int num_of_predators;
    int num_of_preys;

    friend class ModelPP;
    friend class Field;
    friend class ConsoleDialog;

public:
    Settings();
};

#endif // SETTINGS_H
