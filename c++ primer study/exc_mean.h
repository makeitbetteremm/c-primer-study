#pragma once
#include<iostream>
using std::cout;
using std::endl;
class bad_hmean
{
private:
	double a;
	double b;
public:
	bad_hmean(double x, double y) :a(x), b(y) { ; }
	void mesg();
};
void bad_hmean::mesg()
{
	cout << "hmean( " << a << ", " << b << " ): invalid arguments: a = -b\n";
}
class bad_gmean
{
public:
	double a;
	double b;
	bad_gmean(double x, double y) :a(x), b(y) { ; }
	const char* mesg();
};
const char* bad_gmean::mesg()
{
	return "gmean() argument shouble be >= 0 \n";
}