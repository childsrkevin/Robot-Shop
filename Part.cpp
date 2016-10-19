#include"Part.h"
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

namespace patch
{
    template < typename T > std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

string Part::to_string(){
    //string pub = ("Type: " + type + ", Name: " + name + ", Cost: " + cost+ ", Weight in Pounds: " + weight + ", Description: " + description + "\n");
    
    string pub = "Type: ";
    pub += type;
    pub += ", Name: ";
    pub += name;
    pub += ", Cost: ";
    pub += patch::to_string(cost);
    pub += ", Weight in Pounds: ";
    pub += patch::to_string(weight);
    pub += ", Description: ";
    pub += description;
    
    return pub;
}
