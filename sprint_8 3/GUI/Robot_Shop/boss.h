#ifndef boss_h
#define boss_h


#include <iostream>
#include <string>
#include <vector>
#include"Database.h"
#include "View.h"
#include "controller.h"
#include "SA.h"


using namespace std;

class boss
{
public:
    void mp(vector<string> modname, vector<double> sellingprice, vector<double> totalcost);
    void totalsold(vector<string> modname, vector<string> modnamesold);
    void salesass(vector<string> seller, vector<string> seller_sold);
private:
};

#endif /* boss_h */
