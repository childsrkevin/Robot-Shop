#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "PM.h"
#include "Database.h"
#include "View.h"
//#include "customer.h"

class Controller {
	public:
		Controller(Database& data) : database(data), view(View(database)) {}
		void cli();
		void execute_cmd(int cmd);
	private:
                PM pm;
		Database& database;
		View view;
};
#endif
