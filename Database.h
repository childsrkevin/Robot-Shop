#ifndef _DATABASE_H
#define _DATABASE_H
#include<iostream>
#include<string>
#include<vector>
#include"Part.h"

using namespace std;

class Database {
public:
    void add_part(Part p);
    
    string part_to_string(int index);
    
    int number_of_parts();
private:
    vector <Part> part;
};

#endif
