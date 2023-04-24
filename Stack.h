#pragma once

class Stack
{
private:
	struct Node
	{
		int data;
		Node* next;
	};

	Node* _top;
	
public:
	
	Stack() { _top = 0; }
	Stack(const Stack& Stack) = delete;
	Stack& operator=(const Stack& Stack) = delete;
	~Stack() { Clear(); }

	void Push(int data);
	int Pop();
	int Peek() const { return _top->data; }
	void Clear();
	int Count() const;
	void Output();
	bool Is_Empty() const { return _top == 0; }
};



