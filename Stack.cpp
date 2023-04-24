#include "Stack.h"
#include <iostream>


void Stack::Push(int data)
{
	_top = new Node{ data, _top };
}
int Stack::Pop()
{
	if (_top)
	{
		Node* temp = _top;
		int data = temp->data;
		_top = _top->next;
		delete temp;
		return data;
	}
	return INT_MAX;
}
void Stack::Clear()
{
	while (_top)
	{
		Node* temp = _top;
		_top = _top->next;
		delete temp;
	}
}
int Stack::Count() const
{
	int count = 0;
	Node* temp = _top;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void Stack::Output()
{
	if (_top == NULL)
	{
		std::cout << "Stack Overflow" << std::endl;
		return;
	}
	Node* temp = _top;
	while (temp != NULL)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}
