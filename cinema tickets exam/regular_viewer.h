#pragma once
#include "viewer.h"
class regular_viewer :public viewer
  {
	int count_buy_ticket = 0;
  public:
	void buy_one_ticket();
	void set_cout_ticket(const int t); 
	const int get_count_ticket();
	friend ostream& operator<<(ostream& out,regular_viewer& _view);
	bool operator<(regular_viewer& _view);
	bool operator>(regular_viewer& _view);
	bool operator==(regular_viewer& _view);
	bool operator!=(regular_viewer& _view);
};

 