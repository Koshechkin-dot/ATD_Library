#pragma once

class Queue
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};
	Node* _tail;
	Node* _curr;
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

