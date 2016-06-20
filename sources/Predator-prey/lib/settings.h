#ifndef SETTINGS_H
#define SETTINGS_H
//#include "field.h"
#include "badfield.h"
#include "badnum.h"

/**
 * @brief класс, содержащий настройки модели
 */
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
     * @brief num_of_predators - текущее число хищников
     */
    int num_of_predators;

    /**
     * @brief num_of_preys - текущее число жертв
     */
    int num_of_preys;

    /**
     * @brief moves_without_meal - текущее время жизни животного без еды
     */
    int moves_without_meal;

    /**
     * @brief min_moves_without_meal - минимальное время жизни животного без еды
     */
    int min_moves_without_meal;

    /**
     * @brief max_moves_without_meal - максимальное время жизни животного без еды
     */
    int max_moves_without_meal;

    /**
     * @brief метод, проверяющий число хищников и жертв;
     * если число больше максимально допустимого при текущих настройках поля,
     * устанавливается максимально возможное
     */
    void checkNumOfUnits();

public:

    Settings(int field_length_ = 10, int field_height_ = 10, int num_of_predators_ = 3, int num_of_preys_ = 3,
             int moves_without_meal_ = 20, int min_moves_without_meal_ = 5, int max_moves_without_meal_ = 1000);

    /**
     * @brief методы, возвращающие информацию о текущих настройках
     */
    int getFieldLength() const { return field_length; }
    int getFieldHeight() const { return field_height; }
    int getNumOfPreys()  const { return num_of_preys; }
    int getNumOfPredators()   const { return num_of_predators; }
    int getMovesWithoutMeal() const { return moves_without_meal; }
    int getMinMovesWithoutMeal() const { return min_moves_without_meal; }
    int getMaxMovesWithoutMeal() const { return max_moves_without_meal; }
    int getMaxUnits() const;

    /**
     * @brief методы, устанавливающие новые настройки;
     * при неоходимости генерируют исключения
     */
    void setFieldLength(const int);
    void setFieldHeight(const int);
    void setNumOfPredators(const int);
    void setNumOfPreys(const int);
    void setMovesWithoutMeal(const int);

};

#endif // SETTINGS_H
