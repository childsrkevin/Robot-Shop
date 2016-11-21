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
int sales_View(Fl_Widget* w, void* p);
int customer_View(Fl_Widget* w, void* p);



class Robot_Part;
class Robot_Part_Dialog;
class Robot_Model;
class Robot_Model_Dialog;
class Customer_Dialog;
class SalesAssociate_Dialog;
//shop shop;

//
// Widgets
//

Fl_Window *win,*custReports, *saReports,*models, *catalog, *order;
Fl_Menu_Bar *menubar;
Fl_Box *box;
Robot_Part_Dialog *robot_part_dlg; // The dialog of interest!
Robot_Model_Dialog *robot_model_dlg;
Customer_Dialog *cust_dlg;
SalesAssociate_Dialog *sa_dlg;

//
//Robot Part Class
//

class Robot_Part{
public:
    vector <string> name;
    vector <string> number;
    vector <string> type;
    vector <string> weight;
    vector <string> cost;
    vector <string> description;
};

class Robot_Model{
public:
    vector <string> name;
    vector <string> number;
    vector <string> head;
    vector <string> arm;
    vector <string> locomotor;
    vector <string> battery;
};

Robot_Part part;
Robot_Model model;

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
        
        rm_torso = new Fl_Input(120, 130, 210, 25, "Torso to Use");
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
        //        sa_create->callback((Fl_Callback *)create_saCB, 0);
        
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

int customer_View(Fl_Widget* w, void* p) {
    const int X = 660;
    const int Y = 500;
    const int border = 10;
    
    custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Customer List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    // buff->text(testing);
    
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
    
    Fl_Text_Buffer *buff = new Fl_Text_Buffer();
    Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Sales Associate List");
    disp->buffer(buff);
    win->resizable(*disp);
    win->show();
    // buff->text(testing);
    
    // Wrap it up and let FLTK do its thing
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
 
 }
 */
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
    { "All Customers", 0, (Fl_Callback *)customer_View },
    { "All Sales Associates", 0, (Fl_Callback *)sales_View, 0, FL_MENU_DIVIDER  },
    { "All Robot Models", 0, (Fl_Callback *)CB },
    { "All Robot Parts", 0, (Fl_Callback *)CB },
    { 0 },
    { "&Help", 0, 0, 0, FL_SUBMENU },
    { "&Manual", 0, (Fl_Callback *)CB},
    { "&About", 0, (Fl_Callback *)CB},
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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Controller::cli()
{
    int cmd = -1;
    s.ez();
    while (cmd != 0)
    {
        view.show_menu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore();
        if(cmd>4)
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        execute_cmd(cmd);
    }
}
void Controller::execute_cmd(int cmd)
{
    int choice=0;
    string input;
    
    if(cmd == 1)//go to pm
    {
        pm.menu();
    }
    else if(cmd == 2)
    {
        int x=3;
        string input,a = "";
        while(x >2 || x <1)
        {
        view.customer_menu();
        cin>>x;
        cin.ignore();
        if(x==1)
        {
            cout<<"Enter Your Name: ";
            getline(cin,a);
            
            c.input_name1(a);
        }
        else if(x==2)
        {
            int b=0;
            while(b!=2)
            {
            cout<<"Enter your name: ";
            getline(cin,a);
            b=c.login(a);
            
            if(b==1)
            {
                cout<<'\n'<<a<<" is logged in"<<'\n';
                break;
            }
            else
            {
                cout<<'\n'<<"Customer is not on file"<<'\n';
                x=3;
                break;
            }
            }

        }
        else if(x==0)
        {
            break;
        }
        else
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
        while(x!=0)
        {
            c.print_menu2();
            cin>> x;
            cin.ignore();
            if(x==1)
            {
                pm.printmodels();
            }
            else if(x==2)
            {
                s.print_cus_order(a);
            }
            else if(choice !=0 && (choice>2|| choice<0))
            {
                cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
            }
        }
    }
    
    else if(cmd == 3)
    {
        choice=3;
        while(choice >2 || choice <1)
        {
        view.sales_menu();
        cin>> choice;
        cin.ignore();
        
        if (choice == 1)
        {
            cout<<"Enter Your Name: ";
            getline(cin,input);
            s.input_name1(input);
        }
        else if(choice == 2)
        {
            int b=0;
            while(b!=2)
            {
            cout<<"Enter Your Name: ";
            getline(cin,input);
            b=s.login(input);
            if(b==1)
            {
                cout<<'\n'<<input<<" is logged in"<<'\n';
                break;
            }
            else
            {
               cout<<'\n'<<"Seller is not on file"<<'\n';
                choice=3;
                break;
            }
            }
        }
        else
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
        while(choice!=0)
        {
            s.menu2();
            cin>> choice;
            cin.ignore();
            if(choice==1)
            {
                pm.printmodels();
                s.create_order(input);
            }
            else if(choice==2)
            {
                s.print_order(input);
            }
            else if(choice !=0 && (choice>2|| choice<0))
            {
                cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
            }
            
        }
    }
    else if(cmd == 4)
    {
        int choice=1;
        while(choice !=0)
        {
        view.boss_menu();
        cin>>choice;
        cin.ignore();
        
        if(choice==1)
        {
            vector<string> models=pm.return_mod_name();
            vector<double> price=pm.return_mod_price();
            vector<double> total_cost=pm.return_mod_totalcost();
            b.mp(models, price, total_cost);
            
        }
        else if(choice==2)
        {
            vector<string> models=pm.return_mod_name();
            vector<string> modnamesold = s.return_model_name();
            b.totalsold(models, modnamesold);
        }
        else if(choice==3)
        {
            s.print_all_orders();
        }
        else if(choice ==4)
        {
            vector<string> seller = s.return_seller();
            vector<string> quantity_sold= s.return_quantity_sold();
            b.salesass(seller,quantity_sold);
        }
        else if(choice !=0 && (choice>4|| choice<0))
        {
            cerr << "\n**Invalid command**\n*****Try Again*****" << endl;
        }
        }
    }
}
