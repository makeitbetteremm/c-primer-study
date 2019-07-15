#pragma once
#include<iostream>

class DmaABC
{
private:
	char *name;
	int rating;
protected:
	const char* Name() const{ return name; }
	int Rating() const { return rating; }
public:
	//constructor
	DmaABC(const char * n = "None", int r = 0);
	DmaABC(const DmaABC &bd);
	virtual ~DmaABC();
	//*
	DmaABC & operator=(const DmaABC &d);
	//vir
	virtual void View() = 0;
};
class BaseDMA :public DmaABC
{
public:
	//constructor
	BaseDMA(const char * n, int r) :DmaABC(n, r) { ; }
	BaseDMA(const DmaABC & d) : DmaABC(d) { ; }
	void View() { DmaABC::View(); }
};

class LackDMA:public DmaABC
{
private:
	enum {COL_LEN=40};
	char color[COL_LEN];
public:
	//cons
	LackDMA(const char *c = "alpha", const char * n = "None", int r = 0);
	LackDMA(const char *c, const DmaABC &d);
	//vir
	virtual void View() { DmaABC::View(); std::cout << "Color: " << color << std::endl; }
};
class HasDMA :public DmaABC
{
private:
	char *style;
public:
	//cons
	HasDMA(const char*s = "None", const char * n = "None", int r = 0);
	HasDMA(const char*s, const DmaABC &d);
	~HasDMA();
	//*
	HasDMA & operator=(const HasDMA &hd);
	//
	virtual void View() { DmaABC::View(); std::cout << "Style: " << style << std::endl; }
};