#ifndef SCHEDULER_TREE_H_
#define SCHEDULER_TREE_H_

#include "task.h"
#include <map>
#include <string>
#include <memory>
#include <utility>    //для пар
#include <iostream>

using std::map;
using std::shared_ptr;
using std::move;
using std::pair;       //для карты
using std::string;

class Scheduler {
private:
	map <int, shared_ptr<Task>> mTask;   //создаём map с ключом string и значением shared_ptr<Task>

public:
	void insert(Task* task)
	{
		mTask.insert(make_pair(task->get_time(), shared_ptr<Task>(task)));
	}

	void show();
	
	void search(const string& name_task, Task *& result_of_search);

	void clean() {
		mTask.clear();
	};
	
	void delete_one_task(const string& name_task);
	void perform(const string& name_task);
	void print_first();

	~Scheduler() {
		clean();
	}
};
#endif
