#include "Controller.h"
//#include "customer.h"
#include "View.h"
#include "Database.h"
#include "Part.h"
#include<iostream>
#include<string>
#include "PM.h" 
using namespace std;

void Controller::cli(){
	int cmd = -1;
	while (cmd != 0)
	{
		view.show_menu();
		cout << "Command? ";
		cin >> cmd;
		cin.ignore();
		execute_cmd(cmd);
	}
}

void Controller::execute_cmd(int cmd){
	if(cmd == 1)//go to pm
        {
                pm.pm_menu();
                 cout << "Command? ";
                 cin >> cmd;
                 cin.ignore();
        }
        else if(cmd == 2)
        {
        //        customer.customer_menu();
        }
}


/*void Controller::execute_PM_cmd(int cmd) {
	if (cmd == 1) // Add part
	{
		string type, name, description;
		int number;
		double cost, weight;

		cout << "Type? ";
		getline(cin, type);

		cout <<  "Name? ";
		getline(cin, name);

		cout << "Description? ";
		getline(cin, description);

		cout << "Part Number? ";
		cin >> number;
		cin.ignore();

		cout << "Cost? ";
		cin >> cost;
		cin.ignore();

		cout << "Weight in Pounds? ";
		cin >> weight;
		cin.ignore();
		
		database.add_part(Part(type, description, name, number, cost, weight));

	}
	else if(cmd == 2) //Print Parts
        {
                view.list_parts();
        } 
}*/
