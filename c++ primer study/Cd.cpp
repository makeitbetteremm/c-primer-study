#include "Cd.h"
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;
Cd::Cd(const char *s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	label = new char[strlen(s2) + 1];
	strcpy_s(label, strlen(s2) + 1, s2);
	selections = n;
	playtime = x;
}
Cd::Cd()
{
	performers = '\0';
	label = '\0';
	selections = 0;
	playtime = 0;
}
Cd::Cd(const Cd &d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}
//*
Cd & Cd::operator=(const Cd &d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
//vir
void Cd::Report() const
{
	cout << "\nPerformers: " << performers << "\n Label: " << label << "\n Selections: " << selections << "\n Playtime: " << playtime;
}
//Classic methods
//cons
Classic::Classic(const char *fa, const char *s1, const char* s2, int n, double x) :Cd(s1, s2, n, x)
{
	famous = new char[strlen(fa) + 1];
	strcpy_s(famous, strlen(fa) + 1, fa);
}
Classic::Classic(const char *fa, const Cd & d) : Cd(d)
{
	famous = new char[strlen(fa) + 1];
	strcpy_s(famous, strlen(fa) + 1, fa);
}
Classic::Classic()
{
	famous = '\0';
}
Classic::Classic(const Classic &c):Cd(c)
{
	famous = new char[strlen(c.famous) + 1];
	strcpy_s(famous, strlen(c.famous) + 1, c.famous);
}
Classic::~Classic()
{
	delete[] famous;
}
//*
Classic & Classic::operator=(const Classic &c)
{
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete[] famous;
	famous = new char[strlen(c.famous) + 1];
	strcpy_s(famous, strlen(c.famous) + 1, c.famous);
	return *this;
}
//vir
void Classic::Report() const
{
	Cd::Report();
	cout << "\n Famous: " << famous;
}