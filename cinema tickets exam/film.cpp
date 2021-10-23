#include "film.h"


bool film::operator==(film*& _film)
{
	if (this->name == _film->name && this->info_film == _film->info_film && this->eage_category == _film->eage_category && this->film_time == _film->film_time)return true;
	else return false;
}

void film::view_list_film()
{
		cout << "film name: " << name << endl;
		cout << "film info: " << name << endl;
		cout << "film time: " << film_time << endl;
		cout << "age category: " << eage_category << endl;
}

void film::set_name(const string _name)
{
	name = _name;
}

void film::set_info_film(const string _info_film)
{
	info_film = _info_film;
}

void film::set_eage_category(const int _eage)
{	
	if (_eage < 0)throw exception("eage must be > 0");
	else eage_category = _eage;
}





const string film::get_name()
{
	return name;
}

const string film::get_info()
{
	return info_film;
}

const int film::get_eage_cat()
{
	return eage_category;
}

istream& operator>>(istream& in, film& _film)
{
	cout << "name: ";
	getline(in, _film.name);
	cout << "info: ";
	getline(in, _film.info_film);
	cout << "time: ";
	in >> _film.film_time;
	cout << "age category: ";
	do{
	in >> _film.eage_category;
	if (!in) {
		_film.eage_category = -1;
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		}
	} while (_film.eage_category < 0);
in.clear(0);
in.ignore(in.rdbuf()->in_avail());
	
	return in;
}

ostream& operator<<(ostream& out,const film& _film)
{
	out << "film name: " << _film.name << endl;
	out << "film info: " << _film.info_film << endl;
	out << "film time: " << _film.film_time << endl;
	out << "age category: " << _film.eage_category; 
	return out;
}
