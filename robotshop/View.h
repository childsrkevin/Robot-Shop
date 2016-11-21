#ifndef _View_H
#define _View_H 201610
#include<FL/Fl.H>
#include<FL/Fl_Box.H>
#include<vector>

using namespace std;

class View : public Fl_Box{
    bool dirty = false;
    public:
//call base instructor
View(int X, int Y, int W, int H) : Fl_Box(X, Y, W, H) { }


bool saved();
};

#endif
