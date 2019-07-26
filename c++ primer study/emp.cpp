#include "emp.h"

using std::cout;
using std::cin;
using std::endl;
//abstr_emp::
abstr_emp::abstr_emp()
{
	fname = "first";
	lname = "second";
	job = "None";
}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, const std::string & j) :fname(fn), lname(ln), job(j)
{
	;
}

abstr_emp::~abstr_emp()
{
	;
}
void abstr_emp::ShowAll() const
{
	cout << fname << ", " << lname << " Job: " << job << endl;
}
void abstr_emp::SetAll()
{
	cout << "Please enter the first name: ";
	std::getline(cin, fname);
	cout << "Please enter the second name: ";
	std::getline(cin, lname);
	cout << "Please enter the job: ";
	std::getline(cin, job);
}
std::ostream & operator<<(std::ostream &os, const abstr_emp & e)
{
	os << e.fname << ", " << e.lname << " Job: " << e.job << endl;
	return os;
}

//employee::
employee::employee()
{
	;
}
employee::employee(const std::string & fn, const std::string & ln, const std::string & j) :abstr_emp(fn, ln, j)
{
	;
}
void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

//manager::
manager::manager()
{
	inchargeof = 0;
}
manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico): abstr_emp(fn, ln, j)
{
	inchargeof = ico;
}
manager::manager(const abstr_emp &e, int ico) : abstr_emp(e)
{
	inchargeof = ico;
}
manager::manager(const manager &m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}
void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << inchargeof << endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please enter the inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

//fink::
fink::fink()
{
	reportsto = "null";
}
fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) :abstr_emp(fn, ln, j)
{
	reportsto = rpo;
}
fink::fink(const abstr_emp &e, const std::string & rpo) : abstr_emp(e)
{
	reportsto = rpo;
}
fink::fink(const fink &e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}
void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please enter reportsro: ";
	std::getline(cin, reportsto);
}

//highfink::
highfink::highfink()
{
	InChargeOf() = 0;
	ReportsTo() = "null";
}
highfink::highfink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico) : abstr_emp(fn, ln, j)
{
	InChargeOf() = ico;
	ReportsTo() = rpo;
}
highfink::highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e)
{
	InChargeOf() = ico;
	ReportsTo() = rpo;
}
highfink::highfink(const fink &f, int ico) : abstr_emp(f), fink(f)
{
	InChargeOf() = ico;
}
highfink::highfink(const manager &m, const std::string &rpo) : abstr_emp(m), manager(m)
{
	ReportsTo() = rpo;
}
highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h)
{
	;
}
void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << ReportsTo() << endl;
	cout << "Inchargeof: " << InChargeOf() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Please enter reportsro: ";
	std::getline(cin, ReportsTo());
	cout << "Please enter the inchargeof: ";
	cin >> InChargeOf();
	cin.get();
}