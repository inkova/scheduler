#ifndef SCHEDULER_TREE_H_
#define SCHEDULER_TREE_H_

#include "task.h"

class Scheduler {
private:
	class Node {

	public:

		Task* task;
		Node* left = nullptr;
		Node* right = nullptr;
		bool is_left_thread = false;
		bool is_right_thread = false;


		Node(Task* task, Node* left = nullptr, Node* right = nullptr)
			: task(task), left(left), right(right) {}

		~Node() {
			delete task;
		}
	};

	Node * sceduler_top = nullptr;
public:
	void add(Node*& scheduler_top, Task* task);
};
#endif