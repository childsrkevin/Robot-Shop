#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>
#include"View.h"
#include<FL/Fl_Menu_Bar.H>
#include<FL/fl_ask.H>


Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;


void CloseCB(Fl_Widget* w, void* p){
    int selection = 1;
    if (!view->saved())
       selection = fl_choice("Changes unsaved. Exit anyway?", fl_no, fl_yes, 0);

    if(selection == 1)
       win->hide();
}

Fl_Menu_Item menuitems[] = {
    {"&File",0,0,0, FL_SUBMENU},
    {"&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
    { 0 },
    {"&Product Manager",0,0,0, FL_SUBMENU},
    {"&Create a Part"},
    {"&Remove a Part"},
    {"&Create a Model"},
    {"&Remove a Model"},
    {"&Print all Parts"},
    {"&Print all Models"},
    { 0 },
    {"&Beloved Customer",0,0,0, FL_SUBMENU},
    {"&View Models"},
    {"&View your Orders"},
    {0},
    {"&Sales Assosiate",0,0,0, FL_SUBMENU},
    {"&Make a Sale"},
    {"&View Orders"},
    {0},
    {"&Boss",0,0,0, FL_SUBMENU},
    {"&Models Sold"},
    {"&Assosiate Perf"},
    {"&Profit"},
    {0},
    {0}
    
    
};

int main(){
    const int X = 640;
    const int Y = 480;
//create a window
    win = new Fl_Window{X, Y, "Robbie Robot Shop"};
    win->color(FL_BLACK);
//install menubar
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);
//create a view
    view = new View{0, 0, X, Y};
//sign up for callback
    win->callback(CloseCB, view);
//enable resizing
    win->resizable(*view);
//wrap it up and let FLTK do its thing
    win->end();
    win->show();
    return(Fl::run());
}


