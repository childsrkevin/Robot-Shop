#include"View.h"
#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Box.H>

using namespace std;

bool View :: saved(){
    return !dirty;
}
