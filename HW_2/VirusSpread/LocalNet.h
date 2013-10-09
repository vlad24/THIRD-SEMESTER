#pragma once
#include "Graph.h"
#include "Randomiser.h"
#include "Computer.h"

//! A class which represents a Local Net as a set of computers.

class LocalNet
{
    friend class LocalNetTester;
public:
    /*! @param file Place where we will take the scheme of the net
        @param random Object which defines how random numbers for the net work will be generated
      */
    LocalNet(FILE* file, Randomiser* randomForNet);
    //! A function that brings a virus to random computer of the net
    void sendVirus();
    //! A function that immitates computers infecting each other during working
    void work();
    //! A function which represents the amount and numbers of infected computers
    void showNetStatus() const;
    void showNetInfo() const;
    //! A pause between working sessions of the net
    void makePause(int duration) const;
    ~LocalNet();
private:
    Graph netScheme;
    //! An array that enables to work comfortably with computers of the net
    Computer** computersList;
    int computerAmount;
    //! Array to observe computers that have been infected during one session and can't infect others
    bool* toBeIgnoredAtThisStep;
    Randomiser* randomiser;
};
