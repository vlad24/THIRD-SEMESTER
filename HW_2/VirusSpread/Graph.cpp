#include "Graph.h"
#include <limits.h>
#include <stdio.h>

int const areConnected = 1;

Graph::Graph()
{
    vertexAmount = 0;
    adjMatrix = NULL;
}

bool Graph::isEmpty() const
{
    return ((adjMatrix == NULL) && (vertexAmount == 0));
}

void Graph::fillFromFile(FILE *file)
{
    // Finding out the size
    fscanf(file,"%d ",&vertexAmount);
    adjMatrix = new int*[vertexAmount];
    for(int i = 0 ; i < vertexAmount ; i++)
        adjMatrix[i] = new int[vertexAmount];
    // Initialization
    for(int i = 0 ; i < vertexAmount ; i++)
        for(int j = 0 ; j < vertexAmount; j++)
            adjMatrix[i][j] = 0;
    // Filling
    int i = 0;
    int j = 0;
    while(!feof(file))
    {
            fscanf(file, "%d ", &i);
            fscanf(file, "%d ", &j);
            adjMatrix[i][j] = areConnected;
            adjMatrix[j][i] = areConnected;
    }
}

int **Graph::getMatrix() const
{
    return adjMatrix;
}

int *Graph::getNeighbourNumbers(int elementNumber) const
{
    int* neighbourNumbers = new int[vertexAmount];
    for (int i = 0; i < vertexAmount; i++)
    {
        neighbourNumbers[i] = INT_MIN;
    }
    int currentPositionInArray = 0;
    for (int i = 0; i < vertexAmount; i++)
    {
        if (adjMatrix[elementNumber][i] == areConnected)
        {
            neighbourNumbers[currentPositionInArray] = i;
            currentPositionInArray++;
        }
    }
    return neighbourNumbers;
}

int Graph::getVertexAmount() const
{
    return vertexAmount;
}

Graph::~Graph()
{
    for (int i =0 ; i < vertexAmount; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}
