
#include "micromouseserver.h"
#include "Stack.h"
#include <chrono>
#include <thread>

//used to turn left while also updating the coordinates
void microMouseServer::coordLeft()
{
    if (dir == 0) {
        dir = 3;
    }
    else {
        dir--;
    }
    turnLeft();
}

//used to turn right while also updating the coordinates
void microMouseServer::coordRight()
{
    if (dir == 3) {
        dir = 0;
    }
    else {
        dir++;
    }
    turnRight();
}

//used to move forward while also updating the coordinates
void microMouseServer::coordForward()
{
    moveForward();
    if (dir == 0) {
        y++;
    }
    else if (dir == 1) {
        x++;
    }
    else if (dir == 2) {
        y--;
    }
    else {
        x--;
    }
}

//used to check if mouse has already been to this coordinate
//used to avoid loops and check for completion
bool microMouseServer::checkStack(int x1, int y1)
{
    int l = turnStack->getLength();
    
    while (l >= 0) {
        if ((turnStack->getX(l) == x1) && (turnStack->getY(l) == y1)) {
            return true;
        }
        l--;
    }
    return false;
}

void microMouseServer::studentAI()
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    //initializing stack
    if (turnStack == nullptr) {
        turnStack = new Stack(1000);
    }

    //when mouse is going forward
    if (state == 0) {
        if ((!isWallRight()) && (r == 0)) {
            turnStack->push(l, l + 1, x, y);
            coordRight();
            coordForward();
            if (checkStack(x, y)) {
                foundFinish();
            }
        }
        else if ((!isWallLeft()) && (l == 0)) {
            turnStack->push(r + 1, r, x, y);
            coordLeft();
            coordForward();
            if (checkStack(x, y)) {
                foundFinish();
            }
        }
        else if (!isWallForward()) {
            coordForward();
            if (checkStack(x, y)) {
                state = 1;
                coordLeft();
                coordLeft();
                coordForward();
            }
        }
        else {
            state = 1;
            coordLeft();
            coordLeft();
            coordForward();
        }
        r = 0;
        l = 0;
    }
    //if mouse is retracing its steps
    else {
        if ((x != turnStack->getX()) || (y != turnStack->getY())) {
            coordForward();
        }
        else {
            if (turnStack->getTl() > turnStack->getTr()) {
                coordLeft();
            }
            else {
                coordRight();
            }
            
            l = turnStack->getTl();
            r = turnStack->getTr();
            turnStack->pop();
            state = 0;
        }
    }
    //sleep_until(system_clock::now() + seconds(2));
}
