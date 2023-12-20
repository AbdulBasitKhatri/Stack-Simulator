#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
	private:
		int top;
		int max;
		int *data;
	public:
		Stack(int size);
		~Stack();
		int get();
		void push(int v);
		void pop();
};

#endif
