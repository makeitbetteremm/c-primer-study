#pragma once
template <typename T>
class Stack
{
private:
	enum {Max = 10};
	int stacksize;
	T * items;
	int top;
public:
	Stack(int ss = Max);
	Stack(const Stack &s);
	~Stack();
	Stack & operator=(const Stack &s);
	bool isfull() const;
	bool isempty() const;
	bool push(T &item);
	bool pop(T &item);
};
template <typename T>
Stack<T>::Stack(int ss)
{
	stacksize = ss;
	top = 0;
	items = new T[stacksize];
}
template <typename T>
Stack<T>::Stack(const Stack &s)
{
	stacksize = s.stacksize;
	items = new T[stacksize];
	top = s.top;
}
template <typename T>
Stack<T>::~Stack()
{
	delete[] items;
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &s)
{
	if (this == &s)
		return *this;
	delete[]items;
	stacksize = s.stacksize;
	items = new T[stacksize];
	top = s.top;
	return *this;
}

template <typename T>
bool Stack<T>::isfull() const
{
	return top == stacksize;
}

template <typename T>
bool  Stack<T>::isempty() const
{
	return top == 0;
}

template <typename T>
bool Stack<T>::push(T &item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <typename T>
bool Stack<T>::pop(T &item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

