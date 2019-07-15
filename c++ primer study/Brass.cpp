#include "Brass.h"
#include<iostream>
using std::cout;
using std::endl;
using std::ios_base;


//protected
ActABC::formatting ActABC::Setformat() const
{
	formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void ActABC::Restore(const formatting &f) const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}
//cons
ActABC::ActABC(const string &n, long acct, double b)
{
	name = n;
	accountnum = acct;
	balance = b;
}
void ActABC::Deposit(double b)
{
	if (b < 0)
		cout << "negative deposit not allowed; deposit is cancelled.\n";
	else
		balance += b;
}
//Brass methods
//cons
Brass::Brass(const string &n , long acct , double b):ActABC(n,acct,b)
{
	;
}

//virtual
void Brass::Viewaccount() const
{
	formatting f = Setformat();
	cout << "Name: " << Accountname() << endl;
	cout << "Account: " << Accountnumber() << endl;
	cout << "Balance: $" << Balance() << endl;
	Restore(f);
}
void Brass::Withdraw(double am)
{
	formatting f = Setformat();
	if (am < 0)
		cout << "Withdraw amount must be positive; withdrawal canceled.\n";
	else if (am <= Balance())
		ActABC::Withdraw(am);
	else
		cout << "Withdrawal amount of $" << am << " exceeds your balance.\nWithdraw canceled.\n";
	Restore(f);
}

//BrassPlus methods
//cons
BrassPlus::BrassPlus(const string &n, long acct, double b, double lim, double r): ActABC(n,acct,b)
{
	owelimit = lim;
	rate = r;
	oweamount = 0;
}
BrassPlus::BrassPlus(const Brass &b, double lim, double r) : ActABC(b)
{
	owelimit = lim;
	rate = r;
	oweamount = 0;
}

//virtual
void BrassPlus::Viewaccount() const
{
	formatting f = Setformat();
	cout << "Name: " << Accountname() << endl;
	cout << "Account: " << Accountnumber() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Max loan: $" << owelimit << endl;
	cout << "Owed to Bank: $" << oweamount << endl;
	cout.precision(3);
	cout << "Loan rate: " << 100 * rate << " %\n";
	Restore(f);
}
void BrassPlus::Withdraw(double am)
{
	formatting f = Setformat();
	if (am < 0)
		cout << "Withdraw amount must be positive; withdrawal canceled.\n";
	else if (am <= Balance())
		ActABC::Withdraw(am);
	else if (am <= Balance() + owelimit - oweamount)
	{
		double advance = am - Balance();
		cout << "Bank advance: $" << advance << endl;
		cout << "Finace charge: $" << advance * rate << endl;
		oweamount += advance * (1 + rate);
		ActABC::Withdraw(Balance());
	}
	else
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	Restore(f);
}
