#ifndef _VIEW_H
#define _VIEW_H

#include"Database.h"

class View {
	public:
		View(Database& data) : database(data) {}
		void show_menu();
                //void show_PM_menu();
		/*void show_BC_menu();
                void show_SA_menu();
                void show_PB_menu();*/
		void list_parts();
	private:
		Database& database;
};

#endif
