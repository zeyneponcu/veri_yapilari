#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

using namespace std;

class stack{
	public:
		int size=50;
		int top;
		int upper=-1;
		int* array;
		void expand(int);
		stack();
		~stack();
		void push(int);
		void equal();
		bool isOver();
		void pop();
		int getUpper();
		void downUpper();
		int peek();
		bool isEmpty();
};
#endif