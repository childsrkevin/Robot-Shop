#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "PM.h"
#include "Database.h"
#include "View.h"
#include "customer.h"
#include "SA.h"
#include "boss.h"


class Controller {
public:
    Controller(Database& data) : database(data), view(View(database)) {}
    void cli();
    void execute_cmd(int cmd);
private:
    boss b;
    PM pm;
    customer c;
    Database& database;
    SA s;
    View view;
};
#endif
