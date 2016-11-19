#ifndef _PM_H
#define _PM_H
#include"Robotpart.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PM{
private:
    Robotpart part;
    vector <double> totalcost,shippingcost, sellingprice;
    vector <string> name;
    vector <string> description;
public:
    void menu();
    void printparts();
    void createpart();
    void removepart();
    void printmodels();
    Robotpart getpart();
    vector<string> return_mod_name();
    vector<double> return_mod_price();
    vector<double> return_mod_totalcost();
    
};

#endif //_PM_H
