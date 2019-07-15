#include "stringbad.h"
#include<cstring>
#include<cctype>
using std::cout;
using std::endl;
int stringbad::num_string = 0;
stringbad::stringbad()
{
	len = 0;
	str = new char[1];
	str = nullptr;
	num_string++;
}
stringbad::stringbad(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_string++;;
}
stringbad::stringbad(const stringbad &s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	num_string++;
}
stringbad::~stringbad()
{
	num_string--;
	delete[] str;
}

void stringbad::stringlow()
{
	for (int i = 0; i < len; i++)
		if (isalpha(str[i]))
			str[i] = tolower(str[i]);
}
void stringbad::stringup()
{
	for (int i = 0; i < len; i++)
		if (isalpha(str[i]))
			str[i] = toupper(str[i]);
}
int stringbad::has(char ch)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if (tolower(str[i]) == tolower(ch))
			count++;
	return count;
}
//operator 
stringbad & stringbad::operator=(const stringbad &s)
{
	if(&s==this)
		return *this;
	len = s.len;
	delete[] str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	return *this;
}
stringbad & stringbad::operator=(const char * s)
{
	len = strlen(s);
	delete[] str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

bool stringbad::operator<(const stringbad &s) const
{
	return(strcmp(this->str, s.str) < 0);
}
bool stringbad::operator>(const stringbad &s) const
{
	return s.str < this->str;
}
bool stringbad::operator==(const stringbad &s) const
{
	return(strcmp(this->str, s.str) == 0);
}

stringbad stringbad::operator+(const stringbad &s) const
{
	stringbad temp;
	temp.len = len + s.len;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, temp.len + 1, str);
	strcat_s(temp.str, temp.len + 1, s.str);
	return temp;
}
stringbad stringbad::operator+(const char *c) const
{
	return *this + stringbad(c);
}
//friend 
std::ostream & operator<<(std::ostream &os, const stringbad &s)
{
	os << s.str;
	return os;
}

std::istream & operator>>(std::istream &is, stringbad &s)
{
	char temp[stringbad::CINLIM];
	is.get(temp, stringbad::CINLIM);
	if (is)
		s = temp;
	while (is and is.get() != '\n');
	return is;
}

stringbad operator+(const char *c, const stringbad &s)
{
	return  stringbad(c) + s;
}

//static
int stringbad::howmany()
{
	return num_string;
}