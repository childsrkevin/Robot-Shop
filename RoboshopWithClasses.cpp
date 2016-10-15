#include<iostream>
#include "Database.h"
#include "Controller.h"
using namespace std;

int main()
{
	Database database;
	Controller controller(database);
	controller.cli();
    return 0;
}

