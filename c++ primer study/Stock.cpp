#include "Stock.h"
#include<cstring>

//constructor
using std::cout;
using std::endl;
Stock::Stock()
{
	company = nullptr;
	shares = 0;
	share_val = total_val = 0;
}
Stock::Stock(const char *c, long n, double pr )
{
	int len = strlen(c);
	company = new char[len + 1];
	strcpy_s(company, len + 1, c);
	if (n < 0)
	{
		cout << "Number of shares can't be nagetive;"
			<< company << " shares set to 0.\n";
	}
	else
		shares = n;
	share_val = pr;
	set_total();
}
Stock::Stock(const Stock &s)
{
	int len = strlen(s.company);
	company = new char[len + 1];
	strcpy_s(company, len + 1, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}
Stock::~Stock()
{
	delete[] company;
}
//*
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_total();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. Transaction is aborted.\n";
	}
	else if (num > shares)
		cout << "You can't sell more than you have! " << "Transaction is absorted.\n";
	else
	{
		shares -= num;
		share_val = price;
		set_total();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_total();
}
const Stock & Stock::topval(const Stock &s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
//operator
Stock & Stock::operator=(const Stock &s)
{
	if (company)
		delete[] company;
	int len = strlen(s.company);
	company = new char[len + 1];
	strcpy_s(company, len + 1, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	return *this;
}
//friend
std::ostream & operator<<(std::ostream &os, const Stock &s)
{
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	os << "company: " << s.company << " shares: " << s.shares;
	cout << " share price: " << s.share_val;
	cout.precision(2);
	cout << " Total worth: $" << s.total_val;
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
	return os;
}

