#pragma once
#include<iostream>
class stringbad
{
private:
	char * str;
	int len;
	static int num_string;
	static const int CINLIM = 80;
public:
	stringbad();
	stringbad(const char * s);
	stringbad(const stringbad &s);
	~stringbad();
	int length() { return len; }
	void stringlow();
	void stringup();
	int has(char ch);
	//operator 
	stringbad & operator=(const stringbad &s);
	stringbad & operator=(const char * s);
	char & operator[](int i) { return str[i]; }
	const char & opetator(int i) const { return str[i]; }
	bool operator<(const stringbad &s) const;
	bool operator>(const stringbad &s) const;
	bool operator==(const stringbad &s) const;
	stringbad operator+(const stringbad &s) const;
	stringbad operator+(const char *c) const;
	//friend 
	friend std::ostream & operator<<(std::ostream &os, const stringbad &s);
	friend std::istream & operator>>(std::istream &is, stringbad &s);
	friend stringbad operator+(const char *c, const stringbad &s);
	//static
	static int howmany();
};

