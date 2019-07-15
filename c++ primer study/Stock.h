#pragma once
#include<iostream>
class Stock
{
private:
	char *company;
	int shares;
	double share_val;
	double total_val;
	void set_total() { total_val = shares * share_val; }
public:
	//constructor
	Stock();
	Stock(const char *c, long n = 0, double pr = 0);
	Stock(const Stock &s);
	~Stock();
	//*
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock & topval(const Stock &s) const;
	//operator
	Stock & operator=(const Stock &s);
	//friend
	friend std::ostream & operator<<(std::ostream &os, const Stock &s);
};

