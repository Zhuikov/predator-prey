#include "settings.h"

Settings::Settings(int field_length_, int field_height_, int num_of_predators_, int num_of_preys_,
                   int num_of_grass_, int grow_interval_, int seed_,
                   int moves_without_meal_, int min_moves_without_meal_, int max_moves_without_meal_):
    field_length(field_length_),
    field_height(field_height_),
    num_of_predators(num_of_predators_),
    num_of_preys(num_of_preys_),
    num_of_grass(num_of_grass_),
    grow_interval(grow_interval_),
    seed(seed_),
    moves_without_meal(moves_without_meal_),
    min_moves_without_meal(min_moves_without_meal_),
    max_moves_without_meal(max_moves_without_meal_)
{}

int Settings::getMaxUnits() const
{
    int max_num;
    max_num = std::max(field_height, field_length) * 50; // 2

    return max_num;
}

void Settings::checkNumOfUnits()
{
    if (num_of_predators > getMaxUnits()) {
        setNumOfPredators(getMaxUnits());
    }
    if (num_of_preys > getMaxUnits()) {
        setNumOfPreys(getMaxUnits());
    }
}

void Settings::setFieldLength(const int length)
{
    if (length < Field::MIN_FIELD_SIZE || length > Field::MAX_FIELD_SIZE) {
        throw BadFieldLength(length);
    }
    this->field_length = length;
    checkNumOfUnits();
}

void Settings::setFieldHeight(const int height)
{
    if (height < Field::MIN_FIELD_SIZE || height > Field::MAX_FIELD_SIZE) {
        throw BadFieldHeight(height);
    }
    this->field_height = height;
    checkNumOfUnits();
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

void Settings::setNumOfGrass(const int num)
{
    int MAX_NUM = this->getMaxUnits();

    if (num < 1 || num > MAX_NUM) {
        throw BadNum(num, 1, MAX_NUM);
    }
    this->num_of_grass = num;
}

void Settings::setGrowInterval(const int num)
{
    int MAX_NUM = this->max_moves_without_meal;

    if (num < 1 || num > MAX_NUM) {
        throw BadNum(num, 1, MAX_NUM);
    }
    this->grow_interval = num;
}

void Settings::setSeed(const int seed)
{
    this->seed = seed;
}
