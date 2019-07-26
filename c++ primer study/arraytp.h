#pragma once
#include<iostream>
#include<cstdlib>

template<typename T, int n>
class Array
{
private:
	T arr[n];
public:
	Array() { };
	explicit Array(const T &v);
	T & operator[](int i);
	T operator[](int i) const;
};

template<typename T, int n>
Array<T,n>::Array(const T &v)
{
	for (int i = 0; i < n; i++)
		arr[i] = v;
}
template<typename T, int n>
T & Array<T, n>::operator[](int i)
{
	if (i < 0 || i >= n)
	{
		std::cout << "Error index " << i << " is out of range.\n";
		std::exit(EXIT_FAILURE);
	}
	else
	{
		return arr[i];
	}
}
template<typename T, int n>
T Array<T, n>::operator[](int i) const
{
	if (i < 0 || i >= n)
	{
		std::cout << "Error index " << i << " is out of range.\n";
		std::exit(EXIT_FAILURE);
	}
	else
	{
		return arr[i];
	}
}
