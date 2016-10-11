#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotShop.h"

using namespace std;

void menu();
void pm();
void printlist(string file);
void newPart();
int main()
{
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
	cout << "\n\n~~~~Product Manager~~~~\n1 - Create\n2 - Remove\n3 - Print\n4 - Main Menu\n0 - QUIT\n";
	cin >> value;
	if (value == 1)
	{
		newPart();
	}
	else if (value == 3)
	{
		printlist("totalparts.csv");
		pm();
	}
	else if (value == 4)
		menu();
	else if (value == 0)
		return;
	

}

void printlist(string file)
{
    int i =  0;
	cout << "\n\n~~~~List of Parts~~~~\n";
	ifstream inputfile(file);
	string line;
	while (getline(inputfile, line))
	{
		std::istringstream iss(line);
		cout << i++ <<" - "<< line << "\n";
	}
	return;
}

void newPart()
{
	//append
	//robopart part;
	double weight, cost;
	int number;
	string type, name, description;
	ofstream outputfile;
	outputfile.open("totalparts.csv", std::ios_base::app);
	
	cin.ignore();
	cout << "Enter a name for the part: ";
	getline(cin,name);
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
	getline(cin,description);
	

	outputfile << name << "," << number << "," << type << "," << weight << "," << cost << "," << description << endl;
	cout << "New Part Added!\n";

	outputfile.close();
	pm();
}
