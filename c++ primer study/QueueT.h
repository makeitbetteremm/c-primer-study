#pragma once
template<class Item>
class QueueT
{
private:
	enum { Qsize = 10 };
	class Node
	{
	public:
		Item item;
		Node * next;
		Node(Item & i) :item(i), next(nullptr) { ; }
	};
	Node * rear;
	Node * front;
	int items = 0;
	const int qsize;
	QueueT(const QueueT& q) :qsize(0) { ; }
	QueueT & operator=(QueueT& q) { return *this; }
public:
	QueueT(int q = Qsize);
	~QueueT();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int queuecount() const { return items; }
	bool enqueue(Item & it);
	bool dequeue(Item &it);
};
template<class Item>
QueueT<Item>::QueueT(int q ):qsize(q)
{
	rear = front = nullptr;
	items = 0;
}
template<class Item>
QueueT<Item>::~QueueT()
{
	Node *temp;
	while (front !=nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<class Item>
bool QueueT<Item>::enqueue(Item & it)
{
	if (isfull())
		return false;
	Node * add = new Node(it);
	if (items == 0)
		front = add;
	else
		rear->next = add;
	items++;
	rear = add;
	return true;
}
template<class Item>
bool QueueT<Item>::dequeue(Item &it)
{
	if (isempty())
		return false;
	it = front->item;
	Node * temp;
	temp = front;
	front = front->next;
	delete temp;
	items--;
	if (items == 0)
		rear = 0;
	return true;
}