#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <stdio.h>
#include "RobotDestroyer.h"


class RobotDestroyerTester : public QObject
{
    Q_OBJECT
public:
    explicit RobotDestroyerTester(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testCreatingField()
    {
        RobotDestroyer* destroyer = new RobotDestroyer();
        FILE* fieldFile = fopen("_fieldFile.txt", "r");
        destroyer->createField(fieldFile);
        QVERIFY(destroyer->field->getMatrix()[0][3] == 1);
        QVERIFY(destroyer->field->getMatrix()[1][4] == 0);
        fclose(fieldFile);
        printf("op1");
        delete destroyer;
    }

    void testPuttingRobotsInRightPositions()
    {
        RobotDestroyer* destroyer = new RobotDestroyer();
        FILE* fieldFile = fopen("_fieldFile.txt", "r");
        destroyer->createField(fieldFile);
        FILE* positionsFile = fopen("_robotsConfiguration.txt", "r");
        destroyer->fillStartPositions(positionsFile);
        QVERIFY(destroyer->robotsAmount == 3);
        QVERIFY(destroyer->startPositions[0] == 0);
        QVERIFY(destroyer->startPositions[2] == 4);
        fclose(positionsFile);
        delete destroyer;
    }

    void testMarkingVerteces_1stVertex()
    {
        RobotDestroyer* destroyer = new RobotDestroyer();
        FILE* fieldFile = fopen("_fieldFile.txt", "r");
        destroyer->createField(fieldFile);
        FILE* positionsFile = fopen("_robotsConfiguration.txt", "r");
        destroyer->fillStartPositions(positionsFile);
        destroyer->markVertecesByRobots();
        printf("Printing:");
        destroyer->robotsAtTheVertex[1]->print();
        destroyer->robotsAtTheVertex[2]->print();
        destroyer->robotsAtTheVertex[3]->print();
//        QVERIFY(destroyer->robotsAtTheVertex[2]->contains(0));
//        QVERIFY(destroyer->robotsAtTheVertex[2]->contains(1));
//        QVERIFY(destroyer->robotsAtTheVertex[2]->contains(2));
        fclose(positionsFile);
        delete destroyer;
    }

    void testMarkingVerteces_2ndVertex()
    {

    }

    void testMarkingVerteces_3rdVertex()
    {

    }
    
};

