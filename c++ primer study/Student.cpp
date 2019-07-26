#include "Student.h"

//private methods
std::ostream & Student::arr_out(std::ostream &os)
{
	int lim = arrayDd::size();
	if (lim > 0)
	{
		int i;
		for (i = 0; i < lim; i++)
		{
			os << arrayDd::operator[](i) << " ";
			if (i % 5 == 4)
				cout << endl;
		}
		if (i % 5 != 0)
			cout << endl;
	}
	else
	{
		cout << "Empty array.\n";
	}
	return os;
}

//*
double Student::Average() const
{
	if (arrayDd::size() == 0)
		return -1;
	else
		return arrayDd::sum() / arrayDd::size();
}
double & Student::operator[](int i)
{
	return arrayDd::operator[](i);
}
double Student::operator[](int i) const
{
	return arrayDd::operator[](i);
}
//friend
std::istream & operator>>(std::istream &is, Student &stu)
{
	is >> (string &) stu;
	return is;
}
std::istream & getline(std::istream &is, Student &stu)
{
	getline(is, (string &)stu);
	return is;
}
std::ostream & operator<<(std::ostream &os, Student &stu)
{
	os << (const string & )stu << endl;
	stu.arr_out(os);
	return os;
}
