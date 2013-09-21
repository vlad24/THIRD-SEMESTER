#pragma once
#include "stdio.h"

class Graph
{
public:
    Graph();
    void createFromFile(FILE* file);
    int** getMatrix() const;
    int* getNeighbourNumbers(int elementNumber) const;
    int getVertexAmount() const;
private:
    int** adjMatrix;
    int vertexAmount;
};
