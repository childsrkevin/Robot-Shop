#include<vector>
#include<string>
#include<iostream>
#include"Torso.h"

using namespace std;

void Torso :: store(string t, string n, int num, double c, double w, string d){
    type.push_back(t);
    name.push_back(n);
    number.push_back(num);
    cost.push_back(c);
    weight.push_back(w);
    description.push_back(d);
}

void Torso :: print(){
    cout << "\n=====" << name.size() << " Total Torso Parts=====" << endl;
    for(int i = 0; i < name.size(); i++){
        cout << "Name: " << name[i] << endl;
        cout << "PartNumber: " << number[i] << endl;
        cout << "Cost: " << cost[i] << endl;
        cout << "Weight: " << weight[i] << endl;
        cout << "Description: " << description[i] << endl;
        cout << "----------------------" << endl;
    }
}

void Torso :: remove(int index)
//Removes at index
{
    type.erase(type.begin() + index);
    name.erase(name.begin() + index);
    number.erase(number.begin() + index);
    cost.erase(cost.begin() + index);
    weight.erase(weight.begin() + index);
    description.erase(description.begin() + index);
}
