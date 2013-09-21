#pragma once
#include <QObject>
#include "QtTest/QTest"
#include "QTime"
#include "Randomiser.h"

const int maximumNumberOfSteps = 5;
const int lessThanTen = 10;
const int lessThanOne = 1;
const double delta = 0.1;

class RandomiserTester : public QObject
{
    Q_OBJECT
public:
    explicit RandomiserTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:
    void testIntRandom()
    {
        bool success = false;
        Randomiser* randomos = new Randomiser();
        QTime* time = new QTime();
        for (int j = 0; j < maximumNumberOfSteps; j++)
        {
            int first = randomos->pseudoRandomInt(lessThanTen);
            time->start();
            while(time->elapsed() < 15)
            {
            }
            if (randomos->pseudoRandomInt(lessThanTen) != first)
            {
                success = true;
                break;
            }
        }
        delete randomos;
        delete time;
        QVERIFY(success);
    }

    void testDoubleRandom()
    {
        bool success = false;
        Randomiser* randomos = new Randomiser();
        QTime* time = new QTime();
        for (int j = 0; j < maximumNumberOfSteps; j++)
        {
            int first = randomos->pseudoRandomDouble(lessThanOne);
            time->start();
            while(time->elapsed() < 15)
            {
            }
            if (randomos->pseudoRandomDouble(lessThanOne) - first > delta)
            {
                success = true;
                break;
            }
        }
        delete randomos;
        delete time;
        QVERIFY(success);
    }
    
};
