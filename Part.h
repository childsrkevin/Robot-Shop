#ifndef _PART_H
#define _PART_H

#include<iostream>
#include<string>

using namespace std;

class Part {
	public:
		Part(string p_type,
		string p_description,
		string p_name,
		int p_number,
		double p_cost,
		double p_weight) :

		type(p_type),
		description(p_description),
		name(p_name),
		number(p_number),
		cost(p_cost),
		weight(p_weight) {}

        string to_string();
	
	private:
		string type;
		string description;
		string name;
		int number;
		double cost;
		double weight;
};

#endif
