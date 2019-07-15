#include "DMA.h"
#include<cstring>
using std::cout;
using std::endl;
//constructor
DmaABC::DmaABC(const char * n, int r)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	rating = r;
}
DmaABC::DmaABC(const DmaABC &d)
{
	name = new char[strlen(d.name) + 1];
	strcpy_s(name, strlen(d.name) + 1, d.name);
	rating = d.rating;
}
DmaABC::~DmaABC()
{
	delete[] name;
}
//*
DmaABC & DmaABC::operator=(const DmaABC &d)
{
	if (this == &d)
		return *this;
	delete[] name;
	name = new char[strlen(d.name) + 1];
	strcpy_s(name, strlen(d.name) + 1, d.name);
	rating = d.rating;
	return *this;
}
//vir
void  DmaABC::View()
{
	cout << "Name: " << name << endl;
	cout << "Rating: " << rating << endl;
}
//baseDMA methods


//LackDMA methods
//cons
LackDMA::LackDMA(const char *c, const char * n, int r): DmaABC(n, r)
{
	strcpy_s(color, 39, c);
	color[39] = '\0';
}
LackDMA::LackDMA(const char *c, const DmaABC &d) : DmaABC(d)
{
	strcpy_s(color, 39, c);
	color[39] = '\0';
}
//friend
//HasDMA methods
//cons
HasDMA::HasDMA(const char *s, const char * n, int r): DmaABC(n, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}
HasDMA::HasDMA(const char*s, const DmaABC &d): DmaABC(d)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}
HasDMA::~HasDMA()
{
	delete[] style;
}
//*
HasDMA & HasDMA::operator=(const HasDMA &hd)
{
	if (this == &hd)
		return *this;
	delete[] style;
	DmaABC::operator=(hd);
	style = new char[strlen(hd.style) + 1];
	strcpy_s(style, strlen(hd.style) + 1, hd.style);
	return *this;
}
