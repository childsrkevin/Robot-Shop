#ifndef customer_h
#define customer_h

#include <iostream>
#include <string>
#include <vector>
#include"Database.h"
#include "View.h"
#include "SA.h"
#include"controller.h"


using namespace std;

class customer
{
public:
    void print_menu2();
    void input_name1(string name);
    int login(string input);
    
private:
    vector<string> name;
    int number_customers;
};
#endif /* customer_h */
