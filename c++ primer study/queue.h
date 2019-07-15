#pragma once
#include<cstdlib>
class customer
{
private:
	long arrive;
	int processtime;
public:
	customer() { arrive = processtime = 0; }
	void set(long when) { arrive = when; processtime = rand() % 3 + 1; }
	long when() const { return arrive; }
	int process() const { return processtime; }
};

typedef customer Item;
class queue
{
private:
	struct Node
	{
		Item item;
		Node * Next;
	};
	Node *front, *rear;
	const int qsize;
	int items;
	enum { QLIM = 10 };
	queue(const queue &q) : qsize(0) {}
	queue & operator=(const queue &q) { return *this; }
public:
	queue(int qs = QLIM);
	~queue();
	int qcount() { return items; }
	bool isempty() { return 0 == items; }
	bool isfull() { return qsize == items;}
	bool dequeue(Item &it);
	bool enqueue(Item &it);
};

