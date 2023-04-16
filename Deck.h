#pragma once


class Deck
{
private:
	struct CNode
	{
		int data;
		CNode* next;
		CNode* prev;
	};
	CNode* _head;
	void First(int data);
public:
	Deck() { _head = 0; }
	Deck(const Deck& Deck) = delete;
	~Deck() { Clear(); }
	
	
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

