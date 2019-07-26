#include "Worker.h"
using std::cout;
using std::cin;
using std::endl;

//protected
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Empoyee ID: " << id << endl;
	}
void Worker::Get()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Entor worker's ID: ";
	cin >> id;
	while (cin.get() != '\n');
	}
Worker::~Worker() { ; }
//*



//Waiter
//protected
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n');
}
//*
void Waiter::Set()
{
	Worker::Get();
	Get();
}
void Waiter::Show()
{
	cout << "Category: Waiter\n";
	Worker::Data();
	Data();
}
//Singer
//protected
void Singer::Data() const
{
	cout << "Vocal range: " << vp[voice] << endl;
}
void Singer::Get()
{
	cout << "Enter number for singer's vocal range: \n";
	int i = 0;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << vp[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n');
}
//static data
const char* Singer::vp[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };
void Singer::Set()
{
	Worker::Get();
	Get();
}
void Singer::Show()
{
	cout << "Category: Singer\n";
	Worker::Data();
	Data();
}

//SingerWaiter
//protected
void SingerWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}
void SingerWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}
//*
void SingerWaiter::Set()
{
	Worker::Get();
	Get();
}
void SingerWaiter::Show()
{
	cout << "Category: SingerWaiter\n";
	Worker::Data();
	Data();
}