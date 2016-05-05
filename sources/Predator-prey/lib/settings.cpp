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

void Settings::setFieldLength(const int length)
{
    if (length < Field::MIN_FIELD_SIZE || length > Field::MAX_FIELD_SIZE) throw BadFieldCreate();
    this->field_length = length;
}

void Settings::setFieldHeight(const int height)
{
    if (height < Field::MIN_FIELD_SIZE || height > Field::MAX_FIELD_SIZE) throw BadFieldCreate();
    this->field_height = height;
}

void Settings::setMovesWithoutMeal(const int moves)
{
    if (moves < min_moves_without_meal || moves > max_moves_without_meal) throw BadNum();
    this->moves_without_meal = moves;
}

void Settings::setNumOfPredators(const int num)
{
    int MAX_NUM = std::max(field_height, field_length) * 2;

    if (num < 1 || num > MAX_NUM) throw BadNum();
    this->num_of_predators = num;
}

void Settings::setNumOfPreys(const int num)
{
    int MAX_NUM = std::max(field_height, field_length) * 2;

    if (num < 1 || num > MAX_NUM) throw BadNum();
    this->num_of_preys = num;
}
