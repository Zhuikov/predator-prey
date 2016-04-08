//#include <QString>
//#include <QtTest>
//#include "predator.h"

//class PredatorTest : public QObject
//{
//    Q_OBJECT

//public:
//    PredatorTest();

//private Q_SLOTS:
//    void predatorMove();
//};

//PredatorTest::PredatorTest() {}

//void PredatorTest::predatorMove()
//{
//    Field field(10, 10);
//    Units units;

//    Prey tst_prey(3, 3, &field);
//    tst_prey.setPtrs(&units);
//    Predator tst_predator(4, 4, &field);
//    tst_predator.setPtrs(&units);

//    units.predators.push_back(&tst_predator);
//    units.preys.push_back(&tst_prey);

//    tst_predator.movePredator();

//    QCOMPARE(tst_predator.my_place.getX(), 3);
//    QCOMPARE(tst_predator.my_place.getY(), 4);


//}

//QTEST_APPLESS_MAIN(PredatorTest)

//#include "tst_predatortest.moc"

