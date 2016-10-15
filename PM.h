#include"Database.h"
#include "View.h" 
#include "Controller.h"
#include "Part.h"
#ifndef _PM_H
#define _PM_H

class PM{
    public:
        void pm_menu();
        Part pm_cmd(int cmd);
    private:
       //Controller controller;
       //Part part;
};

#endif //_PM_H
