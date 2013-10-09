#pragma once
#include <QObject>
#include <QtTest/QTest>
#include <stdio.h>
#include "LocalNet.h"
#include "BasicRandomiser.h"
#include "ZeroRandomiser.h"
#include "OneRandomiser.h"

class LocalNetTester : public QObject
{
    Q_OBJECT
public:
    explicit LocalNetTester(QObject *parent = 0) : QObject(parent) {}
    
private slots:

    void testCreationOnAmount()
    {
        FILE* netFile = fopen("net.txt", "r");
        Randomiser* basicRandomos = new BasicRandomiser();
        LocalNet* net = new LocalNet(netFile, basicRandomos);
        QVERIFY(net->computerAmount == 6);
        delete net;
        fclose(netFile);
    }

    void testCreationOnConnection()
    {
        FILE* netFile = fopen("net.txt", "r");
        Randomiser* basicRandomos = new BasicRandomiser();
        LocalNet* net = new LocalNet(netFile, basicRandomos);
        QVERIFY(net->netScheme.getMatrix()[0][1] == 1);
        QVERIFY(net->netScheme.getMatrix()[1][0] == 1);
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
        Randomiser* basicRandomos = new BasicRandomiser();
        LocalNet* net = new LocalNet(netFile, basicRandomos);
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

    void testUncontrolledWorkOnAccountingInfectedComputers()
    {
        FILE* netFile = fopen("net.txt", "r");
        Randomiser* basicRandomos = new BasicRandomiser();
        LocalNet* net = new LocalNet(netFile, basicRandomos);
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

    void testWorkWithSuperStrongVirus()
    {
        FILE* netFile = fopen("net.txt", "r");
        Randomiser* oneRandomos = new OneRandomiser();
        LocalNet* weakNet = new LocalNet(netFile, oneRandomos);
        weakNet->sendVirus();
        QVERIFY(weakNet->computersList[1]->isInfected);
        int* neighbours = weakNet->netScheme.getNeighbourNumbers(1);
        weakNet->work();
        for (int i = 0; i < weakNet->computerAmount; i++)
        {
            if (neighbours[i] > 0)
            {
                QVERIFY(weakNet->computersList[neighbours[i]]->isInfected);
            }
            else
            {
                break;
            }
        }
        delete weakNet;
        fclose(netFile);
    }

    void testWorkWithWeakVirus()
    {
        FILE* netFile = fopen("net.txt", "r");
        Randomiser* zeroRandomos = new ZeroRandomiser();
        LocalNet* net = new LocalNet(netFile, zeroRandomos);
        net->sendVirus();
        QVERIFY(net->computersList[0]->isInfected);
        int* neighbours = net->netScheme.getNeighbourNumbers(0);
        net->work();
        for (int i = 0; i < net->computerAmount; i++)
        {
            if (neighbours[i] > 0)
            {
                QVERIFY(!(net->computersList[neighbours[i]]->isInfected));
            }
            else
            {
                break;
            }
        }
        delete net;
        fclose(netFile);
    }
};

