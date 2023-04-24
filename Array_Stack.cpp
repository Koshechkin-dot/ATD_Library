#include "Arr_Stack.h"
#include <iostream>

void Array_Stack::Push(int data)
{
	if (_top < _Size - 1)
	{
		_top++;
		*(_array + _top) = data;
		return;
	}
	std::cout << "Stack Overflow" << std::endl;
}
int Array_Stack::Pop()
{
	if (_top >= 0)
	{
		int data = *(_array + _top);
		_top--;
		return data;
	}
	return INT_MAX;
}
int Array_Stack::Peek() const
{
	if (_top >= 0)
	{
		return *(_array + _top);
	}
	return INT_MAX;
}

void Array_Stack::Output()
{
	if (_top < 0)
	{
		std::cout << "This stack is empty" << std::endl;
		return;
	}
	for (int i = 0; i < _Size; i++)
	{
		std::cout << *(_array + i) << ' ';
	}
	std::cout << std::endl;
}
