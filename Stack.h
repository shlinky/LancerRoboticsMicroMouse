#pragma once
#include <stdlib.h> 

class Stack {
public:
	Stack(int size);
	bool push(int tl, int tr, int x, int y);
	bool pop();
	int getTl(int index = -1);
	int getTr(int index = -1);
	int getX(int index = -1);
	int getY(int index = -1);
	int getLength();
private:
	int get(int index, int part);
	int* stackPtr;
	int length;
	int maxSize;
};
