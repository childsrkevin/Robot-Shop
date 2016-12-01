#include "PM.h"
#include"Robotpart.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PM::printmodels()
{
    part.printmodel();
}
vector<string> PM::return_mod_name()
{
    return part.return_model_name();
}
vector<double> PM::return_mod_price()
{
    return part.return_model_price();
}
vector<double> PM::return_mod_totalcost()
{
    return part.return_mod_totalcost();
}
void PM :: menu()
{
    int decision = -1;
    cout << "\n=====Product Manager Menu=====" << endl;
    
    cout << "1) Create a Part" << endl;
    cout << "2) Remove a Part" << endl;
    cout << "3) Create a Model" << endl;
    cout << "4) Remove a Model" << endl;
    cout << "5) Print All Parts" << endl;
    cout << "6) Print All Models" << endl;
    cout << "0) Main Menu" << endl;
    
    cout << "\nAction?" << endl;
    
    cin >> decision;
    cin.ignore();
    if(decision == 1)
        part.create();
    else if(decision == 2)
        part.remove();
    else if(decision == 3)
        part.createmodel();
    else if(decision == 4)
        part.removemodel();
    else if(decision == 5)
        part.print();
    else if(decision == 6)
        part.printmodel();
    else if(decision == 0)
        return;
    else if(decision == 8)
        part.givedata();
    else
    {
        cerr << "\n**Invalid command**\n" << endl;
    }
    
}

Robotpart PM :: getpart(){
    return part;
}
