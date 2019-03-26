#include <iostream>
#include "task_period.h"
using namespace std;

void Task_period::print() const {
	cout << "Task is called " << get_name() << " with data " << get_data() << ".\nIts importance is " << get_imp() << ", its time is " << get_time() << " and its period is " << period << ".\n";
}

