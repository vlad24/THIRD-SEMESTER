#include "RobotDestroyer.h"
#include <stdio.h>
#include <limits.h>

RobotDestroyer::RobotDestroyer()
{
    field = NULL;
    pathField = NULL;
    robotFromThisVertex = NULL;
    robotsAmount = 0;
}

void RobotDestroyer::createField(FILE* fieldFile)
{
    field = new Graph();
    field->fillFromFile(fieldFile);
}

void RobotDestroyer::fillStartPositions(FILE* positionsFile)
{
    int vertecesAmount = field->getVertexAmount();
    robotFromThisVertex = new int[vertecesAmount];
    for (int i = 0; i < vertecesAmount; i++)
    {
        robotFromThisVertex[i] = INT_MIN;
    }
    fscanf(positionsFile, "%d", &robotsAmount);
    for (int i = 0; i < robotsAmount; i++)
    {
        int robot = -1;
        int vertex = -1;
        fscanf(positionsFile, "%d ", &robot);
        fscanf(positionsFile, "%d", &vertex);
        robotFromThisVertex[vertex] = robot;
    }
}

void RobotDestroyer::createPathField()
{
    pathField = new Graph(field->getVertexAmount());
    for (int currentVertex = 0; currentVertex < field->getVertexAmount(); currentVertex++)
    {
        int count = 0;
        int* doubleNeighbours = field->getDoubleNeighbourNumbers(currentVertex, count);
        for (int i = 0; i < count; i++)
        {
            pathField->connectVerteces(currentVertex, doubleNeighbours[i]);
        }
        delete[] doubleNeighbours;
    }
}

bool RobotDestroyer::robotsCanDestroy()
{
    createPathField();
    int vertexCount = pathField->getVertexAmount();
    bool* passed = new bool[vertexCount];
    for (int i = 0; i < vertexCount; i++)
    {
        passed[i] = false;
    }
    for (int currentVertex = 0; currentVertex < vertexCount; currentVertex++)
    {
        if (!passed[currentVertex])
        {
            bool* passedAtThisStep = new bool[vertexCount];
            markComponent(currentVertex, passedAtThisStep);
            int robotsInTheComponent = countRobotsInComponent(passedAtThisStep);
            if (robotsInTheComponent == 1)
            {
                delete[] passed;
                delete[] passedAtThisStep;
                return false;
            }
            else
            {
                for (int y = 0 ; y < vertexCount; y++)
                    if (passedAtThisStep[y])
                        passed[y] = true;
                delete[] passedAtThisStep;
            }
        }
    }
    delete[] passed;
    return true;
}

void RobotDestroyer::markComponent(int currentVertex, bool* &passedNow)
{
    passedNow[currentVertex] = true;
    int neighbourCount = 0;
    int* neighbours = pathField->getNeighbourNumbers(currentVertex, neighbourCount);
    for (int neighbourIndex = 0; neighbourIndex < neighbourCount; neighbourIndex++)
    {
        if (!passedNow[neighbours[neighbourIndex]])
            markComponent(neighbours[neighbourIndex], passedNow);
    }
    delete[] neighbours;
    return;
}

int RobotDestroyer::countRobotsInComponent(bool* isInComponent)
{
    int robotsCounter = 0;
    for (int i = 0; i < pathField->getVertexAmount(); i++)
    {
        if (isInComponent[i])
        {
            if (robotFromThisVertex[i] != INT_MIN)
                robotsCounter++;
        }
    }
    return robotsCounter;
}

RobotDestroyer::~RobotDestroyer()
{
    if (robotFromThisVertex != NULL)
        delete[] robotFromThisVertex;
    if (field != NULL)
        delete field;
    if (pathField != NULL)
        delete pathField;
}
