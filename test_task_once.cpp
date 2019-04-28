#include <iostream>
#include <cassert> 
#include "task_once.h" 
#include "task.h"
#include "task_period.h"
#include "scheduler_tree.h"

using std::string;
using std::cout;

void test_task_once() {
	Task_once t1("do", "done", 1, 2);  // ������� �������
	assert(t1.get_imp() == 1);         // �������� �������� � ������� �����������
	assert(t1.get_time() == 2);
	
	t1.print();
	
	bool res;
	res = t1.extension(9);            // ��������� �� ���������� 9
	assert(res);
	assert(t1.get_imp() == 1);
	assert(t1.get_time() == 11);

	res = t1.extension(-8);           // ��������� �� ���������� 8
	assert(res);
	assert(t1.get_imp() == 1);
	assert(t1.get_time() == 3);

	res = t1.change_imp(3);           // �������� �� ���������� 3
	assert(res);
	assert(t1.get_imp() == 3);
	assert(t1.get_time() == 3);

	res = t1.change_imp(-3);          // �������� �� ������������ -3 (-3<0)
	assert(!res);
	assert(t1.get_imp() == 3);
	assert(t1.get_time() == 3);

	res = t1.extension(-8);           // ��������� �� ������������ -8 ( (3-8)<0 )
	assert(!res);
	assert(t1.get_imp() == 3);
	assert(t1.get_time() == 3);

}

void test_task_period() {
	Task_period tp("do_period", "done_period", 1, 2, 3);  // ������� �������
	assert(tp.get_imp() == 1);         // �������� �������� � ������� �����������
	assert(tp.get_time() == 2);
	assert(tp.get_period() == 3);

	tp.print();

	bool res;
	res = tp.extension(9);            // ��������� �� ���������� 9
	assert(res);
	assert(tp.get_imp() == 1);
	assert(tp.get_time() == 11);

	res = tp.extension(-8);           // ��������� �� ���������� 8
	assert(res);
	assert(tp.get_imp() == 1);
	assert(tp.get_time() == 3);

	res= tp.miss();                   // ���������� ����������
	assert(res);
	assert(tp.get_time() == 6);
	assert(tp.get_imp() == 1);

	res = tp.change_imp(3);           // �������� �� ���������� 3
	assert(res);
	assert(tp.get_imp() == 3);
	assert(tp.get_time() == 6);

	res = tp.change_imp(-3);          // �������� �� ������������ -3 (-3<0)
	assert(!res);
	assert(tp.get_imp() == 3);
	assert(tp.get_time() == 6);

	res = tp.extension(-7);           // ��������� �� ������������ -8 ( (6-7)<0 )
	assert(!res);
	assert(tp.get_imp() == 3);
	assert(tp.get_time() == 6);

}

void test_tree() {
	Scheduler  sch = Scheduler();
	Task_period * tp1 = new Task_period("do_period1", "done_period1", 1, 2, 3);
	Task_once *to1= new Task_once("do1", "done1", 3, 1);
	Task_period * tp2 = new Task_period("do_period2", "done_period2", 4, 5, 6);
	Task_once *to2 = new Task_once("do2", "done2", 4, 4);
	Task_once *to3 = new Task_once("do3", "done3", 4, 10);

	Task *task[5] = { tp1, tp2, to1, to2, to3 };
	
	for (int i = 0; i < 5; i++) {
	  sch.add(task[i]);
	 
	  cout << "\nTree: \n";
	  sch.show();
	//  printf("---\n");
	//  sch.print();
	  cout << "\n";
	} 
	Task * result_of_search =nullptr;
	sch.search("do_period2", result_of_search);
	if (result_of_search != nullptr) result_of_search->print();
	else cout << "Task with this name not found\n";
	
	sch.delete_one_task("do_period1");
	cout << "\nAfter delete:\n";
	sch.show();
	
	sch.search("do_period1", result_of_search);
	cout << "\nAfter search:\n";
	if (result_of_search != nullptr) result_of_search->print();
	else cout << "Task with this name not found\n";
	
	sch.perform("do_period2");
	cout << "\nAfter perform:\n";
	sch.show();
	
	sch.perform("do2");
	cout << "\nAfter perform:\n";
	sch.show();

	cout << "\nPrint first:\n";
	sch.print_first();
	

	sch.delete_all_tree();
	sch.show();
}


int main() {
	test_task_once();
	test_task_period();
	test_tree();
	return 0;
}

