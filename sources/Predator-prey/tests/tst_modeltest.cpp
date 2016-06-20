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
    void settingsTest();

    void predatorNoMoveTest();
    void predatorCreateTest();
    void predatorMoveKillTest();
    void predatorPriorityTest();
    void predatorHungryTest();
    void twoPredatorsTest();

    void modelInitializeTest();
    void debugTest();

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

//TODO: думаю, этот тест нереально понять никому, кроме автора
void ModelTest::moveEnd(Units *units)
{
    for (std::vector< Predator* >::iterator it = units->predators.begin(); it != units->predators.end(); ++it) {
        if ( (*it)->exist == false ) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    units->predators.erase( std::remove(units->predators.begin(), units->predators.end(), nullptr),
                            units->predators.end() );

    for (std::vector< Prey* >::iterator it = units->preys.begin(); it != units->preys.end(); ++it) {
        if ( (*it)->exist == false ) {
            delete (*it);
            (*it) = nullptr;
        }
    }
    units->preys.erase( std::remove(units->preys.begin(), units->preys.end(), nullptr),
                            units->preys.end() );
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
    new Prey(1, 0, &field, &units);
    QCOMPARE(field.isEmpty(0, 0), true);

    new Predator(2, 5, &field, &units, 20);
    new Prey(3, 4, &field, &units);
    QVERIFY_EXCEPTION_THROWN(field.setPosition(-1, 0, nullptr), BadFieldBoundary);
    QVERIFY_EXCEPTION_THROWN(field.setPosition(10, 10, nullptr), BadFieldBoundary);

}

void ModelTest::settingsTest()
{
    Settings settings;

    QVERIFY_EXCEPTION_THROWN(settings.setFieldHeight(-1), BadFieldHeight);
    QVERIFY_EXCEPTION_THROWN(settings.setFieldLength(-1), BadFieldLength);
    QVERIFY_EXCEPTION_THROWN(settings.setNumOfPredators(-1), BadNum);
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

void ModelTest::predatorMoveKillTest()
{
    Field field(10, 10);
    Units units;

    new Prey(3, 3, &field, &units);
    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    units.predators[0]->move();

//    QCOMPARE(tst_predator->getPlace().getV(), 4);
//    QCOMPARE(tst_predator->getPlace().getH(), 3);

//    units.predators[0]->movePredator();

    QCOMPARE(tst_predator->getPlace().getV(), 3);
    QCOMPARE(tst_predator->getPlace().getH(), 3);
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

    tst_predator->move();
    moveEnd(&units);
    tst_predator->move();

    QCOMPARE(tst_predator->getPlace().getV(), 2);
    QCOMPARE(tst_predator->getPlace().getH(), 3);
    int pred_size = units.predators.size();
    QCOMPARE(pred_size, 2);

}

void ModelTest::predatorHungryTest()
{
    Field field;
    Units units;

    Predator* tst_predator = new Predator(4, 4, &field, &units, 20);

    for (int i = 0; i < 20; i++) {
        tst_predator->move();
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

    tst_predator1->move();
    tst_predator2->move();
    moveEnd(&units);
    tst_predator1->move();
    tst_predator2->move();
    moveEnd(&units);
    QCOMPARE(units.preys.empty(), true);

    field.setPosition(tst_predator1->getPlace().getV(), tst_predator1->getPlace().getH(), nullptr);
    field.setPosition(tst_predator2->getPlace().getV(), tst_predator2->getPlace().getH(), nullptr);
    tst_predator1->exist = false;
    tst_predator2->exist = false;
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

    tst_predator->move();

    QCOMPARE(tst_predator->getPlace().getV(), 5);
    QCOMPARE(tst_predator->getPlace().getH(), 4);
}

void ModelTest::modelInitializeTest()
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
        for (unsigned int i = 0; i < units.predators.size(); i++) units.predators[i]->move();
        moveEnd(&units);
        num_of_predators_moves ++;
    }
    moveEnd(&units);
    int final_vec_size = units.predators.size();
    QCOMPARE(final_vec_size, 3);

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

    while (!model.isEnd()) {
        model.move();
        model.remove();
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
    unsigned int size = 2;
    QCOMPARE(tst_list.size(), size);

    sense.setRadius(1);
    tst_list = sense.getTargets(tst_coord2);
    size = 1;
    QCOMPARE(tst_list.size(), size);

    tst_list = sense.getTargets(Coordinates(1, 1));
    QCOMPARE(tst_list.empty(), true);
}


QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
