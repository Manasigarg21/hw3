#include "stack.h"
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	Stack<int> temp;
	temp.push(5);
	temp.push(7);
	temp.push(3);
	temp.push(4);
	temp.pop();
	temp.pop();
	temp.push(8);
	temp.push(12);
	temp.push(-3);
	temp.push(-5);
	
	cout<<temp.empty()<<endl; //false
	cout<<temp.size()<<endl; //6
	cout<<temp.top()<<endl; //-5

}