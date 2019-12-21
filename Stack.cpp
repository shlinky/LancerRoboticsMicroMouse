#include "Stack.h"

Stack::Stack(int size)
{
	maxSize = size;
	stackPtr = (int*) malloc(size * sizeof(int));
	length = 0;
}

bool Stack::push(int item)
{
	if (length == maxSize) {
		return false;
	}
	else {
		length++;
		*(stackPtr + length - 1) = item;
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


