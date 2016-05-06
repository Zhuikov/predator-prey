#include <QString>
#include <QtTest>
#include <cmath>
#include "field.h"
#include "coordinates.h"
#include "badfield.h"
#include "badboundary.h"
#include "model.h"
#include "predator.h"

//TODO: сделать отдельный проект с функциональными тестами и добавить их
class ModelTest : public QObject
{
    Q_OBJECT

public:
    ModelTest();

private Q_SLOTS:
    int doubleCompare(double a, double b);
    void moveEnd(Units*);

    void coordinatesTest();
    void fieldTest();
    void predatorMoveTest();
    void predatorCreateTest();
    void predatorMoveKillTest();
    void predatorPriorityTest();
    void predatorHungryTest();
    void twoPredatorsTest();
    void modelppInitializeTest();
    void debugTest();
};

ModelTest::ModelTest() {}

int ModelTest::doubleCompare(double a, double b)
{
    if (fabs(a - b) < 10e-3) return 1;
    return 0;
}

//TODO: думаю, этот тест нереально понять никому, кроме автора
void ModelTest::moveEnd(Units *units)
{
    int num_of_died = 0;
    for (unsigned int i = 0; i < units->predators.size(); i++) {
        if (units->predators[i]->died == true)
            num_of_died ++;
    }

    int num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (unsigned int i = 0; i < units->predators.size(); i++) {
            if (units->predators[i]->died == true) {
                delete units->predators[i];
                if (units->predators[i] != units->predators.back())
                    std::swap(units->predators[i], units->predators.back());
                units->predators.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }

    num_of_died = 0;
    for (unsigned int i = 0; i < units->preys.size(); i++) {
        if (units->preys[i]->died == true)
            num_of_died ++;
    }

    num_deleted_died = 0;
    while (num_deleted_died < num_of_died) {
        for (unsigned int i = 0; i < units->preys.size(); i++) {
            if (units->preys[i]->died == true) {
                delete units->preys[i];
                if (units->preys[i] != units->preys.back())
                    std::swap(units->preys[i], units->preys.back());
                units->preys.pop_back();
                num_deleted_died ++;
                break;
            }
        }
    }
}

void ModelTest::coordinatesTest()
{
    Coordinates A(0, 0), B(3, 4), C(-10, 10);
    double dist1, dist2, dist3;
    dist1 = B - A;
    dist2 = C - A;
    dist3 = B - C;
    QVERIFY2(doubleCompare(dist1, 5), "wrong distance between points");
    QVERIFY2(doubleCompare(dist2, 14.142), "wrong distance between points");
    QVERIFY2(doubleCompare(dist3, 14.318), "wrong distance between points");

    QCOMPARE(A.getV(), 0);
    A.setH(110000);
    QCOMPARE(A.getH(), 110000);

    A.setV(15); A.setH(15);
    B.setV(15); B.setH(15);
    QCOMPARE(A == B, true);
    QCOMPARE(A != B, false);

    B.setH(16);
    QCOMPARE(A != B, true);
    QCOMPARE(A == B, false);

    Coordinates D;
    QCOMPARE(D.getV(), 0);
    QCOMPARE(D.getH(), 0);
}

//TODO: очень длинный тест, надо разбить на несколько поменьше, на каждую тестируемую функциональность
void ModelTest::fieldTest()
{
    Field field;

    QCOMPARE(field.getLength(), 10);
    QCOMPARE(field.getHeight(), 10);
    QCOMPARE(field.isEmpty(0, 0), true);
    QCOMPARE(field.isEmpty(4, 2), true);
    QCOMPARE(field.isEmpty(10, 10), false);
    QCOMPARE(field.isEmpty(-1, 0), false);
    QCOMPARE(field.isEmpty(0, -2), false);
    QCOMPARE(field.isEmpty(-1, 1), false);
    QCOMPARE(field.isEmpty(10, 9), false);
    QCOMPARE(field.getPosition(2, 5), Position::EMPTY);

    field.setPosition(1, 4, Position::PREDATOR);
    QCOMPARE(field.isEmpty(1, 4), false);
    QCOMPARE(field.whatIsEmpty(4, 0), Direction::UP);
    QCOMPARE(field.whatIsEmpty(0, 0), Direction::RIGHT);
    QCOMPARE(field.whatIsEmpty(1, 4), Direction::UP);
    QCOMPARE(field.whatIsEmpty(2, 4), Direction::RIGHT);
    QCOMPARE(field.whatIsEmpty(0, 9), Direction::DOWN);
    QVERIFY_EXCEPTION_THROWN(field.whatIsEmpty(10, 3), BadFieldBoundary);

    field.setPosition(0, 1, Position::PREDATOR);
    field.setPosition(1, 0, Position::PREY);
    QCOMPARE(field.isEmpty(0, 0), true);
    QCOMPARE(field.whatIsEmpty(0, 0), Direction::NO_DIRECTION);

    field.setPosition(2, 5, Position::PREDATOR);
    field.setPosition(3, 4, Position::PREY);
    QVERIFY_EXCEPTION_THROWN(field.setPosition(-1, 0, Position::PREDATOR), BadFieldBoundary);
    QVERIFY_EXCEPTION_THROWN(field.setPosition(10, 10, Position::PREY), BadFieldBoundary);
    QCOMPARE(field.whatIsEmpty(2, 4), Direction::LEFT);

}

void ModelTest::predatorMoveTest()
{
    Field field;
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    field.setPosition(3, 4, Position::PREDATOR);
    field.setPosition(4, 5, Position::PREDATOR);
    field.setPosition(5, 4, Position::PREDATOR);
    field.setPosition(4, 3, Position::PREDATOR);

    tst_predator->movePredator();
    QCOMPARE(tst_predator->place.getV(), 4);
    QCOMPARE(tst_predator->place.getH(), 4);

}

void ModelTest::predatorMoveKillTest()
{
    Field field(10, 10);
    Units units;

    new Prey(3, 3, &field, &units);
    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->place.getV(), 4);
    QCOMPARE(tst_predator->place.getH(), 3);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->place.getV(), 3);
    QCOMPARE(tst_predator->place.getH(), 3);
    moveEnd(&units);
    QCOMPARE(units.preys.empty(), true);
}

void ModelTest::predatorCreateTest()
{
    Field field(10, 10);
    Units units;

    new Prey(3, 3, &field, &units);
    new Prey(2, 3, &field, &units);
    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    tst_predator->movePredator();
    tst_predator->movePredator();
    tst_predator->movePredator();

    QCOMPARE(tst_predator->place.getV(), 2);
    QCOMPARE(tst_predator->place.getH(), 3);
    int pred_size = units.predators.size();
    QCOMPARE(pred_size, 2);

}

void ModelTest::predatorHungryTest()
{
    Field field;
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    for (int i = 0; i < 20; i++) {
        tst_predator->movePredator();
    }
    moveEnd(&units);
    int pred_size = units.predators.size();
    QCOMPARE(pred_size, 0);

}

void ModelTest::twoPredatorsTest()
{
    Field field;
    Units units;

    Predator* tst_predator1 = new Predator(4, 5, &field, &units, 20);
    Predator* tst_predator2 = new Predator(2, 3, &field, &units, 20);
    new Prey(3, 4, &field, &units);

    tst_predator1->movePredator();
    tst_predator2->movePredator();
    moveEnd(&units);
    tst_predator1->movePredator();
    tst_predator2->movePredator();
    moveEnd(&units);
    QCOMPARE(units.preys.empty(), true);

    field.setPosition(tst_predator1->place.getV(), tst_predator1->place.getH(), Position::EMPTY);
    field.setPosition(tst_predator2->place.getV(), tst_predator2->place.getH(), Position::EMPTY);
    tst_predator1->died = true;
    tst_predator2->died = true;
    moveEnd(&units);
    QCOMPARE(units.predators.empty(), true);

}

void ModelTest::predatorPriorityTest()
{
    Field field(10, 10);
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);
    new Prey(3, 3, &field, &units);
    new Prey(5, 4, &field, &units);

    tst_predator->movePredator();

    QCOMPARE(tst_predator->place.getV(), 5);
    QCOMPARE(tst_predator->place.getH(), 4);
}

void ModelTest::modelppInitializeTest()
{
    Settings sett;
    Model model(&sett);

    QCOMPARE(model.getDay(), 0);
    QCOMPARE(model.getTime(), 0);

    model.movePreys();
    model.movePredators();
    model.remove();
    QCOMPARE(model.getDay(), 0);
    QCOMPARE(model.getTime(), 1);

    model.movePredators();
    model.movePreys();
    model.remove();
    QCOMPARE(model.getTime(), 2);

    QCOMPARE(model.isEnd(), false);
}

//TODO: слишком общее название для такого длинного теста
void ModelTest::debugTest()
{
    Field field(10, 10);
    Units units;
    new Predator(8, 9, &field, &units, 5);
    new Predator(9, 9, &field, &units, 5);
    new Predator(0, 0, &field, &units, 5);

    new Prey(0, 1, &field, &units);
    new Prey(0, 3, &field, &units);
    new Prey(0, 2, &field, &units);
    new Prey(0, 4, &field, &units);

    int num_of_predators_moves = 0;
    while (num_of_predators_moves < 5) {
        for (unsigned int i = 0; i < units.predators.size(); i++) units.predators[i]->movePredator();
        moveEnd(&units);
        num_of_predators_moves ++;
    }
    moveEnd(&units);
    int final_vec_size = units.predators.size();
    QCOMPARE(final_vec_size, 3);

}

QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
