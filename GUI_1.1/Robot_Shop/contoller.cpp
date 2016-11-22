#include"controller.h"
#include "customer.h"
#include "View.h"
#include "Database.h"
#include "PM.h"
#include "SA.h"

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
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
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
void create_custCB(Fl_Widget* w, void* p);
void cancel_custCB(Fl_Widget* w, void* p);
void create_saCB(Fl_Widget* w, void* p);
void cancel_saCB(Fl_Widget* w, void* p);
int sales_View(Fl_Widget* w, void* p);
int customer_View(Fl_Widget* w, void* p);
int model_View(Fl_Widget* w, void* p);
int part_View(Fl_Widget* w, void* p);
int manual_View(Fl_Widget* w, void* p);
int order_View(Fl_Widget* w, void* p);
void menu_create_prepCB(Fl_Widget* w, void* p);
void menu_create_orderCB(Fl_Widget* w, void* p);
void create_orderCB(Fl_Widget* w, void* p);
void cancel_orderCB(Fl_Widget* w, void* p);
int order_View(Fl_Widget* w, void* p);
void cancel_prepCB(Fl_Widget* w, void* p);


class Robot_Part;
class Robot_Part_Dialog;
class Robot_Model;
class Robot_Model_Dialog;
class Customer_Dialog;
class SalesAssociate_Dialog;
class Order_Dialog;
class Prep_Dialog;

//shop shop;

//
// Widgets
//

Fl_Window *win,*custReports, *saReports,*models, *catalogi/*, *order*/;
Fl_Menu_Bar *menubar;
Fl_Box *box;
Robot_Part_Dialog *robot_part_dlg; // The dialog of interest!
Robot_Model_Dialog *robot_model_dlg;
Customer_Dialog *cust_dlg;
SalesAssociate_Dialog *sa_dlg;
Order_Dialog *o_dlg;
Prep_Dialog *p_dlg;

//
//Robot Part Class
//


class Order{
public:
    vector <string> name;
    vector <string> number;
    vector <string> date;
    vector <string> saname;
    vector <string> rname;
    vector <string> cost;
};

Order o;

class Robot_Part{
public:
    vector <string> name;
    vector <string> number;
    vector <string> type;
    vector <string> weight;
    vector <string> cost;
    vector <string> description;
   
    void pop(){
    name.push_back("Head1");
    name.push_back("Arm1");
    name.push_back("Torso1");
    name.push_back("Locomotor1");
    name.push_back("battery1");

    number.push_back("123");
    number.push_back("124");
    number.push_back("125");
    number.push_back("126");
    number.push_back("127");

    type.push_back("Head");
    type.push_back("Arm");
    type.push_back("Torso");
    type.push_back("Locomotor");
    type.push_back("battery");

    weight.push_back("12.4");
    weight.push_back("12.5");
    weight.push_back("20.3");
    weight.push_back("16.4");
    weight.push_back("17.4");

    cost.push_back("42.4");
    cost.push_back("54.5");
    cost.push_back("21.3");
    cost.push_back("16.4");
    cost.push_back("54.3");

    description.push_back("This is a head part");
    description.push_back("This is a arm part");
    description.push_back("This is a torso part");
    description.push_back("This is a locomotor part");
    description.push_back("This is a battery part");

    }

};

class Robot_Model{
public:
    vector <string> name;
    vector <string> number;
    vector <string> head;
    vector <string> arm;
    vector <string> locomotor;
    vector <string> battery;
    vector <string> price;
};

Robot_Part part;
Robot_Model model;

//
// Robot Part dialog
//


class Prep_Dialog{
public:
     Prep_Dialog(){

//       part.pop();
       
       dialog = new Fl_Window(340,150, "Prepopulation");
  
       box = new Fl_Box(20,40,300,100,"Prepopulation Complete!");
  
       p_cancel = new Fl_Button(270, 110, 60, 25, "OK");
       p_cancel->callback((Fl_Callback *)cancel_prepCB, 0);



        dialog->end();
        dialog->set_non_modal();
    }

    void show() {dialog->show();}
    void hide() {dialog->hide();}
    

private:
    Fl_Window *dialog;
    Fl_Button *p_cancel;
    Fl_Box *box;
   
};

Prep_Dialog prep;

class Order_Dialog {
public:
      Order_Dialog() {
        dialog = new Fl_Window(340, 270, "Orders");

        o_name = new Fl_Input(120, 10, 210, 25, "Customer Name:");
        o_name->align(FL_ALIGN_LEFT);

        o_number = new Fl_Input(120, 40, 210, 25, "Order Number:");
        o_number->align(FL_ALIGN_LEFT);

        o_date = new Fl_Input(120, 70, 210, 25, "Date:");
        o_date->align(FL_ALIGN_LEFT);

        o_r_name = new Fl_Input(120, 100, 210, 25, "Robot Name:");
        o_r_name->align(FL_ALIGN_LEFT);

        o_cost = new Fl_Input(120, 130, 210, 25, "Price:");
        o_cost->align(FL_ALIGN_LEFT);

        o_sa = new Fl_Multiline_Input(120, 160, 210, 75, "Sales Assistant:");
        o_sa->align(FL_ALIGN_LEFT);

        o_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
        o_create->callback((Fl_Callback *)create_orderCB, 0);

        o_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
        o_cancel->callback((Fl_Callback *)cancel_orderCB, 0);

        dialog->end();
        dialog->set_non_modal();
    }

    void show() {dialog->show();}
    void hide() {dialog->hide();}
    string name() {return o_name->value();}
    string number() {return o_number->value();}
    string date() {return o_date->value();}
    string r_name() {return o_r_name->value();}
    string cost() {return o_cost->value();}
    string sa_name() {return o_sa->value();}

private:
    Fl_Window *dialog;
    Fl_Input *o_name;
    Fl_Input *o_number;
    Fl_Input *o_date;
    Fl_Input *o_r_name;
    Fl_Input *o_cost;
    Fl_Input *o_sa;
    Fl_Return_Button *o_create;
    Fl_Button *o_cancel;
};


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
        
        rm_torso = new Fl_Input(120, 130, 210, 25, "Torso to Use");
        rm_torso->align(FL_ALIGN_LEFT);
        
        rm_battery= new Fl_Input(120, 170, 210, 25, "Battery to Use");
        rm_battery->align(FL_ALIGN_LEFT);
        
        rm_price = new Fl_Input(120, 210, 210, 25, "Price");
        rm_price->align(FL_ALIGN_LEFT);
        
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
    string price(){return rm_price->value();}
    
private:
    Fl_Window *dialog;
    Fl_Input *rm_name;
    Fl_Input *rm_model_number;
    Fl_Input *rm_head;
    Fl_Input *rm_arm;
    Fl_Input *rm_torso;
    Fl_Input *rm_battery;
    Fl_Input *rm_price;
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
        sa_create->callback((Fl_Callback *)create_saCB, 0);
        
        sa_cancel = new Fl_Button(270, 100, 60, 25, "Cancel");
        sa_cancel->callback((Fl_Callback *)cancel_saCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string SA_name() { return sa_name->value(); }
    vector <string> name;
private:
    Fl_Window *dialog;
    Fl_Input *sa_name;
    
    Fl_Return_Button *sa_create;
    Fl_Button *sa_cancel;
};

SalesAssociate_Dialog sales;

class Customer_Dialog {
public:
    Customer_Dialog() {
        
        dialog = new Fl_Window(340, 150, "Customer");
        
        c_name = new Fl_Input(120, 10, 210, 25, "Name:");
        c_name->align(FL_ALIGN_LEFT);
        
        c_create = new Fl_Return_Button(145, 120, 120, 25, "Create");
        c_create->callback((Fl_Callback *)create_custCB, 0);
        
        c_cancel = new Fl_Button(270, 120, 60, 25, "Cancel");
        c_cancel->callback((Fl_Callback *)cancel_custCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
    }
    
    void show() { dialog->show(); }
    void hide() { dialog->hide(); }
    string cust_name() { return c_name->value(); }
    vector <string> name;
private:
    Fl_Window *dialog;
    Fl_Input *c_name;
    
    Fl_Return_Button *c_create;
    Fl_Button *c_cancel;
};

Customer_Dialog customer;

//
// Callbacks
//

int customer_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    int i = 0,j=0; 
    string temp;    
    char* temp1;

    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Customer List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    for(i = 0; i < customer.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + customer.name[i] + "\n";
    }
    temp1 = new char[temp.length() + 1];
    strcpy(temp1,temp.c_str());
    buff->text(temp1);
    
    // Wrap it up and let FLTK do its thing
    custReports->end();
    custReports->show();
    return(Fl::run());
}



int model_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    int i = 0,j=0;
    string temp;
    char* temp1;

    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Model List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    for(i = 0; i < model.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + model.name[i] + ", Price: " + model.price[i] + "\n";
    }
    temp1 = new char[temp.length() + 1];
    strcpy(temp1,temp.c_str());
    buff->text(temp1);

    // Wrap it up and let FLTK do its thing
    custReports->end();
    custReports->show();
    return(Fl::run());
}


int order_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    int i = 0,j=0;
    string temp;
    char* temp1;

    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Order List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    for(i = 0; i < o.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + o.name[i] + ", Date: "+  o.date[i] +", Price: " + o.cost[i] + ", Sales Assistant: " + o.saname[i] + "\n";
    }
    temp1 = new char[temp.length() + 1];
    strcpy(temp1,temp.c_str());
    buff->text(temp1);

    // Wrap it up and let FLTK do its thing
    custReports->end();
    custReports->show();
    return(Fl::run());
}




int manual_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    int i = 0,j=0;
    string temp;
    char* temp1;

    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Manual");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    /*for(i = 0; i < model.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + model.name[i] + ", Price: " + model.price[i] + "\n";
    }*/
    //temp1 = new char[temp.length() + 1];
    //strcpy(temp1,temp.c_str());
    buff->text("Prepopulate - Will add premade parts\nCreate Order - Will create an order for a robot model\nCreate Customer - Will create a customer\nCreate Sales Associate -  Will create a sales associate\nCreate Robot Part - Will Create a robot part in the robot shop\nCreate Robot Model - Will create a model using created robot parts\nReport All Orders - Will Print all Orders created\nReport All Customers - Will Print all Customers created\nReport All Sales Associates - Will print all Sales Associates Created\nReport All Robot Models - Will print all Robot Models created\nReport All Robot Parts - Will print all Robot Parts created\n");

    // Wrap it up and let FLTK do its thing
    custReports->end();
    custReports->show();
    return(Fl::run());
}

int part_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    int i = 0,j=0;
    string temp;
    char* temp1;

    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Part List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    for(i = 0; i < part.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + part.name[i] + ", Type: " + part.type[i] + ", Price: " + part.cost[i] + "\n";
    }

    temp1 = new char[temp.length() + 1];
    strcpy(temp1,temp.c_str());
    buff->text(temp1);

    // Wrap it up and let FLTK do its thing
    custReports->end();
    custReports->show();
    return(Fl::run());
}


int sales_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    
    saReports = new Fl_Window{ X, Y, "Robot Shoppe" };

    int i;
    string temp;
    char* temp1;
    

    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Sales Associate Names");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    // buff->text(testing);
    
    // Wrap it up and let FLTK do its thing

    for(i = 0; i < sales.name.size();i++)
    {
         cout << i << endl;
         temp = temp + "Name: " + sales.name[i] + "\n";
    }

   temp1 = new char[temp.length() + 1];
    strcpy(temp1,temp.c_str());

    buff->text(temp1);
    saReports->end();
    saReports->show();
    return(Fl::run());
}
void CB(Fl_Widget* w, void* p) { } // No action

void menu_create_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->show();
}
void menu_create_robot_modelCB(Fl_Widget* w, void* p){
    robot_model_dlg->show();
}

void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
    
    string temp;
    cout << "### Creating robot part" << endl;
    cout << "Name    : " << robot_part_dlg->name() << endl;
    cout << "Part #  : " << robot_part_dlg->part_number() << endl;
    cout << "Type    : " << robot_part_dlg->type() << endl;
    cout << "Weight  : " << robot_part_dlg->weight() << endl;
    cout << "Cost    : " << robot_part_dlg->cost() << endl;
    cout << "Descript: " << robot_part_dlg->description() << endl;
    
    temp = robot_part_dlg->name();
    part.name.push_back(temp);
    
    temp = robot_part_dlg->part_number();
    part.number.push_back(temp);
    
    temp = robot_part_dlg->type();
    part.type.push_back(temp);
    
    temp = robot_part_dlg->weight();
    part.weight.push_back(temp);
    
    temp = robot_part_dlg->cost();
    part.cost.push_back(temp);
    
    temp = robot_part_dlg->description();
    part.description.push_back(temp);
    
    robot_part_dlg->hide();
}

void cancel_robot_partCB(Fl_Widget* w, void* p) {
    robot_part_dlg->hide();
}

void create_robot_modelCB(Fl_Widget* w, void* p){
    string temp;
    cout << "### Creating robot model" << endl;
    cout << "Model Name    : " << robot_model_dlg->name() << endl;
    cout << "Model #  : " << robot_model_dlg->number() << endl;
    cout << "Head    : " << robot_model_dlg->head() << endl;
    cout << "Arm  : " << robot_model_dlg->arm() << endl;
    cout << "Torso    : " << robot_model_dlg->torso() << endl;
    cout << "Battery: " << robot_model_dlg->battery() << endl;
    
    temp = robot_model_dlg->name();
    model.name.push_back(temp);
    
    temp = robot_model_dlg->number();
    model.number.push_back(temp);
    
    temp = robot_model_dlg->head();
    model.head.push_back(temp);
    
    temp = robot_model_dlg->arm();
    model.arm.push_back(temp);
    
    temp = robot_model_dlg->torso();
    model.locomotor.push_back(temp);
    
    temp = robot_model_dlg->battery();
    model.battery.push_back(temp);
   
    temp = robot_model_dlg->price();
    model.price.push_back(temp);
    
    
    robot_model_dlg->hide();
    
}

void create_custCB(Fl_Widget* w, void* p)
 {
 
    string temp;
    cout << "### Storing Name" << endl;
    cout << "Customer Name    : " << cust_dlg->cust_name() << endl;

    temp = cust_dlg->cust_name();
    customer.name.push_back(temp);

 cust_dlg->hide();
 
 }


void create_saCB(Fl_Widget* w, void* p)
 {
  string temp;
    cout << "### Storing Name" << endl;
    cout << "Customer Name    : " << sa_dlg->SA_name() << endl;

    temp = sa_dlg->SA_name();
    sales.name.push_back(temp); 


 sa_dlg->hide();
 
 }
 
void cancel_robot_modelCB(Fl_Widget* w, void* p){
    robot_model_dlg->hide();
}
void menu_create_custCB(Fl_Widget* w, void* p) {
    cust_dlg->show();
}
void menu_create_orderCB(Fl_Widget* w, void* p){
   o_dlg->show();
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





void create_orderCB(Fl_Widget* w, void* p){
    string temp;
    cout << "### Creating order" << endl;
    cout << "Customer Name    : " << o_dlg->name() << endl;
    cout << "Order #  : " << o_dlg->number() << endl;
    cout << "Date  : " << o_dlg->date() << endl;
    cout << "Robot Name  : " << o_dlg->r_name() << endl;
    cout << "Price    : " << o_dlg->cost() << endl;
    cout << "Sales Assistant Name: " << o_dlg->sa_name() << endl;
    temp = o_dlg->name();
    o.name.push_back(temp);

    temp = o_dlg->number();
    o.number.push_back(temp);
    temp = o_dlg->date();
    o.date.push_back(temp);

    temp = o_dlg->r_name();
    o.rname.push_back(temp);

    temp = o_dlg->cost();
    o.cost.push_back(temp);

    temp = o_dlg->sa_name();
    o.saname.push_back(temp);


    o_dlg->hide();
}
void cancel_orderCB(Fl_Widget* w, void* p){
  o_dlg->hide();
}
void menu_create_prepCB(Fl_Widget* w, void* p){
  part.pop();
  p_dlg->show();
}
//
// Menu
//

Fl_Menu_Item menuitems[] = {
    { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Pre-Populate", FL_ALT + 'q', (Fl_Callback *)menu_create_prepCB },
    { 0 },
    { "&Create", 0, 0, 0, FL_SUBMENU },
    { "Order", 0, (Fl_Callback *)menu_create_orderCB, 0, FL_MENU_DIVIDER},
    { "Customer", 0, (Fl_Callback *)menu_create_custCB},
    { "Sales Associate", 0, (Fl_Callback *)menu_create_saCB, 0, FL_MENU_DIVIDER  },
    { "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
    { "Robot Model", 0, (Fl_Callback *)menu_create_robot_modelCB},
    { 0 },
    { "&Report", 0, 0, 0, FL_SUBMENU },
    { "All Orders", 0, (Fl_Callback *)order_View },
    { "All Customers", 0, (Fl_Callback *)customer_View },
    { "All Sales Associates", 0, (Fl_Callback *)sales_View, 0, FL_MENU_DIVIDER  },
    { "All Robot Models", 0, (Fl_Callback *)model_View },
    { "All Robot Parts", 0, (Fl_Callback *)part_View },
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "&Manual", 0, (Fl_Callback *)manual_View},
    { 0 },
    { 0 }
};

int Controller::gui()
{
    const int X = 560;
    const int Y = 420;
    
    // Create dialogs

    

    robot_part_dlg = new Robot_Part_Dialog{};
    robot_model_dlg = new Robot_Model_Dialog{};
    cust_dlg = new Customer_Dialog{};
    sa_dlg = new SalesAssociate_Dialog{};
    o_dlg = new Order_Dialog{};
    p_dlg = new Prep_Dialog{};
    
    // Create a window
    win = new Fl_Window{X, Y, "Robbie Robot Shop Manager"};
    win->color(FL_BLACK);
    
    // Install menu bar
    menubar = new Fl_Menu_Bar(0, 0, X, 30);
    menubar->menu(menuitems);
    
    // Wrap it up and let FLTK do its thing
    win->end();
    win->show();
    return(Fl::run());
}

void cancel_prepCB(Fl_Widget* w, void* p){
     p_dlg->hide();
}
