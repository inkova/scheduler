
#include <iostream>
#include "scheduler_tree.h"
#include "task.h"
#include "task_period.h"
#include "task_once.h"

using std::string;
using std::endl;
using std::cout;

void Scheduler::perform(const string& name_task) {
	Task  *tmp = nullptr;
	bool check=false;
	multimap <int, shared_ptr<Task>> ::iterator it = mmTask.end();

	if (search(name_task, it)) {
		cout << "\nCompleted task:\n";
		it->second->print();
	}
	else {
		cout << "\nTask with name " << name_task << " not found." << endl;
		return;
	}

	tmp = it->second->clone();
	check= tmp->miss();
	delete_one_task(name_task);
	if(check) insert(tmp);
	else  delete tmp;

	return;
}

void Scheduler::print_first() {
	multimap <int, shared_ptr<Task>> ::iterator it = mmTask.begin();
	int time;
	time = it->first;
	for (; (it != mmTask.end() && time == it->first); it++)
	{
		it->second->print();
	}
	return;
}

void Scheduler::show() {
	multimap <int, shared_ptr<Task>> ::iterator it = mmTask.begin();
	for (; it != mmTask.end(); it++) {  // выводим их
		it->second->print();
	}
	return;
}

bool Scheduler::search(const string& name_task, multimap <int, shared_ptr<Task>> ::iterator & it) {
	it = mmTask.begin();
	for (; it != mmTask.end(); it++) {  
		if (it->second->get_name()== name_task) {
			return true;
		}
	}
	return false;
}

void Scheduler::delete_one_task(const string& name_task) {
	multimap <int, shared_ptr<Task>> ::iterator it = mmTask.end();
	
	if (!(search(name_task,it))) {
		cout << "\nTask with name " << name_task << " not found." << endl;
		return;
	}
	mmTask.erase(it);
	return;
}
