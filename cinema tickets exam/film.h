#pragma once
#include "includet.h"
class film
{
	string name;
	string info_film;
	int eage_category; 
protected:
public:
	void set_name(const string _name);
	void set_info_film(const string _info_film);
	void set_eage_category(const int _eage);
	tim film_time;
	const string get_name();
	const string get_info();
	const int get_eage_cat();
	friend istream& operator>>(istream& in,film& _film);
	friend ostream& operator<<(ostream& out,const film& _film);
	bool operator==(film*& _film);
	void view_list_film();
};

