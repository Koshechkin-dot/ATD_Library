#pragma once

class Queue
{
private:
	struct LinkedList
	{
		int data;
		LinkedList* next;
		LinkedList* prev;
	};
	LinkedList* _tail;
	LinkedList* _curr;
public:
	Queue() { _tail = _curr = 0; }
	Queue(const Queue& Queue) = delete;
	~Queue() { Clear(); }

	void Push(int data);
	int Pop();
	int Peek();
	int Count();
	bool Is_Empty() { return _tail == 0; }
	void Clear();
	void Outlist();
};

