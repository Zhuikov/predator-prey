#include <QString>
#include <QtTest>
#include <cmath>
#include "field.h"
#include "coordinates.h"
#include "badfield.h"
#include "badboundary.h"
#include "badnum.h"
#include "model.h"
#include "predator.h"
#include "movement.h"
#include "sense.h"
#include "prey.h"
#include "grass.h"
#include "predator.h"

//TODO: сделать отдельный проект с функциональными тестами и добавить их
class ModelTest : public QObject
{
    Q_OBJECT

public:
    ModelTest();

private Q_SLOTS:
    int doubleCompare(double a, double b);

    void coordinatesTest();
    void fieldTest();
    void predatorNoMoveTest();
    void predatorHungryTest();
    void modelInitializeTest();
    void debugTest2();
    void moveTest();
    void moveApartTest();
    void SFTest();
    void senseTest();
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
    QVERIFY(field.getPosition(2, 5) == nullptr);

    Units units;
    new Predator(1, 4, &field, &units, 20);
    QCOMPARE(field.isEmpty(1, 4), false);

    new Predator(0, 1, &field, &units, 20);
    new Prey(1, 0, &field, &units, 20);
    QCOMPARE(field.isEmpty(0, 0), true);

    new Predator(2, 5, &field, &units, 20);
    new Prey(3, 4, &field, &units, 20);

}

void ModelTest::predatorNoMoveTest()
{
    Field field;
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    new Predator(3, 4, &field, &units, 20);
    new Predator(3, 3, &field, &units, 20);
    new Predator(4, 5, &field, &units, 20);
    new Predator(5, 5, &field, &units, 20);
    new Predator(5, 4, &field, &units, 20);
    new Predator(4, 3, &field, &units, 20);
    new Predator(3, 5, &field, &units, 20);
    new Predator(5, 3, &field, &units, 20);
    tst_predator->move();
    QCOMPARE(tst_predator->getPlace().getV(), 4);
    QCOMPARE(tst_predator->getPlace().getH(), 4);

}

void ModelTest::predatorHungryTest()
{
    Field field;
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    for (int i = 0; i < 20; i++) {
        tst_predator->move();
    }
    QCOMPARE(units.predatorsNum, 0);
}

void ModelTest::modelInitializeTest()
{
    Settings sett;
    Model model(&sett);

    QCOMPARE(model.getStep(), 0);

    model.move();
    QCOMPARE(model.getStep(), 1);

    model.move();
    QCOMPARE(model.getStep(), 2);
}

void ModelTest::debugTest2()
{
    Field field;
    Units units;

    new Predator(4, 5, &field, &units, 20);
    Movement movement(Coordinates(4, 4), &field);
    movement.setSpeed(1);
    movement.setTarget(Coordinates(4, 6));

    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(4, 4));

}

void ModelTest::moveTest()
{
    Field field(20, 20);
    Movement movement(Coordinates(0, 0), &field);
    movement.setTarget(Coordinates(5, 5));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(1, 1));
    movement.setSpeed(3);
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(4, 4));
    movement.setSpeed(7.2);
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 5));
    movement.setTarget(Coordinates(5, 15));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 13));
    movement.setTarget(Coordinates(5, 5));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 5));
    movement.setSpeed(3);
    movement.setTarget(Coordinates(0,0));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(2, 2));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(0, 0));


}

void ModelTest::moveApartTest()
{
    Field field;
    Movement movement(Coordinates(5, 5), &field);
    movement.setTarget(Coordinates(5, 10));
    movement.moveApart();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 4));
}

void ModelTest::SFTest()
{
    Settings settings;
    settings.setFieldHeight(30);
    settings.setFieldLength(30);
    settings.setNumOfPredators(60);
    settings.setNumOfPreys(60);

    Model model(&settings);

    while (!model.isEnd())
    {
        model.move();
    }
}

void ModelTest::senseTest()
{
    Field field;
    Units units;
    new Predator (3, 3, &field, &units, 20);
    new Predator(5, 5, &field, &units, 20);
    Sense sense(&field);
    std::list< std::pair< Unit*, double > >tst_list;
    Coordinates tst_coord1(4, 4);
    Coordinates tst_coord2(6, 5);

    tst_list = sense.getTargets(tst_coord1);

    sense.setRadius(1);
    tst_list = sense.getTargets(tst_coord2);

    tst_list = sense.getTargets(Coordinates(1, 1));
    QCOMPARE(tst_list.empty(), true);
}


QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
