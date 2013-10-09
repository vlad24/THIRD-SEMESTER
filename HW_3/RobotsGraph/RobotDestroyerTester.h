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
        QVERIFY(destroyer->robotFromThisVertex[0] == 0);
        QVERIFY(destroyer->robotFromThisVertex[4] == 2);
        fclose(positionsFile);
        delete destroyer;
    }

    void testCreatingPathField()
    {
        RobotDestroyer* destroyer = new RobotDestroyer();
        FILE* fieldFile = fopen("_fieldFile.txt", "r");
        destroyer->createField(fieldFile);
        FILE* positionsFile = fopen("_robotsConfiguration.txt", "r");
        destroyer->fillStartPositions(positionsFile);
        destroyer->createPathField();
        QVERIFY(destroyer->pathField->getMatrix()[0][1] == 1);
        QVERIFY(destroyer->pathField->getMatrix()[1][0] == 1);
        QVERIFY(destroyer->pathField->getMatrix()[5][3] == 1);
        QVERIFY(destroyer->pathField->getMatrix()[3][5] == 1);
        QVERIFY(destroyer->pathField->getMatrix()[5][4] == 0);
        QVERIFY(destroyer->pathField->getMatrix()[4][5] == 0);
        QVERIFY(destroyer->pathField->getMatrix()[0][2] == 0);
        QVERIFY(destroyer->pathField->getMatrix()[2][0] == 0);
        fclose(positionsFile);
        delete destroyer;
    }

    void testMarkingComponents()
    {
        RobotDestroyer* destroyer = new RobotDestroyer();
        FILE* fieldFile = fopen("_fieldFile.txt", "r");
        destroyer->createField(fieldFile);
        FILE* positionsFile = fopen("_robotsConfiguration.txt", "r");
        destroyer->fillStartPositions(positionsFile);
        destroyer->createPathField();
        bool* passedNow = new bool[destroyer->robotsAmount];
        destroyer->markComponent(0, passedNow);

        fclose(positionsFile);
        delete destroyer;
    }
};

