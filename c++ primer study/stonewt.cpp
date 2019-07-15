#include"stonewt.h""
#include<iostream>
using std::cout;
using std::endl;

Stonewt::Stonewt()
{
	stones = pounds = pds_left = 0;
	mode = STONE;
}
Stonewt::Stonewt(double n)
{
	pounds = n;
	stones = int(n) / lbs_per_stn;
	pds_left = int(n) % lbs_per_stn + n - int(n);
	mode = STONE;
}
Stonewt::Stonewt(int n, double p)
{
	stones = n;
	pds_left = p;
	pounds = n * lbs_per_stn + p;
	mode = STONE;
}
Stonewt::~Stonewt()
{

}

Stonewt::operator int() const
{
	return int(pounds + 0.5);
}
Stonewt::operator double() const
{
	return pounds;
}
Stonewt Stonewt::operator*(double n) const
{
	return Stonewt(n*pounds);
}
void Stonewt::ex_mode(Mode m)
{
	mode = m;
}
bool  Stonewt::operator<(const Stonewt &t) const
{
	return pounds < t.pounds;
}
bool  Stonewt::operator<=(const Stonewt &t) const
{
	return pounds <= t.pounds;
}
bool  Stonewt::operator>(const Stonewt &t) const
{
	return pounds > t.pounds;
}
bool  Stonewt::operator>=(const Stonewt &t) const
{
	return pounds >= t.pounds;
}
bool  Stonewt::operator==(const Stonewt &t) const
{
	return pounds == t.pounds;
}
bool  Stonewt::operator!=(const Stonewt &t) const
{
	return pounds != t.pounds;
}
//friend
std::ostream& operator<<(std::ostream &os, const Stonewt &s)
{
	if (Stonewt::STONE == s.mode)
		os << s.stones << " stones, " << s.pds_left << " pounds\n";
	else if (Stonewt::INT_P == s.mode)
		os << int(s.pounds) << " pounds\n";
	else if (Stonewt::DOU_P == s.mode)
		os << s.pounds << " pounds\n";
	else
		os << "Error.\n";
	return os;
}