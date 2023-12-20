#include "stack.hpp"

Stack::Stack(int size) : max(size){
	top = -1;
	data = new int[max];
}
Stack::~Stack(){
	delete []data;
}
int Stack::get(){
	return data[top];
}
void Stack::push(int v){
	if(top < max-1){
		data[++top] = v;
	}
	else{
		std::cout << std::endl << "   Stack Overflow! cannot push" << std::endl << std::endl;
		return;
	}
}
void Stack::pop(){
	if(top > -1){
		top--;
	}
	else{
		std::cout << std::endl << "   Stack Underflow! cannot pop" << std::endl << std::endl;
		return;
	}
}
