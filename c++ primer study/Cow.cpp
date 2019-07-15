#include "Cow.h"
#include<iostream>
#include<cstring>
Cow::Cow()
{
	name[20] = '\0';
	hobby = nullptr;
	weight = 0;
}
Cow::Cow(const char* nm, const char * ho, double wt)
{
	strcpy_s(name, 20, nm);
	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, ho);
	weight = wt;
}
Cow::Cow(const Cow &c)
{
	strcpy_s(name, 20, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
}
Cow::~Cow()
{
	delete[]hobby;
}
Cow & Cow::operator=(const Cow &c)
{
	strcpy_s(name, c.name);
	int len = strlen(c.hobby);
	if(hobby=nullptr)
		delete[] hobby;
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
	return *this;
}
void Cow::ShowCow() const
{
	using std::cout;
	using std::endl;
	cout << name << ": " << hobby << ", " << weight << endl;
}
