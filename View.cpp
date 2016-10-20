#include"View.h"
#include<iostream>
#include<string>

using namespace std;

void View::show_menu()
{
    cout << endl << endl;
    cout << "==========" << endl;
    cout << "Main Menu" << endl;
    cout << "==========" << endl;
    cout << endl;
    cout << "(1) Product Manager" << endl;
    cout << "(2) Beloved Customer" << endl;
    cout << "(3) Sales Associate" << endl;
    cout << "(4) Pointed-Haired Boss" << endl;
    cout << "(0) Exit" << endl;
}
void View::sales_menu()
{
    cout<<"\nEnter Designated Number From Menu"<<'\n';
    cout<<"1)New Sales Associate"<<'\n';
    cout<<"2)Returning Sales Associate"<<'\n';
}
void View::customer_menu()
{
    cout<<"\nEnter Designated Number From Menu"<<'\n';
    cout<<"1) If You Are a New Customer"<<'\n';
    cout<<"2) If You Are a Returning Customer"<<'\n';
    cout<<"0) To Return To Main Menu"<<'\n';
}
void View::boss_menu()
{
    cout<<"\nEnter Designated Number From Menu"<<'\n';
    cout<<"1)View Profit Margin"<<'\n';
    cout<<"2)View Models Sold"<<'\n';
    cout<<"3)View Complete List of Orders"<<'\n';
    cout<<"4)View Sales For Each Sales Associate"<<'\n';
    cout<<"0) To Return To Main Menu"<<'\n';
}
