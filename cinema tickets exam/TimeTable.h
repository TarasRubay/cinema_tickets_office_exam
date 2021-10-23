#pragma once
#include "includet.h"
#include "cinema_hall.h"
#include "film.h"

class TimeTable
{
	vector <film*> film_colect;
	vector <cinema_hall*> hall_colect;
public:
	void add_watch_table(istream& in,ostream& out);
	void wiew_watch_table(istream& in,ostream& out);
	void add_film(istream& in);
	void add_hall(istream& in);
	void view_film_colect(ostream& out);
	void view_hall_colect(ostream& out);
	void view_film_for_viewer(istream& in, ostream& out);
	void reserved_place_regular_viewer(istream& in, ostream& out);
	void reserved_place_viewer(istream& in, ostream& out);
	void buy_place_regular_viewer(istream& in, ostream& out);
	void buy_place_viewer(istream& in, ostream& out);
	void view_reserved_place(istream& in, ostream& out);
	void view_buy_place(istream& in, ostream& out);
	void view_ratin_regular_viever(ostream& out);
};  