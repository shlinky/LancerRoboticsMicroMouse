
#include "micromouseserver.h"
#include "Stack.h"
#include <chrono>
#include <thread>

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
/*
 * The following are the eight functions that you can call. Feel free to create your own fuctions as well.
 * Remember that any solution that calls moveForward more than once per call of studentAI() will have points deducted.
 *
 *The following functions return if there is a wall in their respective directions
 *bool isWallLeft();
 *bool isWallRight();
 *bool isWallForward();
 *
 *The following functions move the mouse. Move forward returns if the mouse was able to move forward and can be used for error checking
 *bool moveForward();
 *void turnLeft();
 *void turnRight();
 *
 * The following functions are called when you need to output something to the UI or when you have finished the maze
 * void foundFinish();
 * void printUI(const char *mesg);
*/
    if (turnStack == nullptr) {
        turnStack = new Stack(1000);
    }

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
        char buff[100];
        printUI(itoa(l, buff, 10));
        printUI(itoa(r, buff, 10));
    }

    char buff[100];
    printUI(itoa(x, buff, 10));
    printUI(itoa(y, buff, 10));
    printUI(itoa(state, buff, 10));
    printUI("_______");
    //sleep_until(system_clock::now() + seconds(2));
}
