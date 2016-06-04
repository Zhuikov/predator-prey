#include <QtTest>
#include "movement.h"

class MovementTest : public QObject
{
    Q_OBJECT

public:
    MovementTest();

private Q_SLOTS:

    void moveTest();
    void moveApartTest();

};

void moveTest()
{
    Movement movement(Coordinates(0, 0));
    movement.setTarget(Coordinates(5, 5));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(1, 1));
    movement.setSpeed(3);
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(3, 3));
    movement.setSpeed(7.2);
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 5));
    movement.setTarget(Coordinates(5, 15));
    movement.move();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 12));

}

void moveApartTest()
{
    Movement movement(Coordinates(5, 5));
    movement.setTarget(Coordinates(5, 10));
    movement.moveApart();
    QCOMPARE(movement.getCurrent(), Coordinates(5, 4));
}
