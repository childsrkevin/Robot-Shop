#include "controller.h"
#include "customer.h"
#include "View.h"
#include "Database.h"
#include "Part.h"
#include "PM.h"
#include "SA.h"
#include "boss.h"

#include<iostream>
#include<string>

using namespace std;
using std::string;
using std::getline;

void boss :: mp(vector<string> modname, vector<double> sellingprice, vector<double> totalcost)
{
    cout<<"\n";
    int i = 0;
    while(i < modname.size())
    {
        cout << "\nModel Name: " << modname[i] << ", Profit: $" << (sellingprice[i] - totalcost[i]) << endl;
        i++;
    }
}

void boss::totalsold(vector<string> modname,vector<string> modnamesold)
{
    cout<<"\n";
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < modname.size();i++)
    {
        count=0;
        for(j = 0; j < modnamesold.size();j++)
        {
            if(modname[i] == modnamesold[j])
                count++;
        }
        cout<<"Model Name: "<<modname[i]<<"   Quantity Sold: "<<count<<'\n';
    }
}
void boss::salesass(vector<string> seller, vector<string> seller_sold)
{
    cout<<"\n";
    int i = 0, j = 0, count = 0;
    
    for(i = 0; i < seller.size();i++)
    {
        count=0;
        for(j = 0; j < seller_sold.size();j++)
        {
            if(seller[i] == seller_sold[j])
                count++;
        }
        cout<<"Seller: "<<seller[i]<<"   Quantity Sold: "<<count<<'\n';
    }
}
