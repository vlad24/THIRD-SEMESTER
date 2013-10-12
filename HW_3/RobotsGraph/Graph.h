#pragma once
#include "stdio.h"

//! A class implementing non-orientied graph with functions for getting differently remote verteces

class Graph
{
public:
    friend class GraphTester;
    Graph();
    //! Constructor which creates a Graph with predefined amount of verteces
    Graph(int futureVertexAmount);
    bool isEmpty() const;
    void fillFromFile(FILE* file);
    int** getMatrix() const;
    //! A function which returns numbers of elements incident to the given
    int* getNeighbourNumbers(int elementNumber, int& count) const;
    //! A function which returns numbers of elements double-incident to the given
    int* getDoubleNeighbourNumbers(int elementNumber, int &count) const;
    int getVertexAmount() const;
    void connectVerteces(int first, int second);
    ~Graph();
private:
    int** adjMatrix;
    int vertexAmount;
};
