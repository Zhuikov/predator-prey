#include <QString>
#include <QtTest>
#include <cmath>
#include "field.h"
#include "coordinates.h"
#include "modelpp.h"
#include "predator.h"

class ModelTest : public QObject
{
    Q_OBJECT

public:
    ModelTest();

private Q_SLOTS:
    int doubleCompare(double a, double b);

    void coordinatesTest();
    void fieldTest();
    void predatorTest();
    void modelppInitializeTest();
    void debugTest();
};

ModelTest::ModelTest() {}

int ModelTest::doubleCompare(double a, double b)
{
    if (fabs(a - b) < 10e-3) return 1;
    return 0;
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

    QCOMPARE(A.getI(), 0);
    A.setJ(110000);
    QCOMPARE(A.getJ(), 110000);
}

void ModelTest::fieldTest()
{
    Field field(5, 7);

    QCOMPARE(field.getNumOfCols(), 7);
    QCOMPARE(field.getNumOfRows(), 5);
    QCOMPARE(field.isEmpty(0, 0), true);
    QCOMPARE(field.isEmpty(4, 2), true);
    QCOMPARE(field.isEmpty(2, 5), true);
    QCOMPARE(field.isEmpty(4, 6), true);
    QCOMPARE(field.isEmpty(5, 7), false);
    QCOMPARE(field.isEmpty(9, 9), false);
    QCOMPARE(field.isEmpty(-1, 0), false);
    QCOMPARE(field.isEmpty(5, -1), false);
    QCOMPARE(field.isEmpty(0, -2), false);
    QCOMPARE(field.isEmpty(-1, 1), false);
    QCOMPARE(field.isEmpty(10, 9), false);
    QCOMPARE(field.getChar(2, 5), '.');

    field.setPosition(1, 4, 'X');
    QCOMPARE(field.isEmpty(1, 4), false);
    QCOMPARE(field.whatIsEmpty(4, 0), 'u');
    QCOMPARE(field.whatIsEmpty(0, 0), 'r');
    QCOMPARE(field.whatIsEmpty(1, 4), 'u');
    QCOMPARE(field.whatIsEmpty(2, 4), 'r');
    QCOMPARE(field.whatIsEmpty(0, 6), 'd');

    field.setPosition(0, 1, 'X');
    field.setPosition(1, 0, 'O');
    QCOMPARE(field.isEmpty(0, 0), true);
    QCOMPARE(field.whatIsEmpty(0, 0), '0');

    field.setPosition(2, 5, 'X');
    field.setPosition(3, 4, 'O');
    QCOMPARE(field.whatIsEmpty(2, 4), 'l');

    Field field2(10, 10);
    field2 = field;
    QCOMPARE(field2.getChar(2, 5), 'X');
    QCOMPARE(field2.getChar(3, 4), 'O');
    QCOMPARE(field2.isEmpty(-1, 0), false);
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

    field.setPosition(3, 4, 'S');
    field.setPosition(4, 5, 'T');
    field.setPosition(5, 4, 'O');
    field.setPosition(4, 3, 'P');
    units.predators[0]->movePredator();
    QCOMPARE(tst_predator->my_place.getI(), 4);
    QCOMPARE(tst_predator->my_place.getJ(), 4);
    field.setPosition(3, 4, '.');
    field.setPosition(4, 5, '.');
    field.setPosition(5, 4, '.');
    field.setPosition(4, 3, '.');

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getI(), 3);
    QCOMPARE(tst_predator->my_place.getJ(), 4);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getI(), 3);
    QCOMPARE(tst_predator->my_place.getJ(), 3);
    QCOMPARE(units.preys.empty(), true);

    Prey* tst_prey2 = new Prey(2, 3, &field);
    tst_prey2->setPtrs(&units);
    units.preys.push_back(tst_prey2);

    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getI(), 2);
    QCOMPARE(tst_predator->my_place.getJ(), 3);
    int pred_size = units.predators.size();
    QCOMPARE(pred_size, 2);

    Prey *tst_prey3 = new Prey(1, 2, &field);
    tst_prey3->setPtrs(&units);
    units.preys.push_back(tst_prey3);

    units.predators[0]->movePredator();
    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->my_place.getI(), 1);
    QCOMPARE(tst_predator->my_place.getJ(), 2);
    int prey_size = units.preys.size();
    QCOMPARE(prey_size, 0);


}

void ModelTest::modelppInitializeTest()
{
    Settings sett;
    ModelPP model(&sett);

    model.initializeModel();
    QCOMPARE(model.getDay(), 0);
    QCOMPARE(model.getTime(), 0);

    model.movePreys();
    model.movePredators();
    QCOMPARE(model.getDay(), 0);
    QCOMPARE(model.getTime(), 2);

    model.movePredators();
    model.movePreys();
    QCOMPARE(model.getTime(), 4);

    QCOMPARE(model.isEnd(), false);
}

void ModelTest::debugTest()
{
    Field field(10, 10);
    Units units;
    Predator *tst_pred1 = new Predator(8, 9, &field);
    tst_pred1->setPtrs(&units);
    Predator *tst_pred2 = new Predator(9, 9, &field);
    tst_pred2->setPtrs(&units);
    Predator *tst_pred3 = new Predator(0, 0, &field);
    tst_pred3->setPtrs(&units);
    units.predators.push_back(tst_pred1);
    units.predators.push_back(tst_pred2);
    units.predators.push_back(tst_pred3);

    Prey *tst_prey1 = new Prey(0, 1, &field);
    tst_prey1->setPtrs(&units);
    Prey *tst_prey2 = new Prey(0, 3, &field);
    tst_prey2->setPtrs(&units);
    Prey *tst_prey3 = new Prey(0, 9, &field);
    tst_prey3->setPtrs(&units);
//    Prey *tst_prey4 = new Prey(0, 2, &field);
//    tst_prey4->setPtrs(&units);
//    Prey *tst_prey5 = new Prey(0, 4, &field);
//    tst_prey5->setPtrs(&units);
    units.preys.push_back(tst_prey1);
    units.preys.push_back(tst_prey2);
    units.preys.push_back(tst_prey3);
//    units.preys.push_back(tst_prey4);
//    units.preys.push_back(tst_prey5);

    int a = 0;           // количество ходов для хищников
    while (a < 30) {
    for (std::vector<Predator*>::iterator i = units.predators.begin();
         i != units.predators.end(); i++) {
            (*i)->movePredator();
    }
    a++;
    }

    /* С закомментированными строчками (199 - 202, 206 - 207) все работает как надо.
     * В этих строках создается еще пара жертв, что позволяет хищнику их съесть
     * и породить еще одного, уже второго. Затем выскакивает segm. fault.
     * Причина - какой-то рандомный хищник, у которого ничего не инициализированно.
     * В векторе хищников predators его его адреса даже нет.
     *
     * p.s структура тестов, наверно, убогая
     * ...да и не только тестов)
     */
}

QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
