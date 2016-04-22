#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
    /**
     * @brief field_length - текущая длина поля
     */
    int field_length;

    /**
     * @brief field_height - текущая ширина (высота) поля
     */
    int field_height;

    /**
     * @brief moves_without_meal - текущее время жизни животного без еды
     */
    int moves_without_meal;

    /**
     * @brief max_moves_without_meal - максимальное время
     * жизни животного без еды
     */
    int max_moves_without_meal;

    /**
     * @brief num_of_predators - текущее число хищников
     */
    int num_of_predators;

    /**
     * @brief num_of_preys - текущее число жертв
     */
    int num_of_preys;

    friend class Model;
    friend class Field;
    friend class ConsoleDialog;

public:
    Settings();
};

#endif // SETTINGS_H
