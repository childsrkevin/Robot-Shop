#include"PM.h"
#include"View.h"
#include "Database.h"
#include "Part.h" 
#include "Controller.h"  
#include <iostream>
#include <string>

using namespace std;
void PM :: pm_menu()
{
    int cmd;
    cout << endl << endl;
    cout << "====================" << endl;
    cout << "Product Manager Menu" << endl;
    cout << "====================" << endl;
    cout << endl;
    cout << "(1) Create a Part" << endl;
    cout << "(2) Print all Parts" << endl;

    cout << "Command?";
    cin >> cmd;
    cin.ignore();
    pm_cmd(cmd);
}

Part PM :: pm_cmd(int cmd)
{
    if(cmd == 1)
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

        return Part(type, description, name, number, cost, weight);
    }
    //if(cmd == 2)
      //  controller.view.list_parts();
}
