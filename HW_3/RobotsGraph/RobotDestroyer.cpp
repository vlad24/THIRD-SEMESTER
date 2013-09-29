#include "RobotDestroyer.h"
#include <stdio.h>
#include <limits.h>

RobotDestroyer::RobotDestroyer()
{
    field = NULL;
    startPositions = NULL;
    robotsAtTheVertex = NULL;
    robotsAmount = 0;
}

void RobotDestroyer::createField(FILE* fieldFile)
{
    field = new Graph();
    field->fillFromFile(fieldFile);
}

void RobotDestroyer::fillStartPositions(FILE* positionsFile)
{
    fscanf(positionsFile, "%d", &robotsAmount);
    startPositions = new int[robotsAmount];
    for (int i = 0; i < robotsAmount; i++)
    {
        startPositions[i] = INT_MIN;
    }
    for (int i = 0; i < robotsAmount; i++)
    {
        int robot = -1;
        int vertex = -1;
        fscanf(positionsFile, "%d ", &robot);
        fscanf(positionsFile, "%d", &vertex);
        startPositions[robot] = vertex;
    }
}



void RobotDestroyer::markVertecesByRobots()
{
      robotsAtTheVertex = new PointerList*[field->getVertexAmount()];
      for (int i = 0; i < field->getVertexAmount(); i++)
      {
          robotsAtTheVertex[i] = new PointerList();
      }
    for (int robotNumber = 0; robotNumber < robotsAmount; robotNumber++)
    {
        // Analysing all possible ways for the current robot
        int startRobotPosition = startPositions[robotNumber];
        markVertexByOneRobot(robotNumber, startRobotPosition, 0);
        printf("%d robot done\n", robotNumber);
    }
}

RobotDestroyer::~RobotDestroyer()
{
    if (field != NULL)
    {
        int vertecesCount = field->getVertexAmount();
        delete field;
        if (robotsAtTheVertex != NULL)
        {
            for (int i = 0; i < vertecesCount; i++)
            {
                delete robotsAtTheVertex[i];
            }
            delete[] robotsAtTheVertex;
        }
    }
}

//!!!! NEEDS REPAIRING USING DOUBLE NEIGHBOURS
void RobotDestroyer::markVertexByOneRobot(int robot, int robotPosition, int step)
{
    if (robotsAtTheVertex[robotPosition]->contains(robot))
    {
        // If a robot has been here - escaping
        return;
    }
    else
    {
        // If it hasn't - appending it to the list of the vertex if step is even
        if (step % 2 == 0)
            robotsAtTheVertex[robotPosition]->add(robot);
        // Scanning verteces, incident to its current position
        int count = 0;
        int* neighbourVerteces = field->getNeighbourNumbers(robotPosition, count);
        for (int j = 0; j < count; j++)
        {
            // Transporting robot to a new vertex and doing the same there
                markVertexByOneRobot(robot, neighbourVerteces[j], step + 1);
        }
        delete neighbourVerteces;
    }
}
