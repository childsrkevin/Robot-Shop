#ifndef SA_h
#define SA_h

#include <iostream>
#include <string>
#include <vector>
#include"Database.h"
#include "View.h"
#include "controller.h"

using namespace std;

class SA
{
public:
    int return_sales();
    string input_name(string name);
    void input_name1(string name);
    void create_order(string input);
    void print_order(string input);
    void print_cus_order(string input);
    void menu2();
    void menu();
    void print_all_orders();
    vector<string> return_model_name();
    vector<string> return_quantity_sold();
    vector<string> return_seller();
    int login(string input);
    void ez();
    
private:
    vector<string> sellers;
    vector<string> order_seller;
    vector<string> c_name;
    vector<string> date;
    vector<int> order_number;
    vector<string> model;
    vector<int> quantity;
    vector<double> price;
    vector<string> quanity_sold;
    vector<string> quanity_names;
    int num_sellers;
    int num_sales;
    
};
#endif /* SA_h */
