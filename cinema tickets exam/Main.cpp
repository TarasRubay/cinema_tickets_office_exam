#include "Office.h"
int main() {
	Office Log;
	int menu = 100, MaxMenu = 3;
	int Switc = menu;
	do
	{
		switch (Switc)
		{
		case 100:
			do
			{
				
				cout << "\n1 - employee\n";
				cout << "2 - viewer regular \n";
				cout << "3 - viewer\n";
				cout << "0 - exit\n";
				cin >> Switc;
				system("cls");
				if (!cin) {
					Switc = -1;
					cin.clear(0);
					cin.ignore(cin.rdbuf()->in_avail());
				}
			} while (Switc < 0 || Switc > MaxMenu);
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			break;
		case 1:
			Log.Emloyee(cin, cout);
			Switc = menu;
			break;
		case 2:
			Log.RegularV(cin, cout);
			Switc = menu;
			break;
		case 3:
			Log.Viever(cin, cout);
			Switc = menu;
			break;
		default:
			break;
		}

	} while (Switc != 0);
	return 0;
}

