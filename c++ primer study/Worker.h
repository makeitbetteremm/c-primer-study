#pragma once
#include<iostream>
#include<string>
using std::string;
class Worker
{
private:
	string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	//cons
	Worker() :fullname("null"), id(0L) { ; }
	Worker(const string &s, long l) :fullname(s), id(l) { ; }
	virtual ~Worker() = 0;
	//*
	virtual void Set() = 0;
	virtual void Show() = 0;
};
//Waiter
class Waiter :virtual public Worker
{
private:
	int panache;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Waiter() :Worker(), panache(0) { ; }
	Waiter(const string&s, long l, int p) :Worker(s, l), panache(p) { ; }
	Waiter(const Worker &w, int p) :Worker(w), panache(p) { ; }
	//*
	virtual void Set();
	virtual void Show();
};
//Singer
class Singer :virtual public Worker
{
protected:
	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	virtual void Data() const;
	virtual void Get();
private:
	static const char* vp[Vtypes];
	int voice;
public:
	Singer() :Worker(), voice(0) { ; }
	Singer(const string&s, long l, int v) :Worker(s, l), voice(v) { ; }
	Singer(const Worker &w, int v) :Worker(w), voice(v) { ; }
	//*
	virtual void Set();
	virtual void Show();
};

class SingerWaiter :public Singer, public Waiter
{
protected:
	virtual void Data() const;
	virtual void Get();
public:
	SingerWaiter() { ; }
	SingerWaiter(const string&s, long l, int p, int v) :Worker(s, l), Singer(s, l, v), Waiter(s, l, p) { ; }
	SingerWaiter(const Worker &wk, int p, int v) :Worker(wk), Singer(wk, v), Waiter(wk, p) { ; }
	SingerWaiter(const Waiter &wt, int p, int v) :Worker(wt), Singer(wt, v), Waiter(wt, p) { ; }
	SingerWaiter(const Singer &sr, int p, int v) :Worker(sr), Singer(sr, v), Waiter(sr, p) { ; }
	//*
	void Set();
	void Show();
};