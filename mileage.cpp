//
//  main.cpp
//  mileage
//
//  Created by Alex Nunez on 9/6/16.
//  Copyright © 2016 Alex Nunez. All rights reserved.
//

#include <iostream>
using namespace std;

class mpg_log
{
private:
    double last_odometer=0;
    double this_odometer=0;
    double this_gas=0;
public:
    double current_odometer(double last_odometer,double this_odometer)
    {
        return this_odometer-last_odometer;
    }
    double get_current_mpg(double last_odometer,double this_odometer, double this_gas)
    {
        return current_odometer(last_odometer,this_odometer)/this_gas;
    }
};
int main()
{
    mpg_log car;
    
    double i,f,g;
    cout << "Initital Odometer: ";
    cin >> i;
    while(i !=0)
    {
        cout << "Odometer: ";
        cin >> f;
        if(f==0)
        {
            break;
        }
        cout << "Gallons: ";
        cin >> g;
    
        cout<<"This mpg: "<< car.get_current_mpg(i,f,g)<<'\n';
        
        i=f;
        cout<<"To quit enter 0 for Odometer."<<'\n';
    }
    return 0;
}
