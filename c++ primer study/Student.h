#pragma once
#include<iostream>
#include<valarray>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class Student:private std::string ,private std::valarray<double>
{
private:
	typedef std::valarray<double> arrayDd;
	//private methods
	std::ostream & arr_out(std::ostream &os);
public:
	//cons
	Student() :string("Null Student"), arrayDd() { ; }
	explicit Student(string &s) :string(s), arrayDd() { ; }
	explicit Student(int n) : string("Nully"), arrayDd(n) { ; }
	Student(string &s, int n) :string(s), arrayDd(n) { ; }
	Student(string &s, arrayDd d) :string(s), arrayDd(d) { ; }
	Student(string &s, double x, int n) :string(s), arrayDd(x, n) { ; }
	~Student() { ; }
	//*
	double Average() const;
	const string & Name() const { return (const string &) *this;}
	double & operator[](int i);
	double operator[](int i) const;
	//friend
	friend std::istream & operator>>(std::istream &is, Student &stu);
	friend std::istream & getline(std::istream &is, Student &stu);
	friend std::ostream & operator<<(std::ostream &os, Student &stu);
};

