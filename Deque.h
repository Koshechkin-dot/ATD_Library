#pragma once


class Deque
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};
	Node* _head;
	void First(int data);
public:
	Deque() { _head = 0; }
	Deque(const Deque& Deque) = delete;
	~Deque() { Clear(); }
	
	
	void FPush(int data);
	void BPush(int data);
	int FPop();
	int BPop();
	int FPeek() const { return _head->data; }
	int BPeek() const { return _head->prev->data; }
	int Count() const;
	bool Is_Empty() { return _head == 0; }
	void Clear();
	void Outlist();
};

