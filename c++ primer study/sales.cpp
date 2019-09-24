#include"sales.h"
Sales::Sales(int yr)
{
	year = yr;
	for (int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}
Sales::Sales(int yr, double *g, int n)
{
	year = yr;
	int lim = (n < MONTHS) ? n : MONTHS;
	int i = 0;
	for (; i < lim; i++)
		gross[i] = g[i];
	for (; i < MONTHS; i++)
		gross[i] = 0;
}
double Sales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}
double & Sales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}
//salelabel

LabelSales::bad_lindex::bad_lindex(const string &s1, int i, const string &s2) :bad_index(i, s2)
{
	lbl = s1;
}

LabelSales::LabelSales(const string &s1, int yr) : Sales(yr)
{
	label = s1;
}

LabelSales::LabelSales(const string &s1, int yr, double *g, int n) : Sales(yr, g, n)
{
	label = s1;
}

double LabelSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_lindex(label, i);
	return Sales::operator[](i);
}
double & LabelSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw bad_lindex(label, i);
	return Sales::operator[](i);
}