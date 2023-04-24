#include "Deque.h"
#include <iostream>


void Deque::First(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = temp;
	temp->prev = temp;
	_head = temp;
}

void Deque::FPush(int data)
{
	if (_head == NULL)
	{
		First(data);
		return;
	}
	Node* temp = new Node{ data, _head, _head->prev };
	_head->prev->next = temp;
	_head->prev = temp;
	_head = temp;
}

void Deque::BPush(int data)
{
	if (_head == NULL)
	{
		First(data);
		return;
	}
	Node* temp = new Node{ data, _head, _head->prev };
	_head->prev->next = temp;
	_head->prev = temp;
}

int Deque::FPop()
{
	if (_head == NULL) { return INT_MIN; }
	if (_head->next == _head)
	{
		int saved = _head->data;
		delete _head;
		_head = NULL;
		return saved;
	}
	Node* del = _head;
	int saved = del->data;
	_head = _head->next;
	_head->prev = del->prev;
	del->prev->next = _head;
	delete del;
	return saved;
}

int Deque::BPop()
{
	if (_head == NULL) { return INT_MIN; }
	if (_head->next == _head)
	{
		delete _head;
		_head = NULL;
		return INT_MIN;
	}
	Node* del = _head->prev;
	int saved = del->data;
	_head->prev = del->prev;
	del->prev->next = _head;
	delete del;
	return saved;
}

int Deque::Count() const
{
	int count = 0;
	Node* temp = _head;
	do
	{
		count++;
		temp = temp->next;
	} 
	while (temp != _head);
	return count;
}

void Deque::Clear()
{
	Node* temp = _head;
	do
	{
		Node* del = temp;
		temp = temp->next;
		delete del;
		del = NULL;
	}
	while (temp != _head);
	_head = NULL;
}

void Deque::Outlist()
{
	if (_head == NULL)
	{
		std::cout << "This deck is empty" << std::endl;
		return;
	}
	Node* temp = _head;
	do
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	} 
	while (temp != _head);
	std::cout << std::endl;
}
