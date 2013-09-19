#include "Graph.h"
#include <stdio.h>

int const areConnected = 1;

Graph::Graph(FILE *file)
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
            for(int u = 0 ; u < 3 ; u++)
            {
                fscanf(file, "%d ", &i);
                fscanf(file, "%d ", &j);
                adjMatrix[i][j] = areConnected;
                adjMatrix[j][i] = areConnected;
            }
        }
}

int **Graph::getMatrix() const
{
    return adjMatrix;
}

int Graph::getVertexAmount() const
{
    return vertexAmount;
}
