#pragma once
#include "stdio.h"

class Graph
{
public:
    Graph(FILE* file);
    int** getMatrix() const;
    int getVertexAmount() const;
private:
    int** adjMatrix;
    int vertexAmount;
};
