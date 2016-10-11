#include<iostream>
#include<string>

using namespace std;
void menu();
void create()
{
	int value;
	cout << "~~~~CREATE~~~~\nWhere would you like to go?\n1 - Order\n2 - Customer\n3 - Sales Associate\n4 - Robot Model\n5 - Robot Component\n6 - Main Menu\n";

	cin >> value;

	if (value == 6)
		menu();
}

void menu()
{
	int value;
	cout << "~~~~Main Menu~~~~\nWhere would you like to go?\n1 - Create\n2 - Report\n3 - Save\n0 - Quit\n";

	cin >> value;

	if (value == 1)
		create();
	return;
}
