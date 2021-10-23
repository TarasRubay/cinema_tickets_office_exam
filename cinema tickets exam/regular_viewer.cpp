#include "regular_viewer.h"

void regular_viewer::buy_one_ticket()
{
	count_buy_ticket++;
}

void regular_viewer::set_cout_ticket(const int t)
{
	count_buy_ticket = t;
}

const int regular_viewer::get_count_ticket()
{
	return count_buy_ticket;
} 

bool regular_viewer::operator<(regular_viewer& _view)
{
	if (this->count_buy_ticket < _view.count_buy_ticket)return true;
	else return false;
}

bool regular_viewer::operator>(regular_viewer& _view)
{
	return !this->operator<(_view);
}

bool regular_viewer::operator==(regular_viewer& _view)
{
	if(this->get_name() == _view.get_name() && this->get_age() == _view.get_age())return true;
	else return false;
}

bool regular_viewer::operator!=(regular_viewer& _view)
{
	return !this->operator==(_view);
}

ostream& operator<<(ostream& out,regular_viewer& _view)
{
	
	out <<"name: "<< _view.get_name() << "; age: " <<_view.get_age() <<"; count buy ticket: "<< _view.get_count_ticket();
	return out;
}
