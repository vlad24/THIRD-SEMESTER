#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "LocalNet.h"
#include <stdio.h>

class LocalNetTester : public QObject
{
    Q_OBJECT
public:
    explicit LocalNetTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:

    void testCreationOnAmount()
    {
        FILE* netFile = fopen("net.txt", "r");
        LocalNet* net = new LocalNet(netFile);
        QVERIFY(net->computerAmount == 6);
        delete net;
        fclose(netFile);
    }

    void testCreationOnConnection()
    {
        FILE* netFile = fopen("net.txt", "r");
        LocalNet* net = new LocalNet(netFile);
        QVERIFY(net->netScheme.getMatrix()[5][3] == 1);
        QVERIFY(net->netScheme.getMatrix()[3][5] == 1);
        QVERIFY(net->netScheme.getMatrix()[0][3] != 1);
        QVERIFY(net->netScheme.getMatrix()[3][0] != 1);
        delete net;
        fclose(netFile);
    }

    void testCreationOnSendingVirus()
    {
        int amountOfInfected = 0;
        FILE* netFile = fopen("net.txt", "r");
        LocalNet* net = new LocalNet(netFile);
        net->sendVirus();
        for(int i = 0; i < net->computerAmount; i++)
        {
            if (net->computersList[i]->isInfected)
            {
                amountOfInfected++;
            }
        }
        delete net;
        fclose(netFile);
        QVERIFY(amountOfInfected == 1);
    }

    void testWork()
    {
        FILE* netFile = fopen("net.txt", "r");
        LocalNet* net = new LocalNet(netFile);
        net->sendVirus();
        int firstVictimNumber = -1;
        for(int i = 0; i < net->computerAmount; i++)
        {
            if (net->computersList[i]->isInfected)
            {
                firstVictimNumber = i;
            }
        }
        net->work();
        bool success = true;
        for(int i = 0; i < net->computerAmount; i++)
        {
            if ((net->computersList[i]->isInfected) && (i != firstVictimNumber))
            {
                success = success && (net->toBeIgnoredAtThisStep[i] == true);
            }
        }
        delete net;
        fclose(netFile);
        QVERIFY(success);
    }


    
};

