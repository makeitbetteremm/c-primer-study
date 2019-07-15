#include "mytime.h"
#include <iostream>

using std::cout;
using std::endl;

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += m / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::reset(int h, int m)
{
	hours = h;
	minutes = m;
}
//friend
Time operator+(const Time &t1, const Time &t2)
{
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time operator-(const Time &t1, const Time &t2)
{
	int total1, total2;
	Time sub;
	total1 = t1.hours * 60 + t1.minutes;
	total2 = t2.hours * 60 + t2.minutes;
	sub.minutes = total1 - total2;
	sub.hours += sub.minutes / 60;
	sub.minutes %= 60;
	return sub;
}
Time operator*(const Time &t, double n)
{
	int total = t.hours * 60 + t.minutes;
	total *= n;
	Time mult;
	mult.hours = total / 60;
	mult.minutes = total % 60;
	return mult;
}
Time operator*(double n, const Time &t)
{
	return t * n;
}
std::ostream & operator<<(std::ostream & os, const Time &t)
{
	os << t.hours << " hours, " << t.minutes << " minutes\n";
	return os;
}