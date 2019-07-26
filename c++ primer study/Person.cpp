#include "Person.h"
using std::cout;
using std::cin;
using std::endl;
//Person::
void Person::Data() const
{
	std::cout << firstname << ", " << secondname << endl;
}
void Person::Set(const string &s1, const string &s2)
{
	firstname = s1;
	secondname = s2;
}
void Person::Show() const
{
	Data();
}

//Gunslinger::
void Gunslinger::Data() const
{
	cout << "number: " << kh << ", time: " << tm << endl;
}
void Gunslinger::Show() const
{
	Person::Show();
	Data();
}

//PokerPlayer::
void PokerPlayer::Data() const
{
	cout << "Poker: " << pk << endl;
}
void PokerPlayer::Show() const
{
	Person::Show();
	Data();
}

//BadDude::
void BadDude::Show() const
{
	Person::Show();
	PokerPlayer::Data();
	Gunslinger::Data();
}