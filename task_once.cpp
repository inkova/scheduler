#include <iostream>
#include "task_once.h"

using std::endl;
using std::cout;

void Task_once::print() const {
	cout << "Task is called " << get_name() << " with data " << get_data() << ".\nIts importance is " << get_imp() << " and its time is " << get_time() << endl;
}

