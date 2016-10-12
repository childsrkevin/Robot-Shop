#include<iostream>
#include<string>
#include<vector>

using namespace std;

class robopart {
public:
	vector <int> number;
	vector <double> cost, weight;
	vector <string> description, name;
    int i = 0;
	void inc() { i++; };
};

class robomodel {
public:
	vector <double> cost;
	vector <string> name;
	vector <int> number;
};



