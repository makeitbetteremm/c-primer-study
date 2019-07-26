#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using std::string;
using std::srand;
using std::time;
class Person
{
private:
	string firstname;
	string secondname;
protected:
	void Data() const;

public:
	Person(const string &s1 = "F1", const string &s2 = "S2") :firstname(s1), secondname(s2) { };
	virtual ~Person() { };
	virtual void Show() const;
	virtual void Set(const string &s1 = "F1", const string &s2 = "S2");
};

class Gunslinger :virtual public Person
{
private:
	int kh;
	double tm;
protected:
	void Data() const;
public:
	Gunslinger(int num = 0) :kh(num) { tm = time(0); }
	Gunslinger(const string &s1, const string &s2, int num) :Person(s1, s2), kh(num) { tm = time(0); }
	Gunslinger(const Person &p, int num) :Person(p), kh(num) {  tm = time(0); }
	virtual ~Gunslinger() { };
	double Draw() const { return tm; }
	virtual void Show() const;
};

class PokerPlayer :virtual public Person
{
private:
	int pk;
protected:
	void Data() const;
public:
	PokerPlayer() { srand(time(0)); pk = rand() % 52 + 1; }
	PokerPlayer(const string &s1, const string &s2) :Person(s1, s2) { srand(time(0)); pk = rand() % 52 + 1; }
	virtual ~PokerPlayer() { };
	double Draw() const { return pk; }
	virtual void Show() const;
};

class BadDude :public Gunslinger, public PokerPlayer
{
public:
	BadDude() :Person(), Gunslinger(), PokerPlayer() { };
	BadDude(const string &s1, const string &s2, int num) :Person(s1, s2), Gunslinger(num) { };
	BadDude(const Person &p, int num) :Person(p), Gunslinger(num) { };
	BadDude(const Person &p) :Person(p) { };
	BadDude(const Gunslinger &p) :Person(p), Gunslinger(p) { };
	BadDude(const PokerPlayer &p) :Person(p), PokerPlayer(p) { };
	double Gdraw() { Gunslinger::Draw(); }
	int Cdraw() { PokerPlayer::Draw(); }
	virtual void Show() const;
};

