#pragma once
#include<string>
class TableTennisPlayer
{
private:
	std::string firstname;
	std::string lastname;
	bool hasTable;
public:
	//constructor
	TableTennisPlayer(const std::string &fn = "none", const std::string &ln = "none", bool b = false);
	//*
	void name() const;
	bool HasTable() const { return hasTable; }
	void ResetTable(bool ht) { hasTable = ht; }
};

class RatedPlayer: public TableTennisPlayer
{
private:
	unsigned int rate;
public:
	RatedPlayer(unsigned int r = 0, const std::string &fn = "none", const std::string &ln = "none", bool b = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
	unsigned int Rating() const { return rate; }
	void ResetRating(unsigned int rt) { rate = rt; }
};

