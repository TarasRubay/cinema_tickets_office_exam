#include "viewer.h"


void viewer::set_place(const int _row, const int _col)
{
	if (_row < 0)throw exception("out of range");
	else row = _row;
	if (_col < 0)throw exception("out of range");
	else col = _col;
}

const int viewer::get_row()
{
	return row;
}

const int viewer::get_cow()
{
	return col;
}

const string viewer::get_name()
{
	return name;
}

const int viewer::get_age()
{
	return age;
}


void viewer::set_name(const string& _name)
{
	name = _name;
}

void viewer::set_age(const int& _age)
{ 
	age = _age;
}

 
ostream& operator<<(ostream& out,const viewer& _view)
{
	out << "\nname: " <<_view.name << endl;
	out << "age " <<_view.age << endl;
	out << _view.v_film;
	
	return out;
}

istream& operator>>(istream& in,viewer& _view)
{
	cout << "enter you name: ";
	getline(in,_view.name);
	do
	{
	cout << "enter you age: ";
		in >> _view.age;
		if (!in) {
			_view.age = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
	} while (_view.age < 0);
	in.clear(0);
	in.ignore(in.rdbuf()->in_avail());
	return in;
}
