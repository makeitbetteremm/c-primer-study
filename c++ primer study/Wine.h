#pragma once
#include<valarray>
#include<string>
typedef std::valarray<int> ArrayInt;
template<typename T1, typename T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	Pair() { };
	Pair(const T1 &x, const T2 &y) :a(x), b(y) { };
	T1 & first() { return a; }
	T2 & second() { return b; }
	T1 first() const { return a; }
	T2 second() const { return b; }
};

typedef Pair<ArrayInt, ArrayInt> PairArray;
class Wine:private PairArray
{

private:
	std::string label;
	int years;
public:
	Wine() { label = "null"; years = 0; }
	Wine(const char*l, int y, const int yr[], const int bot[]);
	Wine(const char*l, int y);
	void GetBottles();
	std::string Label() const { return label; }
	void Show() const;
	int Sum() const;
};

