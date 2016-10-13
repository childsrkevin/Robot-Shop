#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotShop.h"

using namespace std;

robopart t, a, h, l, b;
robomodel model;
unapproved pending;

void menu();
void pm();
void printlist();
void newPart();
void remove();
void bc();
void preparts();
void assemble();
void sa();

int main()
{
	cout << "THIS IS A TEST\n";
	preparts();
	menu();
    return 0;
}

void menu()
{
	int value;
	cout << "\n\n~~~~MENU~~~~\n";
	cout << "1 - Product Manager\n";
	cout << "2 - Beloved Customer\n";
	cout << "3 - Sales Associate\n";
	cout << "4 - Pointed-haired Boss\n";
	cout << "5 - QUIT\n";
	cin >> value;
	if (value == 1)
	{
		pm();
	}
	else if (value == 2)
	{
		bc();
	}
	else if (value == 3)
	{
		sa();
	}
	else if (value == 4)
	{

	}
	else if (value == 5)
	{
		return;
	}
}

	void pm()
	{
		int value;
		cout << "\n\n~~~~Product Manager~~~~\n0 - Create new Model\n1 - Create new Part\n2 - Remove\n3 - Print all parts\n4 - Print all Models\n5 - Main Menu\n6 - QUIT\n";
		cin >> value;
		if (value == 0)
			assemble();
		else if (value == 1)
			newPart();
		else if (value == 2)
			remove();
		else if (value == 3)
			printlist();
		else if (value == 4)
			model.print();
		else if (value == 5)
			menu();
		else if (value == 6)
			return;

		pm();
}


void printlist()
{
	int value;
	cout << "\n\n~~~~Print Menu~~~~\n1 - Head\n2 - Battery\n3 - Arm\n4 - Locomotor\n5 - Torso\n6 - All Parts\n";
	cin >> value;
	cout << "\n\n";
	if (value == 1)
		h.print();
	else if (value == 2)
		b.print();
	else if (value == 3)
		a.print();
	else if (value == 4)
		l.print();
	else if (value == 5)
		t.print();
	else if (value == 6)
	{
		h.print();
		b.print();
		a.print();
		l.print();
		t.print();
	}

	return;
}

void newPart()
{
	string name, description, type;
	int number;
	double cost, weight;

	cin.ignore();
	cout << "Enter a name for the part: ";
	getline(cin, name);
	cout << "Enter the part number: ";
	cin >> number;
	cout << "What type of part is it: ";
	cin >> type;
	cout << "Weight in pounds: ";
	cin >> weight;
	cout << "Price: ";
	cin >> cost;
	cin.ignore();
	cout << "Breif Description: ";
	getline(cin, description);

	if (type == "torso")
		t.store(name,number,weight,cost,description);
	else if (type == "arm" || type == "Arm")
		a.store(name, number, weight, cost, description);
	else if (type == "head" || type == "Head")
		t.store(name, number, weight, cost, description);
	else if (type == "battery" || type == "Battery")
		t.store(name, number, weight, cost, description);
	else if (type == "locomotor" || type == "Locomotor")
		t.store(name, number, weight, cost, description);

	cout << "New Part Added!\n";
}


void remove() {
	int value;
	cout << "What type of part would you like to remove\n1 - Head\n2 - Battery\n3 - Arm\n4 - Locomotor\n5 - Torso\n";
	cin >> value;

	if (value == 1)
	{
		h.print();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		h.removeline(value);       
	}
	else if (value == 2)
	{
		b.print();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		b.removeline(value);
	}
	else if (value == 3)
	{
		a.print();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		a.removeline(value);
	}
	else if (value == 4)
	{
		l.print();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		l.removeline(value);
	}
	else if (value == 5)
	{ 
		t.print();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		t.removeline(value);
	}
}


void bc()
{
	int decision;
	double total;
	string name, date, modname, status = "Order Pending";
	cout << "\n\n~~~Welcome Customers!~~~\n1 - View Models\n2 - View Orders\n";
	cin >> decision;
	if (decision == 1)
	{
		model.print();
		cout << "\n Which product would you like to buy?";
		cin >> decision;
		modname = model.decision(decision);
		cout << "For our Records...\nEnter Customers Name: ";
		cin.ignore();
		getline(cin,name);
		cout << "Enter the date: ";
		cin >> date;
		total = model.purchase(decision);
		pending.store(status,name,total,date,modname);
		cout << "Thank you for your purchase! Our Next available Sales Associate will order your model right away!\n";
		menu();
	}
	else if (decision == 2)
	{
		int value;
		string name;
		cout << "Please Enter Your Name: ";
		cin.ignore();
		getline(cin, name);
		value = pending.search(name);
		cout << value << " orders found!\n";
		menu();
	}
}

void preparts()
{
	l.store("locomotor1",1,43.7,120.5,"This is locomotor1");
	l.store("locomotor2", 2, 34.2, 134.7, "This is locomotor2");
	l.store("locomotor3", 3, 72.9, 78.9, "This is locomotor3");

	b.store("AA", 123, 2.3, 5.3, "This is a AA battery");
	b.store("AAA", 122, 2.1, 5.3, "This is a AAA battery");

	t.store("Expensive Torso", 12345, 109.5, 300.8, "The higher priced torso");
	t.store("Value Torso", 1234, 89.4, 160.3, "The value priced torso");

	a.store("Left Arm", 12332, 46.3, 78.2, "This is the left arm");
	a.store("Right Arm", 12333, 46.3, 78.2, "This is the right arm");

	h.store("Value Head", 1236, 32.2, 89.2, "This is the value head");
	h.store("Expensive Head", 1238, 32.2, 160.2, "This is the expensive head");	

	model.store(800, "Kevin 2000", 123, 8.78, 1099.99,"This is a description");
	model.store(1000, "Alex 3000", 1234, 8.78, 1299.99, "This is a description");
	model.store(500, "CheapBot", 12345, 8.78, 799.99, "This is a description");
}

void assemble()
{
	string modelname, description;
	int value, modelnumber;
	double cost = 0,get, sellingprice, shipping;
	
	cout << "Name of new robot model: ";
	cin.ignore();
	getline(cin,modelname);
	h.print();
	cout << "Pick a head for the new robot: ";
	cin >> value;
	get = h.gcost(value);
	cost = cost + get;

	t.print();
	cout << "Pick a torso for the new robot: ";
	cin >> value;
	get = t.gcost(value);
	cost = cost + get;

	a.print();
	cout << "Pick an arm for the new robot: ";
	cin >> value;
	get = a.gcost(value);
	cost = cost + get;

	a.print();
	cout << "Pick another arm for the new robot: ";
	cin >> value;
	get = a.gcost(value);
	cost = cost + get;

	l.print();
	cout << "Pick a locomotor for the new robot: ";
	cin >> value;
	get = l.gcost(value);
	cost = cost + get;

	b.print();
	cout << "Pick batteries for the new robot: ";
	cin >> value;
	get = b.gcost(value);
	cost = cost + get;

	cout << "\n\nModel Number: ";
	cin >> modelnumber;

	cout << "\n\n" << modelname << "Takes $" << cost << "to make\nSelling Price: ";
	cin >> sellingprice;

	cout << "\nShipping Cost: ";
	cin >> shipping;

	cout << "Description: ";
	cin >> description;

	model.store(cost,modelname,modelnumber,shipping,sellingprice, description);
	cout << modelname << " has been created!\n";
}

void sa() {
	string salesname;
	int test;
	cout << "Sales Associate Name: ";
	cin.ignore();
	getline(cin,salesname);
	
	cout << "Welcome!\n";
		pending.printpend();
	
		cout << "Which person would you like to Assist: ";
		cin >> test;
		pending.statchange(test);
		menu();
}

