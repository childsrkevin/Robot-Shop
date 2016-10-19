#include "controller.h"
#include "customer.h"
#include "View.h"
#include "Database.h"
#include "Part.h"
#include "PM.h"
#include "SA.h"

#include<iostream>
#include<string>



using namespace std;
using std::string;
using std::getline;

void customer::input_name1(string a)
{
    name.push_back(a);
    number_customers ++;
}
int customer::login(string input)
{
    for(int i=0;i<name.size();i++)
    {
        if(input==name[i])
        {
            return 1;
        }
    }
    return 0;
}
void customer::print_menu2()
{
    cout<<"\nEnter Designated Number From Menu"<<'\n';
    cout<<"1) View catalog of robots"<<'\n';
    cout<<"2) View Order"<<'\n';
    cout<<"0) To Return To Main Menu"<<'\n';
}



