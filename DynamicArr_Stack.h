#pragma once
class Dynamic_Stack
{
private:
	int* _arr;
	int _size;
public:
	Dynamic_Stack() : _arr(nullptr), _size(0) {}
	Dynamic_Stack(const Dynamic_Stack& Stack) = delete;
	~Dynamic_Stack() { Clear(); }
	void Push(int data);
	int Pop();
	int Peek();
	void Clear();
	void Output();
	int Count() { return _size; }
	bool Is_Empty() { return _size == 0; }
};

