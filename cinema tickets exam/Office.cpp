#include "Office.h"

void Office::Emloyee(istream& in, ostream& out) 
{
	int Menu = 100, MaxMenu = 9;
	int Switc = Menu;
	do
	{
		switch (Switc)
		{
		case 100:
			do
			{
				out << "\n1 - great cinema hall\n";
				out << "2 - view cinema hall\n";
				out << "3 - great movie\n";
				out << "4 - view movie\n";
				out << "5 - add show movie\n";
				out << "6 - view show movie\n";
				out << "7 - view reserved place\n";
				out << "8 - view purchased place\n";
				out << "9 - view rating regular viewer\n";
				out << "0 - exit\n";
				in >> Switc;
				system("cls");
				if (!in) {
					Switc = -1;
					in.clear(0);
					in.ignore(in.rdbuf()->in_avail());
				}
			} while (Switc < 0 || Switc > MaxMenu);
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
			break;
		case 1:
			out << "\ngreat cinema hall\n";
			try
			{
				Table.add_hall(in);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 2:
			try
			{
				Table.view_hall_colect(out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 3:
			out << "\ngreat movie\n";
			try
			{
				Table.add_film(in);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 4:
			try
			{
				Table.view_film_colect(out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 5:
			try
			{
				Table.add_watch_table(in,out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 6:
			try
			{
				Table.wiew_watch_table(in,out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 7:
			try
			{
				Table.view_reserved_place(in,out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 8:
			try
			{
				Table.view_buy_place(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		case 9:
			try
			{
				Table.view_ratin_regular_viever(out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Switc = Menu;
			break;
		default:
			break;
		}

	} while (Switc != 0);
}

void Office::RegularV(istream& in, ostream& out)
{
	int Menu = 100, max_menu = 3;
	int Swich = Menu;
	do
	{
		switch (Swich)
		{
		case 100:
			do
			{
				out << "\nregular_viewer\n";
				out << "\n1 - view film\n";
				out << "2 - reserved place\n";
				out << "3 - buy place\n";
				out << "0 - exit\n";
				in >> Swich;
				system("cls");
				if (!in) {
					Swich = -1;
					in.clear(0);
					in.ignore(in.rdbuf()->in_avail());
				}
			} while (Swich < 0 || Swich > max_menu);
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
			break;
		case 1:
			
			try
			{
				Table.view_film_for_viewer(in,out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 2:
			try
			{
				Table.reserved_place_regular_viewer(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 3:
			
			try
			{
				Table.buy_place_regular_viewer(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 4:
			try
			{
				
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 5:
			try
			{
				
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 6:
			try
			{
				
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 7:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		case 8:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			Swich = Menu;
			break;
		default:
			break;
		}

	} while (Swich != 0);
}

void Office::Viever(istream& in, ostream& out)
{
	int menu = 100, max_menu = 3;
	int switch_on = menu;
	do
	{
		switch (switch_on)
		{
		case 100:
			do
			{
				out << "\nviewer\n";
				out << "\n1 - view film\n";
				out << "2 - reserved place\n";
				out << "3 - buy place\n";
				out << "0 - exit\n";
				in >> switch_on;
				system("cls");
				if (!in) {
					switch_on = -1;
					in.clear(0);
					in.ignore(in.rdbuf()->in_avail());
				}
			} while (switch_on < 0 || switch_on > max_menu);
			in.clear(0);
			in.ignore(in.rdbuf()->in_avail());
			break;
		case 1:

			try
			{
				Table.view_film_for_viewer(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 2:
			try
			{
				Table.reserved_place_viewer(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 3:

			try
			{
				Table.buy_place_viewer(in, out);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 4:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 5:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 6:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 7:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		case 8:
			try
			{

			}
			catch (exception& e)
			{
				cout << e.what();
			}
			switch_on = menu;
			break;
		default:
			break;
		}

	} while (switch_on != 0);
}
