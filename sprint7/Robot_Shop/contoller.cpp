#include"controller.h"
#include "customer.h"
#include "View.h"
#include "Database.h"
#include<iostream>
#include<string>
#include "PM.h"
#include "SA.h"

using namespace std;


void Controller::cli()
{
    int cmd = -1;
    s.ez();
    while (cmd != 0)
    {
        view.show_menu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore();
        if(cmd>4)
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        execute_cmd(cmd);
    }
}

void Controller::execute_cmd(int cmd)
{
    int choice=0;
    string input;
    
    if(cmd == 1)//go to pm
    {
        pm.menu();
    }
    else if(cmd == 2)
    {
        int x=3;
        string input,a = "";
        while(x >2 || x <1)
        {
        view.customer_menu();
        cin>>x;
        cin.ignore();
        if(x==1)
        {
            cout<<"Enter Your Name: ";
            getline(cin,a);
            
            c.input_name1(a);
        }
        else if(x==2)
        {
            int b=0;
            while(b!=2)
            {
            cout<<"Enter your name: ";
            getline(cin,a);
            b=c.login(a);
            
            if(b==1)
            {
                cout<<'\n'<<a<<" is logged in"<<'\n';
                break;
            }
            else
            {
                cout<<'\n'<<"Customer is not on file"<<'\n';
                x=3;
                break;
            }
            }

        }
        else if(x==0)
        {
            break;
        }
        else
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
        while(x!=0)
        {
            c.print_menu2();
            cin>> x;
            cin.ignore();
            if(x==1)
            {
                pm.printmodels();
            }
            else if(x==2)
            {
                s.print_cus_order(a);
            }
            else if(choice !=0 && (choice>2|| choice<0))
            {
                cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
            }
        }
    }
    
    else if(cmd == 3)
    {
        choice=3;
        while(choice >2 || choice <1)
        {
        view.sales_menu();
        cin>> choice;
        cin.ignore();
        
        if (choice == 1)
        {
            cout<<"Enter Your Name: ";
            getline(cin,input);
            s.input_name1(input);
        }
        else if(choice == 2)
        {
            int b=0;
            while(b!=2)
            {
            cout<<"Enter Your Name: ";
            getline(cin,input);
            b=s.login(input);
            if(b==1)
            {
                cout<<'\n'<<input<<" is logged in"<<'\n';
                break;
            }
            else
            {
               cout<<'\n'<<"Seller is not on file"<<'\n';
                choice=3;
                break;
            }
            }
        }
        else
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
        while(choice!=0)
        {
            s.menu2();
            cin>> choice;
            cin.ignore();
            if(choice==1)
            {
                pm.printmodels();
                s.create_order(input);
            }
            else if(choice==2)
            {
                s.print_order(input);
            }
            else if(choice !=0 && (choice>2|| choice<0))
            {
                cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
            }
            
        }
    }
    else if(cmd == 4)
    {
        int choice=1;
        while(choice !=0)
        {
        view.boss_menu();
        cin>>choice;
        cin.ignore();
        
        if(choice==1)
        {
            vector<string> models=pm.return_mod_name();
            vector<double> price=pm.return_mod_price();
            vector<double> total_cost=pm.return_mod_totalcost();
            b.mp(models, price, total_cost);
            
        }
        else if(choice==2)
        {
            vector<string> models=pm.return_mod_name();
            vector<string> modnamesold = s.return_model_name();
            b.totalsold(models, modnamesold);
        }
        else if(choice==3)
        {
            s.print_all_orders();
        }
        else if(choice ==4)
        {
            vector<string> seller = s.return_seller();
            vector<string> quantity_sold= s.return_quantity_sold();
            b.salesass(seller,quantity_sold);
        }
        else if(choice !=0 && (choice>4|| choice<0))
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
    }
}
