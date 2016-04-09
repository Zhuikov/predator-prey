#include <QString>
#include <QtTest>
#include <cmath>
#include "field.h"
#include "point.h"
#include "predator.h"

class ModelTest : public QObject
{
    Q_OBJECT

public:
    ModelTest();

private Q_SLOTS:
    int doubleCompare(double a, double b);

    void pointTest();
    void fieldTest();
    void predatorTest();
};

ModelTest::ModelTest() {}

int ModelTest::doubleCompare(double a, double b)
{
    if (fabs(a - b) < 10e-3) return 1;
    return 0;
}

void ModelTest::pointTest()
{
    Point A(0, 0), B(3, 4), C(-10, 10);
    double dist1, dist2, dist3;
    dist1 = B - A;
    dist2 = C - A;
    dist3 = B - C;
    QVERIFY2(doubleCompare(dist1, 5), "wrong distance between points");
    QVERIFY2(doubleCompare(dist2, 14.142), "wrong distance between points");
    QVERIFY2(doubleCompare(dist3, 14.318), "wrong distance between points");

    QCOMPARE(A.getX(), 0);
    A.setY(110000);
    QCOMPARE(A.getY(), 110000);
}

void ModelTest::fieldTest()
{
    Field field(5, 7);

    QCOMPARE(field.getNumOfCols(), 7);
    QCOMPARE(field.getNumOfRows(), 5);
    QCOMPARE(field.isEmpty(0, 0), 1);
    QCOMPARE(field.isEmpty(4, 2), 1);
    QCOMPARE(field.isEmpty(2, 5), 1);
    QCOMPARE(field.isEmpty(4, 6), 1);
    QCOMPARE(field.isEmpty(5, 7), 0);
    QCOMPARE(field.getChar(2, 5), '.');

    field.setPosition(1, 4, 'X');
    QCOMPARE(field.isEmpty(1, 4), 0);
    QCOMPARE(field.whatIsEmpty(4, 0), 'u');
    QCOMPARE(field.whatIsEmpty(0, 0), 'r');
    QCOMPARE(field.whatIsEmpty(1, 4), 'u');
    QCOMPARE(field.whatIsEmpty(2, 4), 'r');
    QCOMPARE(field.whatIsEmpty(0, 6), 'd');

    field.setPosition(2, 5, 'X');
    field.setPosition(3, 4, 'O');
    QCOMPARE(field.whatIsEmpty(2, 4), 'l');

    Field field2(10, 10);
    field2 = field;
    QCOMPARE(field2.getChar(2, 5), 'X');
    QCOMPARE(field2.getChar(3, 4), 'O');
    QCOMPARE(field2.whatIsEmpty(2, 4), 'l');
    QCOMPARE(field2.getNumOfRows(), 5);
    QCOMPARE(field2.getNumOfCols(), 7);

}

void ModelTest::predatorTest()
{
    Field field(10, 10);
    Units units;

    Prey* tst_prey = new Prey(3, 3, &field);
    tst_prey->setPtrs(&units);
    Predator* tst_predator = new Predator(4, 4, &field);
    tst_predator->setPtrs(&units);
    units.predators.push_back(tst_predator);
    units.preys.push_back(tst_prey);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getX(), 3);
    QCOMPARE(tst_predator->my_place.getY(), 4);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getX(), 3);
    QCOMPARE(tst_predator->my_place.getY(), 3);
    QCOMPARE(units.preys.empty(), true);

    Prey* tst_prey2 = new Prey(2, 3, &field);
    tst_prey2->setPtrs(&units);
    units.preys.push_back(tst_prey2);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getX(), 2);
    QCOMPARE(tst_predator->my_place.getY(), 3);
    int pred_size = units.predators.size();
    QCOMPARE(pred_size, 2);

}

QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
