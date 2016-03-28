#include <QString>
#include <QtTest>
#include <cmath>
#include "field.h"
#include "point.h"

class ModelTest : public QObject
{
    Q_OBJECT

public:
    ModelTest();

private Q_SLOTS:
    int doubleCompare(double a, double b);

    void pointTest();
    void fieldTest();
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

    QCOMPARE(field.isEmpty(0, 0), 1);
    QCOMPARE(field.isEmpty(4, 2), 1);
//    QCOMPARE(field.isEmpty(2, 5), 1);
//    QCOMPARE(field.getChar(2, 5), '.');

//    field.setPosition(1, 4, 'X');
//    QCOMPARE(field.isEmpty(1, 4), 0);
//    QCOMPARE(field.whatIsEmpty(4, 0), 'd');
//    QCOMPARE(field.whatIsEmpty(1, 4), 'u');
//    QCOMPARE(field.whatIsEmpty(1, 5), 'r');
}

QTEST_APPLESS_MAIN(ModelTest)

#include "tst_modeltest.moc"
