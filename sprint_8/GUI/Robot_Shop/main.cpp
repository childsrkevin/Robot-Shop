#include<iostream>
#include "Database.h"
#include "controller.h"
using namespace std;

int main()
{
    Database database;
    Controller controller(database);
    controller.gui();
    return 0;
}

