#ifndef customer_h
#define customer_h
#endif /* customer_h */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
public:
    void customer_menu();
    void print_menu2();
    string input_name(string name);
    
private:
    vector<string> name;
    int number_customers;
};
