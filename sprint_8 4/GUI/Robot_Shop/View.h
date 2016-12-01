#ifndef _VIEW_H
#define _VIEW_H

#include"Database.h"

class View {
public:
    View(Database& data) : database(data) {}
    void show_menu();
    void list_parts();
    void sales_menu();
    void customer_menu();
    void boss_menu();
private:
    Database& database;
};

#endif
