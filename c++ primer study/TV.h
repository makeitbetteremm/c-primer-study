#pragma once

class Tv;
class Remote
{
private:
	int mode;
	int model;
	enum { OFF, ON };
	enum { MINVAL, MAXVAL = 20 };
	enum { ANTENNA, CABLE };
	enum { DVD, TV };
	enum { chang, hudong };
public:
	friend class Tv;
	Remote(int m = TV, int n = chang) :mode(m), model(n) { ; }
	bool volup(Tv &t);
	bool voldowm(Tv & t);
	void onoff(Tv &t);
	void chanup(Tv &t);
	void chandown(Tv &t);
	void set_mode(Tv &t);
	void set_input(Tv &t);
	void set_channel(Tv &t, int c);
	int Model() const { return model; }
};


class Tv
{
private:
	int state;
	int volumn;
	int channel;
	int mode;
	int input;
	int maxchannel;
protected:
	enum {	OFF, ON };
	enum { MINVAL, MAXVAL = 20 };
	enum { ANTENNA, CABLE };
	enum { DVD, TV };
public:
	friend class Remote;
	Tv(int s = OFF, int mc = 120) :state(s), volumn(5), channel(2), mode(CABLE), input(TV), maxchannel(mc) { ; }
	void onoff() { state = (state == ON) ? OFF : ON; }
	bool ison() {return state == ON;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == ANTENNA) ? CABLE : ANTENNA; }
	void set_input() { input = (input == DVD) ? TV : DVD; }
	void setting() const;
	bool set_model(Remote & r) 
	{ 
		if (state == ON) { r.model = (r.model == r.hudong) ? r.chang : r.hudong; return true; }
		else
			return false;
	}
};

inline bool Remote::volup(Tv &t) { return t.volup(); }
inline bool Remote::voldowm(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv &t) { t.onoff(); }
inline void Remote::chanup(Tv &t) { t.chanup(); }
inline void Remote::chandown(Tv &t) { t.chandown(); }
inline void Remote::set_mode(Tv &t) { t.set_mode(); }
inline void Remote::set_input(Tv &t) { t.set_input(); }