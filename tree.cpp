
#include <iostream>
#include "scheduler_tree.h"
#include "task.h"
#include "task_period.h"
#include "task_once.h"

using std::string;
using std::endl;
using std::cout;

void Scheduler::perform(const string& name_task) {
	Task * result_of_search = nullptr, *tmp = nullptr;
	bool check=false;
	
	search(name_task, result_of_search);
	if (result_of_search != nullptr) {
		cout << "\nCompleted task:\n";
		result_of_search->print();
	}
	else {
		cout << "\nTask with name " << name_task << " not found." << endl;
		return;
	}

	tmp = result_of_search->clone();
	check= tmp->miss();
	delete_one_task(name_task);
	if(check) insert(tmp);
	else  delete tmp;

	return;
}

void Scheduler::print_first() {
	map <int, shared_ptr<Task>> ::iterator it = mTask.begin();
	it->second->print();
	return;
}

void Scheduler::show() {
	map <int, shared_ptr<Task>> ::iterator it = mTask.begin();
	for (; it != mTask.end(); it++) {  // выводим их
		it->second->print();
	}
	return;
}

void Scheduler::search(const string& name_task, Task *& result_of_search) {
	result_of_search = nullptr;
	map <int, shared_ptr<Task>> ::iterator it = mTask.begin();
	for (; it != mTask.end(); it++) {  
		if (it->second->get_name()== name_task) {
			result_of_search = it->second.get();
			return;
		}
	}
	return;
}

void Scheduler::delete_one_task(const string& name_task) {
	Task * task_to_delete = nullptr;
	search(name_task, task_to_delete);
	if (task_to_delete == nullptr) {
		cout << "\nTask with name " << name_task << " not found." << endl;
		return;
	}
	mTask.erase(task_to_delete->get_time());
}