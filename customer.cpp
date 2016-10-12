#include <stdio.h>
#include <iostream>
#include "customer.h"

using namespace std;
using std::string;
using std::getline;

string customer::input_name(string a)
{
    cout<<"Enter Your Name: "<<'\n';
    getline(cin,a);
    return a;
}
void customer::print_menu2()
{
    cout<<"Enter Designated Number From Menu"<<'\n';
    cout<<"1) View catalog of robots"<<'\n';
    cout<<"2) View Order"<<'\n';
    cout<<"3) View Outstanding Bill"<<'\n';
    cout<<"0) To Return To Main Menu"<<'\n';
}

void customer::customer_menu()
{
    int x;
    string input,a = "";
    
    cout<<"Enter Designated Number From Menu"<<'\n';
    cout<<"1) If You Are a New Customer"<<'\n';
    cout<<"2) If You Are a Returning Customer"<<'\n';
    cout<<"0) To Return To Main Menu"<<'\n';
    cin>> x;
    if(x==1)
    {
        input = input_name(a);
        name.push_back(input);
        number_customers ++;
    }
    else if(x==2)
    {
        cout<<"Enter your name"<<'\n';
        getline(cin,a);
        for(int i=0;i<number_customers;i++)
        {
            if(name[i] == a)
            {
                while(x!=0)
                {
                    print_menu2();
                    cin>> x;
                    if(x==1)
                    {
                        
                    }
                    else if(x==2)
                    {
                        
                    }
                    else if(x==3)
                    {
                        
                    }
                }
            }
        }
    }
}



