#include "cinema_hall.h"

cinema_hall::~cinema_hall()
{
	for (int i = 0; i < row; i++)
	{
		delete[]*(cinema_shem + i);
	}
	delete cinema_shem;
	delete row_price;
}

bool cinema_hall::check_free_time(ostream& out, tim& _time, film*& _film)
{

	tim work_begin(0, 0, 0);
	tim work_end(24, 0, 0);
	for (auto& it : list_show) {

		if (_time >= it.second.t_begin && _time <= it.second.t_end || (_time + _film->film_time) > work_end) {
			
			out << "Show time is bussy!!!!!!!!!!!!!!";
			return true;
			
		}
	}
	return false;


}

void cinema_hall::add_show_film(film& _film, tim& _begin_show)
{
	show_movie* movie = new show_movie();
	movie->_f = &_film;
	movie->t_begin = _begin_show;
	movie->t_end = _begin_show + _film.film_time;
	long long int key = _begin_show.to_sec();
	list_show.insert({key,*movie});
	
}

void cinema_hall::view_timetable(ostream& out)
{
	tim work_begin(0,0,0);
	tim work_end(24,0,0);
	out << "free time hall from: " << work_begin << " ";
	for (auto it_t = work_begin; it_t < work_end; it_t++)
	{
		//out << it_t << endl;
		for (auto& it : list_show) {
			
			if(it_t.to_sec() == it.first){
				out << "to: " << it.second.t_begin<<" ";
				out << endl << it.second;
				out << "free time hall from: " << it.second.t_end << " ";
			}
			
		}

	}
	out << "to: " << work_end << endl;
	
}

void cinema_hall::view_timetable_for_viewer(ostream& out)
{
		for (auto& it : list_show) 
				out << it.second<<endl;
}

void cinema_hall::great_cinema_hall(const int _row, const int _col)
{
	//if (_num_hall < 0)throw exception("wrong num hall");
	//else num_hall = _num_hall;
	if (_row < 0)throw exception("wrong row < 0");
	else row = _row;
	if (col < 0)throw exception("wrong col < 0"); 
	else col = _col;
	
	
	cinema_shem = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(cinema_shem + i) = new int[col];
	}

for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)*(*(cinema_shem + i) + j) = 0;
		
	row_price = new int[row];
	for (int i = 0; i < row; i++)
	{
		*(row_price + i) = 0;
	}
}

void cinema_hall::print_cinema_shem(ostream& out)
{
	//out << "Num hall: " << num_hall << endl;
	out << "place: ";
	for (int i = 0; i < col; i++)out << setw(2) << i+1;
	out << endl;
	for (int i = 0; i < row; i++)
	{
		out << "row(" << i+1 << ") ";
		for (int j = 0; j < col; j++)
		{
			out << setw(2) << cinema_shem[i][j];
		}
		out << "  price row: " << row_price[i]<<endl;
	}
	out << "the amoung of seats sold: " <<bank_account<<endl<<endl;
}

void cinema_hall::print_cinema_place_client(ostream& out, const int _row, const int _col,const int _type_place)
{
	//out << "\nNum hall: " << num_hall << endl;
	out << "\nplace: ";
	for (int i = 0; i < col; i++)out << setw(2) << i + 1;
	out << endl;
	for (int i = 0; i < row; i++)
	{
		out << "row(" << i + 1 << ") ";
		for (int j = 0; j < col; j++)
		{
			if (i == _row && j == _col)out << setw(2) << _type_place;
			else out << setw(2) << 0;
		}
		out << endl;
	}
}

void cinema_hall::enter_price_row_cinema_shem(const int _row, const int _price)
{
	if (_row < 0 && _row > row)throw exception("out range row");
	else {
		row_price[_row] = _price;
	}
}

void cinema_hall::pay_place(const int _row, const int _col, double _money,const viewer& _view,const film& _film)
{
	viewer *owner_place = new viewer();
	if(_row < 0 && _row > row)throw exception("out range row");
	else if(_col < 0 && _col > col)throw exception("out range col");
	else {
			*owner_place = _view;
			film f;
			f = _film;
			if (owner_place->get_age() >= f.get_eage_cat() && _money >= row_price[_row - 1] && this->cinema_shem[_row - 1][_col - 1] != 2 && this->cinema_shem[_row - 1][_col - 1] != 1) {
				_money -= row_price[_row - 1];
				owner_place->set_place(_row - 1, _col - 1);
				owner_place->v_film = f;
				this->cinema_shem[_row - 1][_col - 1] = 2;
				this->bank_account += row_price[_row - 1];
				if (typeid(_view) == typeid(viewer)) {
					view_list.push_back(owner_place);
				}
				else {
					regular_viewer* p_reg_view;
					p_reg_view = (regular_viewer*)owner_place;
					p_reg_view->buy_one_ticket();
					view_list.push_back(p_reg_view);
				}
			}
			else if (owner_place->get_age() >= f.get_eage_cat())throw exception("small age");
			else if (_money < row_price[_row - 1])throw exception("no money");
			else if (this->cinema_shem[_row - 1][_col - 1] == 2)throw exception("this place is bought");
			else if (this->cinema_shem[_row - 1][_col - 1] == 1)throw exception("this place is reservet");
	}
	
} 

void cinema_hall::pay_place(const int _row, const int _col, double _money, const regular_viewer& _view, const film& _film)
{
	regular_viewer* owner_place = new regular_viewer();
	if (_row < 0 && _row > row)throw exception("out range row");
	else if (_col < 0 && _col > col)throw exception("out range col");
	else {
		*owner_place = _view;
		film f;
		f = _film;
		if (owner_place->get_age() >= f.get_eage_cat() && _money >= row_price[_row - 1] && this->cinema_shem[_row - 1][_col - 1] != 2 && this->cinema_shem[_row - 1][_col - 1] != 1) {
			_money -= row_price[_row - 1];
			owner_place->set_place(_row - 1, _col - 1);
			owner_place->v_film = f;
			this->cinema_shem[_row - 1][_col - 1] = 2;
			this->bank_account += row_price[_row - 1];
			owner_place->buy_one_ticket();
			view_list.push_back(owner_place);
		}
		else if (owner_place->get_age() <= f.get_eage_cat())throw exception("small age"); 
		else if (_money < row_price[_row - 1])throw exception("no money");
		else if (this->cinema_shem[_row - 1][_col - 1] == 2)throw exception("this place is bought");
		else if (this->cinema_shem[_row - 1][_col - 1] == 1)throw exception("this place is reservet");
	}

}



void cinema_hall::reservet_place(const int _row, const int _col, const viewer& _view, const film& _film)
{
	viewer* owner_place = new viewer();
	if (_row < 0 && _row > row)throw exception("out range row");
	else if (_col < 0 && _col > col)throw exception("out range col");
	else {
		*owner_place = _view;
		film f;
		f = _film;
		if (owner_place->get_age() >= f.get_eage_cat()  && this->cinema_shem[_row - 1][_col - 1] != 2 && this->cinema_shem[_row - 1][_col - 1] != 1) {
			owner_place->set_place(_row - 1, _col - 1);
			owner_place->v_film = f;
			this->cinema_shem[_row - 1][_col - 1] = 1;
			reserv_list.push_back(owner_place);
		}
		else if (owner_place->get_age() >= f.get_eage_cat())throw exception("small age");
		else if (this->cinema_shem[_row - 1][_col - 1] == 2)throw exception("this place is bought");
		else if (this->cinema_shem[_row - 1][_col - 1] == 1)throw exception("this place is reservet");
	}
}

void cinema_hall::reservet_place(const int _row, const int _col, const regular_viewer& _view, const film& _film)
{
	regular_viewer* owner_place = new regular_viewer();
	if (_row < 0 && _row > row)throw exception("out range row");
	else if (_col < 0 && _col > col)throw exception("out range col");
	else {
		*owner_place = _view;
		film f;
		f = _film;
		if (owner_place->get_age() >= f.get_eage_cat() && this->cinema_shem[_row - 1][_col - 1] != 2 && this->cinema_shem[_row - 1][_col - 1] != 1) {
			owner_place->set_place(_row - 1, _col - 1);
			owner_place->v_film = f;
			this->cinema_shem[_row - 1][_col - 1] = 1;
			reserv_list.push_back(owner_place);
		}
		else if (owner_place->get_age() >= f.get_eage_cat())throw exception("small age");
		else if (this->cinema_shem[_row - 1][_col - 1] == 2)throw exception("this place is bought");
		else if (this->cinema_shem[_row - 1][_col - 1] == 1)throw exception("this place is reservet");
	}
}

void cinema_hall::view_purchased_place(ostream& out)
{
	if (view_list.empty())throw exception("list buy empty");
	for_each(view_list.begin(), view_list.end(), [&out,this](auto*& it)
	{
		out << *it;
		regular_viewer* p_reg_view;
		p_reg_view = (regular_viewer*)it;
		if (p_reg_view->get_count_ticket() >= 0) {
			out << "\ncount buy ticket: " << p_reg_view->get_count_ticket() << endl;
		}
		else out << endl;
		print_cinema_place_client(out,it->get_row(),it->get_cow(),2);
		
	});
	
}


void cinema_hall::view_reserved_place(ostream& out)
{
	if (reserv_list.empty())throw exception("reservet list empty");
	for_each(reserv_list.begin(), reserv_list.end(), [&out, this](viewer*& it)
		{
			out << *it;
			this->print_cinema_place_client(out, it->get_row(), it->get_cow(), 1);
		});
}

const int cinema_hall::get_row()
{
	return row;
}

const int cinema_hall::get_col()
{
	return col;
}

const int cinema_hall::get_price_row(int _row)
{
	return this->row_price[_row-1];
}

//istream& operator>>(istream& in, cinema_hall& _hall)
//{
//	for (int i = 0; i < _hall.row; i++)
//	{
//		in >> _hall.row_price[i];
//	}
//	return in;
//}

ostream& operator<<(ostream& out, cinema_hall& _hall)
{
	_hall.print_cinema_shem(out);
	return out;
}
