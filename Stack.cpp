#include "Stack.h"
#include "micromouseserver.h"

Stack::Stack(int size)
{
	maxSize = size;
	stackPtr = (int*) malloc((4 * size) * sizeof(int));
	length = 0;
}

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

int Stack::get(int index, int part)
{
	if (index != -1) {
		return *(stackPtr + 4 * (index) + part);
	}
	else {
		return *(stackPtr + 4 * (length) + part);
	}
}

int Stack::getTl(int index)
{
	return(get(index, 0));
}

int Stack::getTr(int index)
{
	return(get(index, 1));
}

int Stack::getX(int index)
{
	return(get(index, 2));
}

int Stack::getY(int index)
{
	return(get(index, 3));
}

int Stack::getLength()
{
	return length;
}
