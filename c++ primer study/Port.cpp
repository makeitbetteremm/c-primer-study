#include "Port.h"
using std::cout;
using std::endl;
//cons
Port::Port(const char *br,  const char *st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, 20, st);
	style[19] = '\0';
	bottles = b;
}
Port::Port(const Port &p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
}

//*
Port & Port::operator=(const Port &p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strcpy_s(style, 20, p.style);
	bottles = p.bottles;
	return *this;
}
Port & Port::operator+= (int b)
{
	if (b < 0)
	{
		cout << "Error!\n";
		return *this;
	}
	else
	{
		bottles += b;
		return *this;
	}
}
Port & Port::operator-=(int b)
{
	if (b >= 0 and b <= bottles)
	{
		bottles -= b;
	}
	else
		cout << "Error!\n";
	return *this;

}
//vir
void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}
//friend
std::ostream& operator<<(std::ostream &os, const Port &p)
{
	cout << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

//VintagePort methods
	//cons
Vintageport::Vintageport() : Port()
{
	nickname = new char[5];
	strcpy_s(nickname, 5, "None");
	year = 0;
}
Vintageport::Vintageport(const char *nn, int y, const char*br, const char *st, int b) : Port(br, st, b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}
Vintageport::Vintageport(const char*nn, int y, const Port &p) : Port(p)
{
	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

Vintageport::Vintageport(const Vintageport &vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}
//*
Vintageport & Vintageport::operator=(const Vintageport &vp)
{
	Port::operator=(vp);
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
	return *this;
}
//vir
void Vintageport::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}
//fri
std::ostream & operator<<(std::ostream &os, const Vintageport &vp)
{
	os << (const Port &)vp;
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}