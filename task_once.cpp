//#include <cstdio>
#include <iostream>
#include "task_once.h"
using namespace std;

void Task_once::print() const {
	//printf("Task is called  with data .\nIts importance is %i and its time is %i.\n", importance, time);
	cout << "Task is called " << get_name() << " with data " << get_data() << ".\nIts importance is " << get_imp() << " and its time is " << get_time() <<".\n";
}

