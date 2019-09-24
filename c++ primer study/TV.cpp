#include "TV.h"
#include<iostream>
using std::cout;
using std::endl;
bool Tv::volup()
{
	if (volumn == MAXVAL)
		return false;
	else volumn++;
	return true;
}
bool Tv::voldown()
{
	if (volumn == 1)
		return false;
	else volumn--;
	return false;
}
void Tv::chanup()
{
	if (channel == maxchannel)
		channel = 1;
	else channel++;
}
void Tv::chandown()
{
	if (channel == 1)
		channel = maxchannel;
	else channel--;
}
void Tv::setting() const
{
	cout << "TV is " << (state == ON ? "On" : "Off") << endl;
	if (state == ON)
	{
		cout << "Volumn setting: " << volumn << endl;
		cout << "Channel setting: " << channel << endl;
		cout << "Input = " << (input == DVD ? "DVD" : "TV") << endl;
		cout << "Mode = " << (mode == ANTENNA ? "Antenna" : "Cable") << endl;
	}
}

void Remote::set_channel(Tv &t, int c)
{
	if (c<1 || c>t.maxchannel);
	else
		t.channel = c;
		
}
