#include "Deck.h"
#include <iostream>


void Deck::First(int data)
{
	CNode* temp = new CNode;
	temp->data = data;
	temp->next = temp;
	temp->prev = temp;
	_head = temp;
}

void Deck::FPush(int data)
{
	if (_head == NULL)
	{
		First(data);
		return;
	}
	CNode* temp = new CNode{ data, _head, _head->prev };
	_head->prev->next = temp;
	_head->prev = temp;
	_head = temp;
}

void Deck::BPush(int data)
{
	if (_head == NULL)
	{
		First(data);
		return;
	}
	CNode* temp = new CNode{ data, _head, _head->prev };
	_head->prev->next = temp;
	_head->prev = temp;
}

int Deck::FPop()
{
	if (_head == NULL) { return INT_MIN; }
	if (_head->next == _head)
	{
		delete _head;
		_head = NULL;
		return INT_MIN;
	}
	CNode* del = _head;
	int saved = del->data;
	_head = _head->next;
	_head->prev = del->prev;
	del->prev->next = _head;
	delete del;
	return saved;
}

int Deck::BPop()
{
	if (_head == NULL) { return INT_MIN; }
	if (_head->next == _head)
	{
		delete _head;
		_head = NULL;
		return INT_MIN;
	}
	CNode* del = _head->prev;
	int saved = del->data;
	_head->prev = del->prev;
	del->prev->next = _head;
	delete del;
	return saved;
}

int Deck::Count() const
{
	int count = 0;
	CNode* temp = _head;
	do
	{
		count++;
		temp = temp->next;
	} while (temp != _head);
	return count;
}

void Deck::Clear()
{
	CNode* temp = _head;
	do
	{
		CNode* del = temp;
		temp = temp->next;
		delete del;
		del = NULL;
	}
	while (temp != _head);
	_head = NULL;
}

void Deck::Outlist()
{
	if (_head == NULL)
	{
		std::cout << "This deck is empty" << std::endl;
		return;
	}
	CNode* temp = _head;
	do
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	} 
	while (temp != _head);
	std::cout << std::endl;
}