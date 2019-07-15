#pragma once
#include<string>
using std::string;
class ActABC
{
private:
	string name;
	long accountnum;
	double balance;
protected:
	const string & Accountname() const { return name; }
	const long Accountnumber() const { return accountnum; }
	struct formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	formatting Setformat() const;
	void Restore(const formatting &f) const;
public:
	//cons
	ActABC(const string &n = "None", long acct = -1, double b = 0);
	virtual ~ActABC() { ; }
	//*
	double Balance() const { return balance; }
	void Deposit(double b);
	//pure virtual
	virtual void Viewaccount() const = 0;
	virtual void Withdraw(double am) = 0 { balance -= am; }
};
class Brass:public ActABC
{
public:
	//cons
	Brass(const string &n = "None", long acct = -1, double b = 0);
	//virtual
	virtual void Viewaccount() const;
	virtual void Withdraw(double am);
};

class BrassPlus: public ActABC
{
private:
	double owelimit;
	double rate;
	double oweamount;
public:
	//cons
	BrassPlus(const string &n = "None", long acct = -1, double b = 0, double lim = 500, double r = 0.11125);
	BrassPlus(const Brass &b, double lim, double r);
	//*
	void Resetrating(double r) { rate = r; }
	void Resetowe(double am = 0) { oweamount = am; }
	void Resetmax(double lim) { oweamount = lim; }
	//virtual
	virtual void Viewaccount() const;
	virtual void Withdraw(double am);
};
