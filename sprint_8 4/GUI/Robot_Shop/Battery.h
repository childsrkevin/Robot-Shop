#ifndef _BATTERY_H
#define _BATTERY_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Battery{
public:
    vector <string> type, description, name;
    vector <double> cost, weight;
    vector <int> number;
    void store(string t, string n, int num, double c, double w, string d);
    void print();
    void remove(int index);
};

#endif //_BATTERY_H
