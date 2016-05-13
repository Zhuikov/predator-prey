#include "settings.h"
#include "field.h"
#include "badfield.h"
#include "badnum.h"

Settings::Settings():
    field_length(10),
    field_height(10),
    moves_without_meal(20),
    min_moves_without_meal(5),
    max_moves_without_meal(1000),
    num_of_predators(3),
    num_of_preys(3)
{}

int Settings::getMaxUnits() const
{
    int max_num;
    max_num = std::max(field_height, field_length) * 2;

    return max_num;
}

void Settings::setFieldLength(const int length)
{
    if (length < Field::MIN_FIELD_SIZE || length > Field::MAX_FIELD_SIZE) {
        throw BadFieldLength(length);
    }
    this->field_length = length;
}

void Settings::setFieldHeight(const int height)
{
    if (height < Field::MIN_FIELD_SIZE || height > Field::MAX_FIELD_SIZE) {
        throw BadFieldHeight(height);
    }
    this->field_height = height;
}

void Settings::setMovesWithoutMeal(const int moves)
{
    if (moves < min_moves_without_meal || moves > max_moves_without_meal) {
        throw BadNum(moves, min_moves_without_meal, max_moves_without_meal);
    }
    this->moves_without_meal = moves;
}

void Settings::setNumOfPredators(const int num)
{
    int MAX_NUM = this->getMaxUnits();

    if (num < 1 || num > MAX_NUM) {
        throw BadNum(num, 1, MAX_NUM);
    }
    this->num_of_predators = num;
}

void Settings::setNumOfPreys(const int num)
{
    int MAX_NUM = this->getMaxUnits();

    if (num < 1 || num > MAX_NUM) {
        throw BadNum(num, 1, MAX_NUM);
    }
    this->num_of_preys = num;
}
