#include "Wine.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

Wine::Wine(const char*l, int y, const int yr[], const int bot[]) : PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
	label = l;
	years = y;
}
Wine::Wine(const char*l, int y): PairArray(ArrayInt(y), ArrayInt(y))
{
	label = l;
	years = y;
}
void Wine::GetBottles()
{
	if (years > 0)
	{
		cout << "Enter " << label << " data for " << years << " year(s)";
		for (int i = 0; i < years; i++)
		{
			int a, b;
			cout << "Enter year: ";
			cin >> a;
			PairArray::first()[i] = a;
			cout << "Enter bottles for that year: ";
			cin >> b;
			PairArray::second()[i] = b;
		}
		cin.get();
	}
	else
		cout << "Error!\n";
}

void  Wine::Show() const
{
	cout << "Wine: " << label;
	cout.width(6);
	cout << "Year";
	cout.width(8);
	cout << "Bottles\n";
	for (int i = 0; i < years; i++)
	{
		cout.width(11);
		cout << PairArray::first()[i];
		cout.width(8);
		cout << PairArray::second()[i];
		cout << endl;
	}
}
int Wine::Sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += PairArray::second()[i];
	return sum;
}
