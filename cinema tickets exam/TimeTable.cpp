#include "TimeTable.h"

void TimeTable::add_watch_table(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int vubir;
		view_hall_colect(out);
		out << "choice Hall: ";
		do
		{
			in >> vubir;
			if (!in) {
				vubir = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (vubir < 1 || vubir > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[vubir-1];

		view_film_colect(out);
		out << "choice film: ";
		do
		{
			in >> vubir;
			if (!in) {
				vubir = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (vubir < 1 || vubir > film_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_f = film_colect[vubir - 1];
		out << "choice free time\n";
		it_h->view_timetable(out);
		tim begin_f;
		out << "\nEnter begin film show\n";
		in >> begin_f;
		if (!it_h->check_free_time(out, begin_f, it_f)) {
			it_h->add_show_film(*it_f,begin_f);
			out << "successfully added movie to table";
		}
	}
}


void TimeTable::wiew_watch_table(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];
		it_h->view_timetable_for_viewer(out);
	}
}

void TimeTable::add_film(istream& in)
{
	film* f = new film();
	in >> *f;
	film_colect.push_back(f);
}

void TimeTable::add_hall(istream& in)
{
	cinema_hall* hall = new cinema_hall();
	int row, col, price;
	do {
	cout << "row: ";
		in >> row;
		if (!in) {
			row = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
	} while (row < 1);
	cin.clear(0);
	cin.ignore(in.rdbuf()->in_avail());
	do {
	cout << "col: ";
		in >> col;
		if (!in) {
			col = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
	} while (col < 1);
	in.clear(0);
	in.ignore(in.rdbuf()->in_avail());
	hall->great_cinema_hall(row,col);
	for (int i = 0; i < row; i++)
	{
	do {
	cout << "price row: "<< i+1 << " ";
		in >> price;
		if (!in) {
			price = -1;
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
		}
	} while (price < 0);
	in.clear(0);
	in.ignore(in.rdbuf()->in_avail());
	hall->enter_price_row_cinema_shem(i,price);
	}
	hall_colect.push_back(hall);
}

void TimeTable::view_film_colect(ostream& out)
{
	if (film_colect.empty())throw exception("film colection is empty");
	int i = 0;
	for_each(film_colect.begin(), film_colect.end(), [&out,&i](film* it) {
		i++;
		out << "\nFilm num: " << i << endl;
		out << *it << endl;
		});
}

void TimeTable::view_hall_colect(ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	int i = 0;
	for_each(hall_colect.begin(), hall_colect.end(), [&out,&i](cinema_hall* it) {
		i++;
		out << "\nHall num: "<< i << "\n" << *it << endl; 
		});
}

void TimeTable::view_film_for_viewer(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		view_film_colect(out);
		out << "choice film: ";
		do
		{
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > film_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_f = film_colect[cho - 1];
		system("cls");
		//out << *it_f;
		int i = 0;
		for_each(hall_colect.begin(), hall_colect.end(), [&it_f,&i,&out](cinema_hall*& it) {
			i++;
			for (auto& it_l : it->list_show) {
				if (*it_l.second._f == it_f) {
					out << "\nHall num: " << i << "\n" << it_l.second << endl;
				}
			}
		});
	}

}

void TimeTable::reserved_place_regular_viewer(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];
		
		regular_viewer _viewer;
		in >> _viewer;
		int i = 0;
		do
		{
			if (it_h->list_show.empty())throw exception("show colection is empty");
			for (auto& it : it_h->list_show) {
				i++;
				out << "\nNum show: " << i << endl << it.second << endl;
			}
			out << "Choise num show: ";
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > i);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int row, col;
		it_h->print_cinema_shem(out);
		do
		{
			out << "\nChoise row: ";
			in >> row;
			if (!in) {
				row = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (row < 1 && row > it_h->get_row()+1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		do
		{
			out << "\nChoise col: ";
			in >> col;
			if (!in) {
				col = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (col < 1 && col > it_h->get_col() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		for (auto& it : it_h->list_show) {
			i++;
			if (i = cho) {
				it_h->reservet_place(row,col,_viewer,*it.second._f);
				out << "place reservet: "<<_viewer.get_name()<<endl;
			}
		}
	
	}
		
}

void TimeTable::reserved_place_viewer(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];

		viewer _viewer;
		in >> _viewer;
		int i = 0;
		do
		{
			if (it_h->list_show.empty())throw exception("show colection is empty");
			for (auto& it : it_h->list_show) {
				i++;
				out << "\nNum show: " << i << endl << it.second << endl;
			}
			out << "Choise num show: ";
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > i);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int row, col;
		it_h->print_cinema_shem(out);
		do
		{
			out << "\nChoise row: ";
			in >> row;
			if (!in) {
				row = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (row < 1 && row > it_h->get_row() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		do
		{
			out << "\nChoise col: ";
			in >> col;
			if (!in) {
				col = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (col < 1 && col > it_h->get_col() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		for (auto& it : it_h->list_show) {
			i++;
			if (i = cho) {
				it_h->reservet_place(row, col, _viewer, *it.second._f);
				out << "place reservet: " << _viewer.get_name() << endl;
			}
		}

	}

}

void TimeTable::buy_place_regular_viewer(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];

		regular_viewer _viewer;
		in >> _viewer;
		int i = 0;
		do
		{
			if(it_h->list_show.empty())throw exception("show colection is empty");
			for (auto& it : it_h->list_show) {
				i++;
				out << "\nNum show: " << i << endl << it.second << endl;
			}
			out << "Choise num show: ";
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > i);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int row, col;
		it_h->print_cinema_shem(out);
		do
		{
			out << "\nChoise row: ";
			in >> row;
			if (!in) {
				row = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (row < 1 && row > it_h->get_row() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		do
		{
			out << "\nChoise col: ";
			in >> col;
			if (!in) {
				col = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (col < 1 && col > it_h->get_col() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int money;
		do
		{
			out << "\nEnter money row: "<< it_h->get_price_row(row)<<endl;
			in >> money;
			if (!in) {
				money = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (money != it_h->get_price_row(row));
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		for (auto& it : it_h->list_show) {
			i++;
			if (i = cho) {
				it_h->pay_place(row, col,money, _viewer, *it.second._f);
				out << "place buy: " << _viewer.get_name() << endl;
			}
		}

	}

}

void TimeTable::buy_place_viewer(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];

		viewer _viewer;
		in >> _viewer;
		int i = 0;
		do
		{
			if (it_h->list_show.empty())throw exception("show colection is empty");
			for (auto& it : it_h->list_show) {
				i++;
				out << "\nNum show: " << i << endl << it.second << endl;
			}
			out << "Choise num show: ";
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > i);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int row, col;
		it_h->print_cinema_shem(out);
		do
		{
			out << "\nChoise row: ";
			in >> row;
			if (!in) {
				row = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (row < 1 && row > it_h->get_row() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		do
		{
			out << "\nChoise col: ";
			in >> col;
			if (!in) {
				col = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (col < 1 && col > it_h->get_col() + 1);
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		int money;
		do
		{
			out << "\nEnter money row: " << it_h->get_price_row(row) << endl;
			in >> money;
			if (!in) {
				money = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (money != it_h->get_price_row(row));
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		for (auto& it : it_h->list_show) {
			i++;
			if (i = cho) {
				it_h->pay_place(row, col, money, _viewer, *it.second._f);
				out << "place buy: " << _viewer.get_name() << endl;
			}
		}

	}
}

void TimeTable::view_reserved_place(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];
		it_h->view_reserved_place(out);
	}
}

void TimeTable::view_buy_place(istream& in, ostream& out)
{
	if (hall_colect.empty())throw exception("hall colection is empty");
	else if (film_colect.empty())throw exception("film colection is empty");
	else {
		int cho;
		out << "choice Hall";
		do
		{
			view_hall_colect(out);
			in >> cho;
			if (!in) {
				cho = -1;
				in.clear(0);
				in.ignore(in.rdbuf()->in_avail());
			}
		} while (cho < 1 || cho > hall_colect.size());
		in.clear(0);
		in.ignore(in.rdbuf()->in_avail());
		auto it_h = hall_colect[cho - 1];
		it_h->view_purchased_place(out);
	}
}

void TimeTable::view_ratin_regular_viever(ostream& out)
{
	vector<regular_viewer*> rating;
	regular_viewer* p_reg_view;
	for (auto it_h : hall_colect) {
		for (auto it_r_v : it_h->view_list) {
			p_reg_view = (regular_viewer*)it_r_v;
			if (p_reg_view->get_count_ticket() >= 0) {
				if (rating.empty()) {
					regular_viewer* new_reg_view = new regular_viewer();
					new_reg_view->set_name(p_reg_view->get_name());
					new_reg_view->set_age(p_reg_view->get_age());
					rating.push_back(new_reg_view);
				}
				for (auto*& it_r : rating) {
					if (*it_r != *p_reg_view) {
						regular_viewer* new_reg_view = new regular_viewer();
						new_reg_view->set_name(p_reg_view->get_name());
						new_reg_view->set_age(p_reg_view->get_age());
						rating.push_back(new_reg_view);
					}
				}
			}
		}
	}
	for (auto it_h : hall_colect) {
		for (auto it_r_v : it_h->view_list) {
			p_reg_view = (regular_viewer*)it_r_v;
			if (p_reg_view->get_count_ticket() >= 0) {
				for (auto* it_r : rating) {
					if (*it_r == *p_reg_view) {
						it_r->set_cout_ticket(it_r->get_count_ticket() + p_reg_view->get_count_ticket());
					}
				}
			}
		}
	}
	for (auto *it : rating)
		out << *it << endl;
}
