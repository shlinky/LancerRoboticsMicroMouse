#include "Stack.h"
#include "micromouseserver.h"

Stack::Stack(int size)
{
	maxSize = size;
	stackPtr = (int*) malloc((4 * size) * sizeof(int));
	length = 0;
}

//pushing x and y coordinates and turns to the stack
bool Stack::push(int tl, int tr, int x, int y)
{
	if (length == (maxSize - 1)) {
		return false;
	}
	else {
		length++;
		*(stackPtr + 4 * (length)) = tl;
		*(stackPtr + 4 * (length)+1) = tr;
		*(stackPtr + 4 * (length)+2) = x;
		*(stackPtr + 4 * (length)+3) = y;
		return true;
	}
}

//popping the last layer of the stack
bool Stack::pop(void)
{
	if (length == 0) {
		return false;
	}
	else {
		length--;
		return true;
	}
}

//private function for getting a certain part of one layer of a stack
int Stack::get(int index, int part)
{
	if (index != -1) {
		return *(stackPtr + 4 * (index) + part);
	}
	else {
		return *(stackPtr + 4 * (length) + part);
	}
}

//get if the mouse has turned left on this coordinate
int Stack::getTl(int index)
{
	return(get(index, 0));
}

//get if the mouse has turned right on this coordinate
int Stack::getTr(int index)
{
	return(get(index, 1));
}

//get x coordinate
int Stack::getX(int index)
{
	return(get(index, 2));
}

//get y coordinate
int Stack::getY(int index)
{
	return(get(index, 3));
}

//get the length of the stack
int Stack::getLength()
{
	return length;
}
