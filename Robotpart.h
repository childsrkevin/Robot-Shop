#ifndef _ROBOTPART_H
#define _ROBOTPART_H
#include<iostream>
#include<vector>
#include<string>
#include"Head.h"
#include"Arm.h"
#include"Torso.h"
#include"Battery.h"
#include"Locomotor.h"
class Robotpart{
public:
    string type, description, name;
    double cost, weight;
    int number;
    vector <string> modd;
    vector <string> modname;
    vector <double> sellingprice, shippingcost, totalcost;
    Head head;
    Arm arm;
    Torso torso;
    Locomotor locomotor;
    Battery battery;
    void create();
    void print();
    void remove();
    void printh();
    void printa();
    void printt();
    void printl();
    void printb();
    void createmodel();
    void removemodel();
    void printmodel();
    void givedata();
    vector<string> return_model_name();
    vector<double> return_model_price();
    vector<double> return_mod_totalcost();
    
};

#endif //_ROBOTPART_H

