#pragma once
#include "stdio.h"

class Graph
{
public:
    friend class GraphTester;
    Graph();
    Graph(int futureVertexAmount);
    bool isEmpty() const;
    void fillFromFile(FILE* file);
    int** getMatrix() const;
    //! A function which returns numbers of elements incident to the given
    int* getNeighbourNumbers(int elementNumber, int& count) const;
    int* getDoubleNeighbourNumbers(int elementNumber, int &count) const;
    int getVertexAmount() const;
    void connectVerteces(int first, int second);
    ~Graph();
private:
    int** adjMatrix;
    int vertexAmount;
};
