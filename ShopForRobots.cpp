#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotShop.h"

using namespace std;

robopart t, a, h, l, b;
robomodel model;

void menu();
void pm();
void printlist();
void newPart();
void printB();
void printA();
void printH();
void printL();
void printT();
void remove();
void removeline(int line,string type);
void bc();
void preparts();
void assemble();
void printM();

int main()
{
	int wait;
	preparts();
	menu();
	//cin >> wait;
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

	}
	else if (value == 3)
	{

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
		//Need to be able to create new instances of robot components in the system
		//For each component: Name, Part Number, type(torso, head, arm, locomotor, battery),
		//weight, cost and descprition
	{
		int value;
		cout << "\n\n~~~~Product Manager~~~~\n0 - Create new Model\n1 - Create new Part\n2 - Remove\n3 - Print all parts\n4 - Print all Models\n5 - Main Menu\n6 - QUIT\n";
		cin >> value;
		if (value == 0)
		{
			assemble();
			pm();
		}
		if (value == 1)
		{
			newPart();
			pm();
		}
		else if (value == 2)
		{
			remove();
			pm();
		}
		else if (value == 3)
		{
			printlist(/*totalparts.csv"*/);
			pm();
		}
		else if (value == 4)
		{
			printM();
		}
		else if (value == 5)
			menu();
		else if (value == 6)
			return;


}


void printlist()
{
	int value;
	/*int i = 0;
	cout << "\n\n~~~~List of Parts~~~~\n";
	ifstream inputfile(file);
	string line;
	while (getline(inputfile, line))
	{
		std::istringstream iss(line);
		cout << i++ << " - " << line << "\n";
	}*/
	cout << "\n\n~~~~Print Menu~~~~\n1 - Head\n2 - Battery\n3 - Arm\n4 - Locomotor\n5 - Torso\n6 - All Parts\n";
	cin >> value;
	if (value == 1)
		printH();
	else if (value == 2)
		printB();
	else if (value == 3)
		printA();
	else if (value == 4)
		printL();
	else if (value == 5)
		printT();
	else if (value == 6)
	{
		printA();
		printB();
		printH();
		printL();
		printT();
	}

	return;
}

void newPart()
{
	ofstream outputfile;
	//append
	string name, description, type;
	int number;
	double cost, weight;

	//ofstream outputfile;
	//outputfile.open("totalparts.csv", std::ios_base::app);

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


	//outputfile << name << "," << number << "," << type << "," << weight << "," << cost << "," << description << endl;
	cout << "New Part Added!\n";

	//outputfile.close();

	if (type == "torso")
	{
		t.name.push_back(name);
		t.number.push_back(number);
		t.weight.push_back(weight);
		t.cost.push_back(cost);
		t.description.push_back(description);
		t.inc();
	}
	else if (type == "arm" || type == "Arm")
	{
		a.name.push_back(name);
		a.number.push_back(number);
		a.weight.push_back(weight);
		a.cost.push_back(cost);
		a.description.push_back(description);
		a.inc();
	}
	else if (type == "head" || type == "Head")
	{
		//outputfile.open("head.csv", std::ios_base::app);
		h.name.push_back(name);
		h.number.push_back(number);
		h.weight.push_back(weight);
		h.cost.push_back(cost);
		h.description.push_back(description);
		//outputfile << "Battery, " << b.name[h.i] << ", " << b.number[h.i] << ", " << b.weight[h.i] << ", " << b.cost[h.i] << ", " << b.description[h.i] << "\n";
		h.inc();
	}
	else if (type == "battery" || type == "Battery")
	{
		
		//outputfile.open("battery.csv", std::ios_base::app);

		b.name.push_back(name);
		b.number.push_back(number);
		b.weight.push_back(weight);
		b.cost.push_back(cost);
		b.description.push_back(description);
		//outputfile << "Battery, " << b.name[b.i] << ", " << b.number[b.i] << ", " << b.weight[b.i] << ", " << b.cost[b.i] << ", " << b.description[b.i] << "\n";
		b.inc();

		//outputfile.close();
	}
	else if (type == "locomotor" || type == "Locomotor")
	{
		l.name.push_back(name);
		l.number.push_back(number);
		l.weight.push_back(weight);
		l.cost.push_back(cost);
		l.description.push_back(description);
		l.inc();
	}
}

void printB() {
	cout << "\n~~List of All Batteries~~\n";
	for (int i = 0; i < b.number.size(); i++)
		if(b.name[i] != "0")
		cout << i << " - Battery, " << b.name[i] << ", " << b.number[i] << ", " << b.weight[i] << ", " << b.cost[i] << ", " << b.description[i] << "\n";
		
}
void printT() {
	cout << "\n~~List of All Torsos~~\n";
	for (int i = 0; i<t.number.size(); i++)
		if (t.name[i] != "0")
		cout << i << " - Torso, " << t.name[i] << ", " << t.number[i] << ", " << t.weight[i] << ", " << t.cost[i] << ", " << t.description[i] << "\n";
}

void printH() {
	cout << "\n~~List of All Heads~~\n";
	for (int i = 0; i<h.number.size(); i++)
		if (h.name[i] != "0")
		cout << i << " - Head, " << h.name[i] << ", " << h.number[i] << ", " << h.weight[i] << ", " << h.cost[i] << ", " << h.description[i] << "\n";
}

void printL() {
	cout << "\n~~List of All Locomotors~~\n";
	for (int i = 0; i<l.number.size(); i++)
		if (l.name[i] != "0")
		cout << i <<" - Locomotor, " << l.name[i] << ", " << l.number[i] << ", " << l.weight[i] << ", " << l.cost[i] << ", " << l.description[i] << "\n";
}

void printA() {
	cout << "\n\n~~List of All Arms~~\n";
	for (int i = 0; i<a.number.size(); i++)
		if (a.name[i] != "0")
		cout << i << " - Arm, " << a.name[i] << ", " << a.number[i] << ", " << a.weight[i] << ", " << a.cost[i] << ", " << a.description[i] << "\n";
}

void remove() {
	int value;
	cout << "What type of part would you like to remove\n1 - Head\n2 - Battery\n3 - Arm\n4 - Locomotor\n5 - Torso\n";
	cin >> value;

	if (value == 1)
	{
		printH();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		removeline(value, "head");
        
	}
	else if (value == 2)
	{
		printB();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		removeline(value,"battery");
	}
	else if (value == 3)
	{
		printA();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		removeline(value, "arm");
	}
	else if (value == 4)
	{
		printL();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		removeline(value, "locomotor");
	}
	else if (value == 5)
	{ 
		printT();
		cout << "\n\nWhich part would you like to remove: ";
		cin >> value;
		removeline(value, "torso");
	}
}

void removeline(int line, string type)
{
	int i = 0;
	while (i < line)
		i++;
	if(type == "battery")
	    b.name[i] = "0";
	else if (type == "torso")
		t.name[i] = "0";
	else if (type == "locomotor")
		l.name[i] = "0";
	else if (type == "head")
		h.name[i] = "0";
	else if (type == "arm")
		a.name[i] = "0";

	cout << type << "number: " << line << " has been removed!\n";
}

void bc()
{
    
}

void preparts()
{
	l.name.push_back("locomotor1");
	l.number.push_back(1);
	l.weight.push_back(43.7);
	l.cost.push_back(120.5);
	l.description.push_back("This is locomotor1");
	l.inc();
	
	l.name.push_back("locomotor2");
	l.number.push_back(2);
	l.weight.push_back(34.2);
	l.cost.push_back(134.7);
	l.description.push_back("This is locomotor2");
	l.inc();

	l.name.push_back("locomotor3");
	l.number.push_back(3);
	l.weight.push_back(72.9);
	l.cost.push_back(78.9);
	l.description.push_back("This is locomotor3");
	l.inc();


	b.name.push_back("AA");
	b.number.push_back(123);
	b.weight.push_back(2.3);
	b.cost.push_back(5.3);
	b.description.push_back("This is a AA battery");
	b.inc();

	b.name.push_back("AAA");
	b.number.push_back(122);
	b.weight.push_back(2.1);
	b.cost.push_back(5.3);
	b.description.push_back("This is a AAA battery");
	b.inc();

	t.name.push_back("Expensive Torso");
	t.number.push_back(12345);
	t.weight.push_back(109.5);
	t.cost.push_back(300.8);
	t.description.push_back("This higher priced torso");
	t.inc();

	t.name.push_back("Value Torso");
	t.number.push_back(1234);
	t.weight.push_back(89.4);
	t.cost.push_back(160.3);
	t.description.push_back("This value priced torso");
	t.inc();

	a.name.push_back("Left Arm");
	a.number.push_back(12332);
	a.weight.push_back(46.3);
	a.cost.push_back(78.2);
	a.description.push_back("This the left arm");
	a.inc();

	a.name.push_back("Right Arm");
	a.number.push_back(12333);
	a.weight.push_back(46.3);
	a.cost.push_back(78.2);
	a.description.push_back("This the right arm");
	a.inc();

	h.name.push_back("Value Head");
	h.number.push_back(1236);
	h.weight.push_back(32.2);
	h.cost.push_back(89.2);
	h.description.push_back("This is the value head");
	h.inc();

	h.name.push_back("Expensive Head");
	h.number.push_back(1238);
	h.weight.push_back(32.2);
	h.cost.push_back(160.2);
	h.description.push_back("This is the expensive head");
	h.inc();
}

void assemble()
{
	
	string modelname;
	int value, modelnumber;
	double cost = 0;
	
	cout << "Name of new robot model: ";
	cin.ignore();
	getline(cin,modelname);
	printH();
	cout << "Pick a head for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	printT();
	cout << "Pick a torso for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	printA();
	cout << "Pick an arm for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	printA();
	cout << "Pick another arm for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	printL();
	cout << "Pick a locomotor for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	printB();
	cout << "Pick batteries for the new robot: ";
	cin >> value;
	cost = cost + h.cost[value];

	model.cost.push_back(cost);
	model.name.push_back(modelname);
	model.number.push_back(modelnumber);

	cout << modelname << " has been created and it cost $" << cost << " to make";

}

void printM()
{
	cout << "\n~~List of All Models~~\n";
	for (int i = 0; i < model.number.size(); i++)
		if (model.name[i] != "0")
			cout << model.name[i] << ", $" << model.cost[i] << ", Model Number: " << model.number[i] << "\n";
}
