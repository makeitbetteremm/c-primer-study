#include "queue.h"



queue::queue(int qs ):qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}
queue::~queue()
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

bool queue::dequeue(Item &it)
{
	if (isempty())
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
bool queue::enqueue(Item &it)
{
	if (isfull())
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

