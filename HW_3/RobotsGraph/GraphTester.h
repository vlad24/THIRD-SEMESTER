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
        FILE* file = fopen("_fieldFile.txt", "r");
        graph->fillFromFile(file);
        QVERIFY(graph->vertexAmount == 6);
        QVERIFY(graph->adjMatrix[1][3] == 1);
        QVERIFY(graph->adjMatrix[4][4] != 1);
        delete graph;
        fclose(file);
    }

    void testFindingNeighbours()
    {
        Graph* graph = new Graph();
        FILE* file = fopen("_fieldFile.txt", "r");
        graph->fillFromFile(file);
        int counter = 0;
        int* neighboursOfTheFirst = graph->getNeighbourNumbers(1, counter);
        QVERIFY(counter == 2);
        QVERIFY(neighboursOfTheFirst[0] == 3);
        QVERIFY(neighboursOfTheFirst[1] == 5);
        delete graph;
        fclose(file);
    }

    void testFindingDoubleNeighbours()
    {
        Graph* graph = new Graph();
        FILE* file = fopen("_fieldFile.txt", "r");
        graph->fillFromFile(file);
        int counter = 0;
        int* doubleNeighboursOfTheFirst = graph->getDoubleNeighbourNumbers(1, counter);
        int controlSum = 0;
        for (int i = 0; i < counter; i++)
        {
            controlSum += doubleNeighboursOfTheFirst[i];
            printf("%d ", doubleNeighboursOfTheFirst[i]);
        }
        QVERIFY(counter == 3);
        QVERIFY(controlSum == 6);
        delete graph;
        fclose(file);
    }

    
};
