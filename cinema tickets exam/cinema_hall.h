#pragma once
#include "includet.h"
#include "viewer.h"
#include "regular_viewer.h"
class cinema_hall
{
	struct show_movie { 
		film* _f;
		tim t_begin;
		tim t_end;
	
		friend ostream& operator<<(ostream& out, show_movie& _movie) {
		out << *_movie._f << endl;
		out << "begin show film: " << _movie.t_begin<<endl;
		out << "end show film: " << _movie.t_end << endl;
		return out;
		}
	   
	};
	int num_hall;
	int row = 0;
	int col = 0;
	int** cinema_shem;
	int* row_price;
	double bank_account = 0;
public:
	map<long long int,show_movie> list_show;
	vector <viewer*> view_list;
	vector <viewer*> reserv_list;
	cinema_hall() = default;
	~cinema_hall(); 
	bool check_free_time(ostream& out, tim& _time, film*& _film);
	void add_show_film(film& _film,tim& _begin_show);
	void view_timetable(ostream& out);
	void view_timetable_for_viewer(ostream& out);
	void great_cinema_hall(const int _row,const int _col);
	void print_cinema_shem(ostream& out);
	void print_cinema_place_client(ostream& out, const int _row, const int _col, const int _type_place);
	void enter_price_row_cinema_shem(const int _row, const int _price);
	void pay_place(const int _row, const int _col,double _money,const viewer& _view,const film& _film);
	void pay_place(const int _row, const int _col,double _money,const regular_viewer& _view,const film& _film);
	void reservet_place(const int _row, const int _col, const viewer& _view, const film& _film);
	void reservet_place(const int _row, const int _col, const regular_viewer& _view, const film& _film);
	void view_purchased_place(ostream& out);
	void view_reserved_place(ostream& out);
	friend ostream& operator<<(ostream& out,cinema_hall& _hall);
	const int get_row();
	const int get_col();
	const int get_price_row(int _row);
	//friend istream& operator>>(istream& in,cinema_hall& _hall);
};

