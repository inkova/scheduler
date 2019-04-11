
#include <iostream>
#include "scheduler_tree.h"
#include "task.h"

using std::string;
using std::endl;
using std::cout;

void Scheduler::add (Node*& scheduler_top, Task* task) {

	if (scheduler_top == nullptr)
		scheduler_top = new Node(task); // дерево пусто, значит добавляемый элемент - корень
	else 

		if (*task < *(scheduler_top->task)) {    //необходимо перейти влево
			
			if (scheduler_top->left != nullptr && scheduler_top->is_left_thread == false) { // слево задание уже есть, сново проверять только с головой левого
				add(scheduler_top->left, task);
			}

			else {             // слево никого нет, помещаем сюда
				Node* for_prepering_to_add = new Node(task);
				//готовим левый конец
				if (scheduler_top->is_left_thread) {             //перекидываем прошивку
					for_prepering_to_add->left = scheduler_top->left;
					for_prepering_to_add->is_left_thread = true;
					scheduler_top->is_left_thread = false;
				}
				scheduler_top->left = for_prepering_to_add; 

				for_prepering_to_add->right = scheduler_top;
				for_prepering_to_add->is_right_thread = true;
			}

		}

		else if (*(task) > *(scheduler_top->task)) {   // аналогично с левым

			if (scheduler_top->right != nullptr && scheduler_top->is_right_thread == false)
				add(scheduler_top->right, task);

			else {

				Node* for_prepering_to_add = new Node(task);

				if (scheduler_top->is_right_thread) {
					for_prepering_to_add->right = scheduler_top->right;
					for_prepering_to_add->is_right_thread = true;
					scheduler_top->is_right_thread = false;
				}
				scheduler_top->right = for_prepering_to_add;

				for_prepering_to_add->left = scheduler_top;
				for_prepering_to_add->is_right_thread = true;

			}

		}

}