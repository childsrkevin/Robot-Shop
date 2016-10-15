#include<iostream>
#include<string>
#include<vector>
#include"Database.h"
#include"Part.h"

using namespace std;

void Database::add_part(Part p)
{
	part.push_back(p);
}

string Database :: part_to_string(int index){
	return part[index].to_string();
}

int Database :: number_of_parts(){
        return part.size();
}

