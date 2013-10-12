#include "Graph.h"
#include <limits.h>
#include <stdio.h>

int const areConnected = 1;

Graph::Graph()
{
    vertexAmount = 0;
    adjMatrix = NULL;
}

Graph::Graph(int futureVertexAmount)
{
    vertexAmount = futureVertexAmount;
    adjMatrix = new int*[futureVertexAmount];
    for (int i = 0; i < futureVertexAmount; i++)
    {
        adjMatrix[i] = new int[futureVertexAmount];
    }
    for (int i = 0; i < futureVertexAmount; i++)
    {
        for(int j = 0; j < futureVertexAmount; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
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

int *Graph::getNeighbourNumbers(int elementNumber, int &count) const
{
    int* neighbourNumbers = new int[vertexAmount];
    count = 0;
    for (int i = 0; i < vertexAmount; i++)
    {
        neighbourNumbers[i] = INT_MIN;
    }
    for (int i = 0; i < vertexAmount; i++)
    {
        if (adjMatrix[elementNumber][i] == areConnected)
        {
            neighbourNumbers[count] = i;
            count++;
        }
    }
    return neighbourNumbers;
}

int *Graph::getDoubleNeighbourNumbers(int elementNumber, int& count) const
{
    int* doubleNeighbourNumbers = new int[vertexAmount];
    bool* accounted = new bool[vertexAmount];
    for (int i = 0; i < vertexAmount; i++)
    {
        doubleNeighbourNumbers[i] = INT_MIN;
        accounted[i] = false;
    }
    accounted[elementNumber] = true;
    count = 0;
    int countForFirst = 0;
    int* neighbours = getNeighbourNumbers(elementNumber, countForFirst);
    for (int i = 0; i < countForFirst; i++) // iterating neighbours
    {
        int countForDouble = 0;
        int* secondaryNeighbours = getNeighbourNumbers(neighbours[i], countForDouble); // neighbours of neighbours
        for (int j = 0; j < countForDouble; j++) // iterating neighbours of each neighbour
        {
                if (!accounted[secondaryNeighbours[j]]) // if this vertex is met for the first time
                {
                    doubleNeighbourNumbers[count] = secondaryNeighbours[j];
                    count++;
                    accounted[secondaryNeighbours[j]] = true;
                }
        }
        delete[] secondaryNeighbours;
    }
    delete[] accounted;
    delete[] neighbours;
    return doubleNeighbourNumbers;
}

int Graph::getVertexAmount() const
{
    return vertexAmount;
}

void Graph::connectVerteces(int first, int second)
{
    if ((first < vertexAmount) && (second < vertexAmount))
    {
        adjMatrix[first][second] = 1;
        adjMatrix[second][first] = 1;
    }
}

Graph::~Graph()
{
    for (int i =0 ; i < vertexAmount; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}
