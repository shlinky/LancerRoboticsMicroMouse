#pragma once
#include <stdlib.h> 

class Stack {
public:
	Stack(int size);
	bool push(int item);
	bool pop(void);
private:
	int* stackPtr;
	int length;
	int maxSize;
};
