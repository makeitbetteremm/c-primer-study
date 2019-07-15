#pragma once
class Cd
{
private:
	char *performers;
	char *label;
	int selections;
	double playtime;
public:
	//cons
	Cd(const char *s1, const char* s2, int n, double x);
	Cd();
	Cd(const Cd &d);
	virtual ~Cd();
	//*
	Cd & operator=(const Cd &d);
	//vir
	virtual void Report() const;
};

class Classic:public Cd
{
private:
	char *famous;
public:
	//cons
	Classic(const char *fa, const char *s1, const char* s2, int n, double x);
	Classic(const char *fa, const Cd & d);
	Classic();
	Classic(const Classic &c);
	~Classic();
	//*
	Classic & operator=(const Classic &c);
	//vir
	virtual void Report() const;
};
