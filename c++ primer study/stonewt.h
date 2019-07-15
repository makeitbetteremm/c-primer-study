#pragma once
#include<iostream>
class Stonewt
{
public:
	enum Mode { STONE, INT_P, DOU_P };
private:
	enum {lbs_per_stn=14};
	int stones;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt();
	Stonewt(double n);
	Stonewt(int n, double p);
	~Stonewt();
	void ex_mode(Mode m);
	operator int() const;
	operator double() const;
	Stonewt operator*(double n) const;
	bool operator<(const Stonewt &t) const;
	bool operator<=(const Stonewt &t) const;
	bool operator>(const Stonewt &t) const;
	bool operator>=(const Stonewt &t) const;
	bool operator==(const Stonewt &t) const;
	bool operator!=(const Stonewt &t) const;
	//friend
	friend std::ostream& operator<<(std::ostream &os, const Stonewt &s);
};
