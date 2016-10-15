#include"View.h"
#include<iostream>
#include<string>

using namespace std;

void View::show_menu() {
	cout << endl << endl;
	cout << "==========" << endl;
	cout << "Main Menu" << endl;
	cout << "==========" << endl;
	cout << endl;
	cout << "Product Manager" << endl;
	cout << "---------------" << endl;
	cout << "(1) Product Manager" << endl;
	cout << "(2) Beloved Customer" << endl;
}

/*void View::show_PM_menu() {
        cout << endl << endl;
        cout << "====================" << endl;
        cout << "Product Manager Menu" << endl;
        cout << "====================" << endl;
        cout << endl;
        cout << "(1) Create a Part" << endl;
        cout << "(2) Print all Parts" << endl;
}*/

void View::list_parts() {
	cout << endl;
	cout << "-------------" << endl;
	cout << "List of Parts" << endl;
	cout << "-------------" << endl;
	for(int i = 0; i < database.number_of_parts(); ++i){
                cout << i << ") " << database.part_to_string(i) << endl;
        }
}
