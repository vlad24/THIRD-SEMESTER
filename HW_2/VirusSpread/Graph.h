#pragma once
#include "stdio.h"

class Graph
{
public:
    friend class GraphTester;
    Graph();
    bool isEmpty() const;
    void fillFromFile(FILE* file);
    int** getMatrix() const;
    //! A function which returns numbers of elements incident to the given
    int* getNeighbourNumbers(int elementNumber) const;
    int getVertexAmount() const;
    ~Graph();
private:
    int** adjMatrix;
    int vertexAmount;
};
