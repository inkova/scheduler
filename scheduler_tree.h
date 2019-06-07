#ifndef SCHEDULER_TREE_H_
#define SCHEDULER_TREE_H_

#include "task.h"
#include <map>
#include <string>
#include <memory>
#include <utility>    //для пар
#include <iostream>

using std::multimap;
using std::shared_ptr;
using std::move;
using std::pair;       //для карты
using std::string;

class Scheduler {
private:
	multimap <int, shared_ptr<Task>> mmTask;   //создаём map с ключом string и значением shared_ptr<Task>

public:
	void insert(Task* task)
	{
		mmTask.insert(make_pair(task->get_time(), shared_ptr<Task>(task)));
	}

	void show();
	
	bool search(const string& name_task, multimap <int, shared_ptr<Task>> ::iterator & it);

	void clean() {
		mmTask.clear();
	};
	
	void delete_one_task(const string& name_task);
	void perform(const string& name_task);
	void print_first();

	~Scheduler() {
		clean();
	}
};
#endif
