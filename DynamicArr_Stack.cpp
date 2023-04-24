#include "DynamicArr_Stack.h"
#include <iostream>


void Dynamic_Stack::Push(int data)
{
	if (_size == 0)
	{
		_size++;
		_arr = new int[_size];
		*(_arr) = data;
		return;
	}
	int* temp = new int[++_size];
	*(temp) = data;
	for (int i = 1; i < _size; i++)
	{
		*(temp + i) = *(_arr + i - 1);
	}
	delete[] _arr;
	_arr = temp;
}

int Dynamic_Stack::Pop()
{
	if (_size == 0)
	{
		return INT_MIN;
	}
	int saved = *(_arr);
	int* temp = new int[--_size];
	for (int i = 0; i < _size; i++)
	{
		*(temp + i) = *(_arr + i + 1);
	}
	delete[] _arr;
	_arr = temp;
	return saved;
}

int Dynamic_Stack::Peek()
{
	return (_size > 0) ? *(_arr) : INT_MIN;
}

void Dynamic_Stack::Clear()
{
	delete[] _arr;
	_arr = nullptr;
	_size = 0;
}

void Dynamic_Stack::Output()
{
	if (_size == 0)
	{
		std::cout << "This stack is empty" << std::endl;
		return;
	}
	for (int i = 0; i < _size; i++) std::cout << *(_arr + i) << ' ';
	std::cout << std::endl;
}
