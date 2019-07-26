#pragma once
template<typename T>
class Queue
{
private:
	struct Node
	{
		T item;
		Node * Next;
	};
	Node *front, *rear;
	const int qsize;
	int items;
	enum { QLIM = 10 };
	Queue(const Queue &q) : qsize(0) {}
	Queue & operator=(const Queue &q) { return *this; }
public:
	Queue(int qs = QLIM);
	~Queue();
	int Qcount() { return items; }
	bool Isempty() { return 0 == items; }
	bool Isfull() { return qsize == items; }
	bool Dequeue(T &it);
	bool Enqueue(T &it);
};
template<typename T>
Queue<T>::Queue(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	while (items > 0)
	{
		Node * temp;
		temp = front;
		front = front->Next;
		delete temp;
		items--;
	}
}

template<typename T>
bool Queue<T>::Dequeue(T &it)
{
	if (Isempty())
		return false;
	it = front->item;
	Node *temp = front;
	front = front->Next;
	delete temp;
	items--;
	if (items == 0)
		rear = nullptr;
	return true;
}

template<typename T>
bool Queue<T>::Enqueue(T &it)
{
	if (Isfull())
		return false;
	Node *node = new Node;
	node->item = it;
	node->Next = nullptr;
	if (items == 0)
		front = rear = node;
	else
	{
		rear->Next = node;
		rear = node;
	}
	items++;
	return true;
}

