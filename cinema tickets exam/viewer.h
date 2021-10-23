#pragma once
#include "includet.h" 
#include "film.h"
class viewer
{
	string name;
	int age;
	int row;
	int col;
public:
	film v_film;
	const int get_row();
	const int get_cow();
	const string get_name();
	const int get_age();
	void set_name(const string& _name);
	void set_age(const int& age); 
	void set_place(const int _row, const int _col);
	friend ostream& operator<<(ostream& out,const viewer& _view);
	friend istream& operator>>(istream& in,viewer& _view);

};

