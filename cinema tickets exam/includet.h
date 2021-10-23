#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> 
#include <iomanip>
#include <windows.h>
using namespace std;
class tim {
	int hour = 0;
	int min = 0;
	long long int sec = 0;
public:
	tim() = default;
	tim(const int _hour, const int _min, const int _sec);
	bool operator<=(tim& _time) {
		if (this->to_sec() <= _time.to_sec())return true;
		else return false;
	}
	bool operator>=(tim& _time) {
		return !this->operator<=(_time);
	}
	bool operator!=(tim& _time) {
		return !this->operator==(_time);
	}
	bool operator>(tim& _time) {
		return !this->operator<(_time);
	}
	bool operator<(tim& _time) {
		if (this->to_sec() < _time.to_sec())return true;
		else return false;
	}
	bool operator==(tim& _time) {
		if (this->to_sec() == _time.to_sec())return true;
		else return false;
	}
	tim operator+=(tim& _time) {
		long long int sec = this->to_sec();
		sec += _time.to_sec();
		this->from_sec(sec);
		return *this; 
	}
	tim operator+(tim& _time) {
		tim t;
		long long int sec = this->to_sec();
		sec += _time.to_sec();
		t.from_sec(sec);
		return t;
	}
	tim operator++(int _val) {
		tim t(*this);
		this->from_sec(this->to_sec() + 1);
		return t;
	}
	const long long int to_sec();
	void from_sec(const long long int _sec);
	friend istream& operator>>(istream& in, tim& _tim)
	{
		do {
		cout << "hour: ";
		in >> _tim.hour;
			if (!in) {
				_tim.hour = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (_tim.hour < 0);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		
		do {
		cout << "minutes: ";
		in >> _tim.min;
		if (!in) {
			_tim.min = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
		} while (_tim.min < 0 || _tim.min > 59);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());

		do {
		cout << "secons: ";
		in >> _tim.sec;
		if (!in) {
			_tim.sec = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
		} while (_tim.sec < 0 || _tim.sec > 59);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		
		return in;
	}
	friend ostream& operator<<(ostream& out, const tim& _tim) {
		out << _tim.hour << ":" << _tim.min << ":" << _tim.sec;
		return out;
	}
};




inline tim::tim(const int _hour, const int _min, const int _sec)
{
	this->hour = _hour;
	this->min = _min;
	this->sec = _sec;
}

inline const long long int tim::to_sec()
{
	return ((this->hour * 3600) + this->min * 60) + this->sec;
}

inline void tim::from_sec(const long long int _sec)
{
	tim t;
	t.sec = _sec;
	while (t.sec >= 3600) {
		t.sec -= 3600;
		t.hour++;
	}
	while (t.sec >= 60) {
		t.sec -= 60;
		t.min++;
	}
	*this = t;
}
