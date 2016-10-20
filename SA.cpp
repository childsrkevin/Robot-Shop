#include"PM.h"
#include"View.h"
#include "Database.h"
#include "controller.h"

#include <stdio.h>
#include <iostream>
#include "SA.h"

void SA :: ez(){
    num_sales = 0;
    num_sellers = 0;
}
void SA::input_name1(string a)
{
    sellers.push_back(a);
    num_sellers++;
}
int SA::login(string input)
{
    for(int i=0;i<sellers.size();i++)
    {
        if(input==sellers[i])
        {
            return 1;
        }
    }
    return 0;
}
void SA::create_order(string input)
{
    string cus_name,date1,model1;
    int order_num,quantity1;
    double price1;
    num_sales++;
    order_seller.push_back(input);
    
    cout<<"Enter Customers Name:"<<'\n';
    getline(cin,cus_name);
    c_name.push_back(cus_name);
    
    cout<<"Enter Order Number:"<<'\n';
    cin>>order_num;
    cin.ignore();
    order_number.push_back(order_num);
    
    cout<<"Enter Date Of Sale:"<<'\n';
    getline(cin,date1);
    date.push_back(date1);
    
    cout<<"Enter Robot Model:"<<'\n';
    getline(cin,model1);
    model.push_back(model1);
    
    cout<<"Enter Quantity:"<<'\n';
    cin >>quantity1;
    cin.ignore();
    quantity.push_back(quantity1);
    
    cout<<"Enter Price:"<<'\n';
    cin >> price1;
    cin.ignore();
    price.push_back(price1);
    
    for(int i = 0; i < quantity1;i++)
    {
        quanity_sold.push_back(model1);
        quanity_sold.push_back(sellers[num_sales-1]);
    }
}
vector<string> SA::return_quantity_sold()
{
    return quanity_sold;
}
vector<string> SA::return_seller()
{
    return sellers;
}
void SA::print_order(string input)
{
    cout<<"\n";
    for(int i =0 ;i<num_sales;i++)
    {
        if(input == order_seller[i])
        {
            cout<<"Order Number:"<<order_number[i]<<"  Customer: "<<c_name[i]<<"  Date: "<<date[i]<<"  Model: "<<model[i]<<"  Quanity: "<<quantity[i]<<"  Price: "<<price[i]<<'\n';
        }
    }
    
}
void SA::print_cus_order(string input)
{
    cout<<"\n";
    for(int i =0 ;i<num_sales;i++)
    {
        if(input == c_name[i])
        {
            cout<<"Order Number:"<<order_number[i]<<"  Date: "<<date[i]<<"  Model: "<<model[i]<<"  Quanity: "<<quantity[i]<<"  Price: "<<price[i]<<'\n';
        }
    }
    
}
void SA::print_all_orders()
{
    cout<<"\n";
    for(int i =0 ;i<num_sales;i++)
    {
        {
            cout<<"Seller: "<<order_seller[i]<<"  Order Number:"<<order_number[i]<<"  Customer: "<<c_name[i]<<"  Date: "<<date[i]<<"  Model: "<<model[i]<<"  Quanity: "<<quantity[i]<<"  Price: "<<price[i]<<'\n';
        }
    }
    
}

int SA::return_sales()
{
    return num_sales;
}
vector<string> SA:: return_model_name()
{
    return quanity_sold;
}
void SA::menu2()
{
    cout<<"\nEnter Designated Number From Menu"<<'\n';
    cout<<"1)Make an Order"<<'\n';
    cout<<"2)View Sales Report"<<'\n';
    cout<<"0)Return to Main Menu"<<'\n';
}



