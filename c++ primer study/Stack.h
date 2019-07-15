#pragma once
typedef unsigned long Item;
class Stack
{
private:
	enum { Max = 10 };
	Item *pitems;
	int size;
	int top;
public:
	//Consructor
	Stack(int n = Max);
	Stack(const Stack &st);
	~Stack();
	//*
	bool isempty() const;
	bool isfull() const;
	bool push(const Item &item);
	bool pop(Item &item);
	Stack & operator=(const Stack &st);
};

