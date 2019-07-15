#pragma once
#include<iostream>
class Port
{
private:
	char *brand;
	char style[20];
	int bottles;
public:
	//cons
	Port(const char *br = "None", const char *st = "None", int b = 0);
	Port(const Port &p);
	virtual ~Port() { delete[] brand; }
	//*
	Port & operator=(const Port &p);
	Port & operator+= (int b);
	Port & operator-=(int b);
	int BottleCount() const { return bottles; }
	//vir
	virtual void Show() const;
	//friend
	friend std::ostream& operator<<(std::ostream &os, const Port &p);
};
class Vintageport : public Port
{
private:
	char * nickname;
	int year;
public:
	//cons
	Vintageport();
	Vintageport(const char *nn, int y, const char*br, const char *st, int b);
	Vintageport(const char*nn, int y, const Port &p);
	Vintageport(const Vintageport &vp);
	~Vintageport() { delete[] nickname; }
	//*
	Vintageport & operator=(const Vintageport &vp);
	//vir
	void Show() const;
	//fri
	friend std::ostream & operator<<(std::ostream &os, const Vintageport &vp);
};
