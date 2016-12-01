#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "PM.h"
#include "Database.h"
#include "View.h"
#include "customer.h"
#include "SA.h"
#include "boss.h"
#include <iostream>
#include <string>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Box.H>

using namespace std;


class Controller
{
public:
    Controller(Database& data) : database(data), view(View(database)) {}
    void cli();
    int gui();
    void execute_cmd(int cmd);
private:
    boss b;
    PM pm;
    customer c;
    Database& database;
    SA s;
    View view;
};
#endif /* _CONTROLLER_H */
