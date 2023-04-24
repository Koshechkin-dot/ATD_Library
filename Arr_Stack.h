#pragma once

class Array_Stack
{
private:
	int* _array, _top = -1, _Size;
public:
	Array_Stack(int Size) : _array(new int[Size]), _Size(Size) {}
	Array_Stack(const Array_Stack& Array_Stack) = delete;
	Array_Stack& operator=(const Array_Stack& Array_Stack) = delete;
	~Array_Stack() { delete[] _array; }

	void Push(int data);
	int Pop();
	int Peek() const;
	void Clear() { _top = -1; }
	int Count() const { return _top + 1; }
	bool Is_Empty() const { return _top == -1; }
	void Output();
};