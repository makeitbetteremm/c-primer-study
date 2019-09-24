#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
using std::cout;
using std::endl;
using std::string;
class Sales
{
public:
	enum { MONTHS = 12 };
private:
	int year;
	double gross[MONTHS];
public:
	class bad_index :public std::logic_error
	{
	private:
		int bi;
	public:
		explicit bad_index(int ix, const string &s = "Index error in Sales object\n") :bi(ix), std::logic_error(s) { ; }
		int bi_val() const { return bi; }
		virtual ~bad_index() throw() {  };
	};
	explicit Sales(int yr = 0);
	Sales(int yr, double *g, int n);
	virtual ~Sales() {};
	int Year() const { return year; }
	virtual double operator[](int i) const;
	virtual double & operator[](int i);
};
class LabelSales : public Sales
{
private:
	string label;
public:
	class bad_lindex :public bad_index
	{
	private:
		string lbl;
	public:
		explicit bad_lindex(const string &s1, int i, const string &s2 = "Index error in labeledSales object\n");
		const string & label_val() const { return lbl; };
		virtual ~bad_lindex() throw() {  };
	};
	explicit LabelSales(const string &s1 = "None", int yr = 0);
	LabelSales(const string &s1, int yr, double *g, int n);
	virtual ~LabelSales() {};
	const string & Label() const { return label; }
	virtual double operator[](int i) const;
	virtual double & operator[](int i);
};
