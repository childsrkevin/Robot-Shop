#include"Arm.h"
#include"Battery.h"
#include"Torso.h"
#include"Locomotor.h"
#include"Head.h"
#include"Robotpart.h"
#include<iostream>
#include<string>

using namespace std;

void Robotpart :: create(){
    cout << "Enter a Part type: " << endl;
    getline(cin, type);
    cout << "Enter a Part Name: " << endl;
    getline(cin,name);
    cout << "Enter the Part Number: " << endl;
    cin >> number;
    cin.ignore();
    cout << "Enter the Cost of Part: " << endl;
    cin >> cost;
    cin.ignore();
    cout << "Enter the Weight in Pounds: " << endl;
    cin >> weight;
    cin.ignore();
    cout << "Enter the Description: " << endl;
    getline(cin,description);
    
    
    if(type == "torso" || type == "Torso")
        torso.store(type,name,number,cost,weight,description);
    else if(type == "head" || type == "Head")
        head.store(type,name,number,cost,weight,description);
    else if(type == "arm" || type == "Arm")
        arm.store(type,name,number,cost,weight,description);
    else if(type == "locomotor" || type == "Locomotor")
        locomotor.store(type,name,number,cost,weight,description);
    else if(type == "battery" || type == "Battery")
        battery.store(type,name,number,cost,weight,description);
}
vector<string> Robotpart::return_model_name()
{
    return modname;
}
vector<double> Robotpart::return_model_price()
{
    return sellingprice;
}
vector<double> Robotpart::return_mod_totalcost()
{
    return totalcost;
}
void Robotpart :: print(){
    head.print();
    arm.print();
    torso.print();
    locomotor.print();
    battery.print();
}

void Robotpart :: remove(){
    int decision;
    
    cout << "=====Removing a Part=====" << endl;
    cout << "1) Head" << endl;
    cout << "2) Arm" << endl;
    cout << "3) Torso" << endl;
    cout << "4) Locomotor" << endl;
    cout << "5) Battery" << endl;
    cin >> decision;
    cin.ignore();
    
    if(decision == 1)
    {
        head.print();
        cout << "Which Head would you like to remove?" << endl;
        cin >> decision;
        head.remove(decision);
    }
    else if(decision == 2)
    {
        arm.print();
        cout << "Which Arm would you like to remove?" << endl;
        cin >> decision;
        arm.remove(decision);
    }
    else if(decision == 3)
    {
        torso.print();
        cout << "Which Torso would you like to remove?" << endl;
        cin >> decision;
        torso.remove(decision);
    }
    else if(decision == 4)
    {
        locomotor.print();
        cout << "Which Locomotor would you like to remove?" << endl;
        cin >> decision;
        locomotor.remove(decision);
    }
    else if(decision == 5)
    {
        battery.print();
        cout << "Which Battery would you like to remove?" << endl;
        cin >> decision;
        cin.ignore();
        battery.remove(decision);
    }
    cout << "Part Removed!" << endl;
}

void Robotpart :: printh(){
    head.print();
}
void Robotpart :: printa(){
    arm.print();
}
void Robotpart :: printt(){
    torso.print();
}
void Robotpart :: printl(){
    locomotor.print();
}
void Robotpart :: printb(){
    battery.print();
}


void Robotpart :: createmodel(){
    int decision = -1;
    string str;
    double tot = 0, temp;
    cout << "Enter the name of your new model: " <<endl;
    getline(cin,str);
    modname.push_back(str);
    
    printh();
    cout << "Choose a Head to use: " << endl;
    cin >> decision;
    cin.ignore();
    temp = head.cost[decision];
    tot += temp;
    
    printt();
    cout << "Choose a Torso to use: " << endl;
    cin >> decision;
    cin.ignore();
    temp = torso.cost[decision];
    tot += temp;
    
    printa();
    cout << "Choose the left arm: " << endl;
    cin >> decision;
    cin.ignore();
    temp = arm.cost[decision];
    tot += temp;
    
    printa();
    cout << "Choose the right arm: " << endl;
    cin >> decision;
    cin.ignore();
    temp = arm.cost[decision];
    tot += temp;
    
    printl();
    cout << "Choose a Locomotor to use: " << endl;
    cin >> decision;
    cin.ignore();
    temp = locomotor.cost[decision];
    tot += temp;
    
    printb();
    cout << "Choose a battery to use: " << endl;
    cin >> decision;
    cin.ignore();
    temp = battery.cost[decision];
    tot += temp;
    
    totalcost.push_back(tot);
    
    cout << "This model costs $" << tot << " to make\nSelling price: "<< endl;
    cin >> tot;
    cin.ignore();
    sellingprice.push_back(tot);
    
    cout << "Shipping Cost: " << endl;
    cin >> tot;
    cin.ignore();
    shippingcost.push_back(tot);
    
    cout << "Description: " << endl;
    getline(cin,str);
    modd.push_back(str);
    
    cout << "model created!" << endl;
    
}

void Robotpart :: removemodel(){
    int decision;
    //printmodel();
    cout << "Which model would you like to remove? " << endl;
    cin >> decision;
    cin.ignore();
    
    modd[decision];
    modname[decision];
    sellingprice[decision];
    shippingcost[decision];
    totalcost[decision];
    
    modd.erase(modd.begin() + decision);
    modname.erase(modname.begin() + decision);
    sellingprice.erase(sellingprice.begin() + decision);
    shippingcost.erase(shippingcost.begin() + decision);
    totalcost.erase(totalcost.begin() + decision);
    
    cout << "Model Removed!" << endl;
}

void Robotpart :: printmodel(){
    cout << "=====" << modd.size() << " Total Models!=====" << endl;
    
    for(int i = 0; i < modd.size(); i++)
    {
        cout << "Model Name: " << modname[i] << endl;
        cout << "Model Description: " << modd[i] << endl;
        cout << "Model Price: $" << sellingprice[i] << endl;
        cout << "Shipping Cost: $" << shippingcost[i] << endl;
        cout << "------------------------------------" << endl;
    }
}

void Robotpart :: givedata(){
    torso.store("Torso","Torso 200",1234,35.4,43.2,"This is a Torso");
    torso.store("Torso","Torso 300",12341,43.2,62.2,"This is another Torso");
    torso.store("Torso","Torso 400",12342,54.4,65.3,"This is another Torso");
    
    head.store("Head","Head 200",3223,56.3,32.2,"This is a Head");
    head.store("Head","Head 300",3224,43.3,43.4,"This is another Head");
    head.store("Head","Head 400",3225,23.2,54.3,"This is another Head");
    
    arm.store("Arm","Left Arm 200",4223,32.2,56.5,"This is a left Arm");
    arm.store("Arm","Right Arm 200",4223,32.2,56.5,"This is a right Arm");
    
    locomotor.store("Locomotor","Locomotor 200",5223,65.3,76.4,"This is a locomotor");
    locomotor.store("Locomotor", "Locomotor 300",5223,32.2,56.5,"This is another locomotor");
    
    battery.store("Battery","AA battery",6223,5.32,5.5,"This is a AA battery");
    battery.store("Battery","AAA battery",6224,5.32,5.4,"This is a AAA battery");
    
}
