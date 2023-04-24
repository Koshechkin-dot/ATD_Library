#include "Queue.h"
#include <iostream>


void Queue::Push(int data)
{
    if (_tail == NULL)
    {
        _tail = _curr = new Node{ data, NULL, NULL };
        return;
    }
    _curr->prev = new Node{ data, _curr, NULL };
    _curr = _curr->prev;
}

int Queue::Pop()
{
    if (_tail == NULL) { return INT_MIN; }
    if (_tail == _curr)
    {
        int saved = _tail->data;
        delete _tail;
        _tail = _curr = NULL;
        return saved;
    }
    Node* del = _tail;
    int saved = _tail->data;
    _tail = _tail->prev;
    delete del;
    return saved;
}

int Queue::Peek() { return (_tail == NULL) ? INT_MIN : _tail->data; }

int Queue::Count()
{
    int count = 0;
    Node* temp = _tail;
    while (temp != NULL)
    {
        temp = temp->prev;
        count++;
    }
    return count;
}

void Queue::Clear()
{
    while (_tail != NULL)
    {
        Node* del = _tail;
        _tail = _tail->prev;
        delete del;
    }
    _tail = _curr = NULL;
}

void Queue::Outlist()
{
    if (_tail == NULL)
    {
        std::cout << "This queue is empty" << std::endl;
        return;
    }
    Node* temp = _tail;
    while (temp != NULL)
    {
        std::cout << temp->data << ' ';
        temp = temp->prev;
    }
    std::cout << std::endl;
}
