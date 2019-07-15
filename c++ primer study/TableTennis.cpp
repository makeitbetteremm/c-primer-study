#include"TableTennis.h"
#include<iostream>
TableTennisPlayer::TableTennisPlayer(const std::string &fn , const std::string &ln, bool b)
{
	firstname = fn;
	lastname = ln;
	hasTable = b;
}

void TableTennisPlayer::name() const
{
	std::cout << firstname << " , " << lastname;
}
//RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r , const std::string &fn , const std::string &ln , bool b ) :TableTennisPlayer(fn, ln, b)
{
	rate = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp)
{
	rate = r;
}
