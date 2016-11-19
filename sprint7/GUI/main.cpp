#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>
//#include "shop.h"

using namespace std;

//
// Declarations (we'll define later, just need to declare some variables!)
//
void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
void create_robot_modelCB(Fl_Widget* w, void* p);
void cancel_robot_modelCB(Fl_Widget* w, void* p);
void menu_create_robot_modelCB(Fl_Widget* w, void* p);
//void create_custCB(Fl_Widget* w, void* p);
void cancel_custCB(Fl_Widget* w, void* p);
//void create_saCB(Fl_Widget* w, void* p);
void cancel_saCB(Fl_Widget* w, void* p);

class Robot_Part_Dialog;
class Robot_Model_Dialog;
class Customer_Dialog;
class SalesAssociate_Dialog;

//shop shop;

//
// Widgets
//

Fl_Window *win,*custReports, *saReports;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg; // The dialog of interest!
Robot_Model_Dialog *robot_model_dlg;
Customer_Dialog *cust_dlg;
SalesAssociate_Dialog *sa_dlg;

//
// Robot Part dialog
//
class Robot_Model_Dialog{
public:
    Robot_Model_Dialog(){
        dialog = new Fl_Window(340, 270, "Robot Model");
        
        rm_name = new Fl_Input(120, 10, 210, 25, "Model Name: ");
        rm_name->align(FL_ALIGN_LEFT);
        
        rm_model_number = new Fl_Input(120, 40, 210, 25, "Model Number");
        rm_model_number->align(FL_ALIGN_LEFT);
        
        rm_head = new Fl_Input(120, 70, 210, 25, "Head to Use");
        rm_head->align(FL_ALIGN_LEFT);
        
        rm_arm = new Fl_Input(120, 100, 210, 25, "Arm to Use");
        rm_arm->align(FL_ALIGN_LEFT);
        
        rm_torso = new Fl_Input(120, 130, 210, 25, "Locomotor to Use");
        rm_torso->align(FL_ALIGN_LEFT);
        
        rm_battery= new Fl_Input(120, 170, 210, 25, "Battery to Use");
        rm_battery->align(FL_ALIGN_LEFT);
        
        rm_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rm_create->callback((Fl_Callback *)create_robot_modelCB, 0);
        
        rm_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rm_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rm_name->value();}
    string number() {return rm_model_number->value();}
    string head() {return rm_head->value();}
    string arm() {return rm_arm->value();}
    string torso() {return rm_torso->value();}
    string battery() {return rm_battery->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rm_name;
    Fl_Input *rm_model_number;
    Fl_Input *rm_head;
    Fl_Input *rm_arm;
    Fl_Input *rm_torso;
    Fl_Input *rm_battery;
    Fl_Return_Button *rm_create;
    Fl_Button *rm_cancel;
};

class Robot_Part_Dialog {
public:
    Robot_Part_Dialog() {
        dialog = new Fl_Window(340, 270, "Robot Part");
        
        rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
        rp_name->align(FL_ALIGN_LEFT);
        
        rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
        rp_part_number->align(FL_ALIGN_LEFT);
        
        rp_type = new Fl_Input(120, 70, 210, 25, "Type:");
        rp_type->align(FL_ALIGN_LEFT);
        
        rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
        rp_weight->align(FL_ALIGN_LEFT);
        
        rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
        rp_cost->align(FL_ALIGN_LEFT);
        
        rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
        rp_description->align(FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
        
        rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return rp_name->value();}
    string part_number() {return rp_part_number->value();}
    string type() {return rp_type->value();}
    string weight() {return rp_weight->value();}
    string cost() {return rp_cost->value();}
    string description() {return rp_description->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_part_number;
    Fl_Input *rp_type;
    Fl_Input *rp_weight;
    Fl_Input *rp_cost;
    Fl_Input *rp_description;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
};

class SalesAssociate_Dialog {
public:
    SalesAssociate_Dialog() {
        
        dialog = new Fl_Window(340, 130, "Sales Associate");
        
        sa_name = new Fl_Input(120, 10, 210, 25, "Name:");
        sa_name->align(FL_ALIGN_LEFT);
        
        sa_create = new Fl_Return_Button(145, 100, 120, 25, "Create");
       // sa_create->callback((Fl_Callback *)create_saCB, 0);
        
        sa_cancel = new Fl_Button(270, 100, 60, 25, "Cancel");
        sa_cancel->callback((Fl_Callback *)cancel_saCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string SA_name() { return sa_name->value(); }
    
private:
    Fl_Window *dialog;
    Fl_Input *sa_name;
    
    Fl_Return_Button *sa_create;
    Fl_Button *sa_cancel;
};

class Customer_Dialog {
public:
    Customer_Dialog() {
        
        dialog = new Fl_Window(340, 150, "Customer");
        
        c_name = new Fl_Input(120, 10, 210, 25, "Name:");
        c_name->align(FL_ALIGN_LEFT);

        c_create = new Fl_Return_Button(145, 120, 120, 25, "Create");
        //c_create->callback((Fl_Callback *)create_custCB, 0);
        
        c_cancel = new Fl_Button(270, 120, 60, 25, "Cancel");
        c_cancel->callback((Fl_Callback *)cancel_custCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string cust_name() { return c_name->value(); }
    
private:
    Fl_Window *dialog;
    Fl_Input *c_name;
    
    Fl_Return_Button *c_create;
    Fl_Button *c_cancel;
};

//
// Callbacks
//

void CB(Fl_Widget* w, void* p) { } // No action

void menu_create_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->show();
}
void menu_create_robot_modelCB(Fl_Widget* w, void* p){
    robot_model_dlg->show();
}

void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
    cout << "### Creating robot part" << endl;
    cout << "Name    : " << robot_part_dlg->name() << endl;
    cout << "Part #  : " << robot_part_dlg->part_number() << endl;
    cout << "Type    : " << robot_part_dlg->type() << endl;
    cout << "Weight  : " << robot_part_dlg->weight() << endl;
    cout << "Cost    : " << robot_part_dlg->cost() << endl;
    cout << "Descript: " << robot_part_dlg->description() << endl;
    robot_part_dlg->hide();
}

void cancel_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->hide();
}

void create_robot_modelCB(Fl_Widget* w, void* p){
    cout << "### Creating robot model" << endl;
    cout << "Model Name    : " << robot_model_dlg->name() << endl;
    cout << "Model #  : " << robot_model_dlg->number() << endl;
    cout << "Head    : " << robot_model_dlg->head() << endl;
    cout << "Arm  : " << robot_model_dlg->arm() << endl;
    cout << "Torso    : " << robot_model_dlg->torso() << endl;
    cout << "Battery: " << robot_model_dlg->battery() << endl;
    robot_model_dlg->hide();
    
}
/*void create_custCB(Fl_Widget* w, void* p)
{
    shop.add_customer(new Customer(cust_dlg->cust_name(), cust_dlg->cust_number(), cust_dlg->sa_number()));
    
    cust_dlg->hide();
    
}
void create_saCB(Fl_Widget* w, void* p)
{
    shop.add_sa(new SalesAssociate(sa_dlg->SA_name(), sa_dlg->sa_number()));
    
    sa_dlg->hide();
    
}*/

void cancel_robot_modelCB(Fl_Widget* w, void* p){
    robot_model_dlg->hide();
}
void menu_create_custCB(Fl_Widget* w, void* p) {
    cust_dlg->show();
}
void menu_create_saCB(Fl_Widget* w, void* p) {
    sa_dlg->show();
}
void cancel_custCB(Fl_Widget* w, void* p) {
    cust_dlg->hide();
}
void cancel_saCB(Fl_Widget* w, void* p) {
    sa_dlg->hide();
}

//
// Menu
//

Fl_Menu_Item menuitems[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&New", FL_ALT + 'n', (Fl_Callback *)CB },
    { "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
    { "&Save", FL_ALT + 's', (Fl_Callback *)CB },
    { "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
    { "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
    { 0 },
    { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "&Undo", 0, (Fl_Callback *)CB },
    { "Cu&t", 0, (Fl_Callback *)CB },
    { "&Copy", 0, (Fl_Callback *)CB },
    { "&Paste", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "Customer", 0, (Fl_Callback *)menu_create_custCB},
    { "Sales Associate", 0, (Fl_Callback *)menu_create_saCB, 0, FL_MENU_DIVIDER  },
    { "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
    { "Robot Model", 0, (Fl_Callback *)menu_create_robot_modelCB },
    { 0 },
    { "&Report", 0, 0, 0, FL_SUBMENU },
    { "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "All Orders", 0, (Fl_Callback *)CB },
    { "Orders by Customer", 0, (Fl_Callback *)CB },
    { "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
    { "All Customers", 0, (Fl_Callback *)CB },
    { "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER  },
    { "All Robot Models", 0, (Fl_Callback *)CB },
    { "All Robot Parts", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "&Manual", 0, (Fl_Callback *)CB},
    { "&About", 0, (Fl_Callback *)CB},
    { 0 },
    { 0 }
};

//
// Main
//

int main() {
    const int X = 560;
    const int Y = 420;
    
    // Create dialogs
    robot_part_dlg = new Robot_Part_Dialog{};
    robot_model_dlg = new Robot_Model_Dialog{};
    cust_dlg = new Customer_Dialog{};
    sa_dlg = new SalesAssociate_Dialog{};
    
    // Create a window
    win = new Fl_Window{X, Y, "Robbie Robot Shop Manager"};
    win->color(FL_WHITE);
    
    // Install menu bar
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);
    
    // Wrap it up and let FLTK do its thing
    win->end();
    win->show();
    return(Fl::run());
}
