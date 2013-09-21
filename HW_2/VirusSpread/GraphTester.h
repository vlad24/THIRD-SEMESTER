#pragma once
#include <QObject>
#include <QtTest/QTest>
#include "Graph.h"
#include "limits.h"

class GraphTester : public QObject
{
    Q_OBJECT
public:
    explicit GraphTester(QObject *parent = 0) : QObject(parent){}
    
private slots:

    void testCreation()
    {
        Graph* graph = new Graph();
        QVERIFY(graph->isEmpty());
        delete graph;
    }

    void testFillingFromFile()
    {
        Graph* graph = new Graph();
        FILE* file = fopen("net.txt", "r");
        graph->fillFromFile(file);
        QVERIFY(graph->vertexAmount == 6);
        QVERIFY(graph->adjMatrix[1][4] == 1);
        QVERIFY(graph->adjMatrix[4][4] != 1);
        delete graph;
        fclose(file);
    }

    void testFindingNeighbours()
    {
        Graph* graph = new Graph();
        FILE* file = fopen("net.txt", "r");
        graph->fillFromFile(file);
        int neighboursAmount = 0;
        int* neighboursOfTheFirstComputer = graph->getNeighbourNumbers(1);
        for (int i = 0; i < graph->vertexAmount; i++)
        {
            if (neighboursOfTheFirstComputer[i] != INT_MIN)
            {
                neighboursAmount++;
            }
        }
        QVERIFY(neighboursAmount == 3);
        QVERIFY(neighboursOfTheFirstComputer[0] == 0);
        QVERIFY(neighboursOfTheFirstComputer[1] == 3);
        QVERIFY(neighboursOfTheFirstComputer[2] == 4);
        delete graph;
        fclose(file);
    }

    
};
