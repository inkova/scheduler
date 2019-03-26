
#include <cassert> 
#include "task_once.h" 
#include "task.h"
#include "task_period.h"

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


int main() {
	test_task_once();
	test_task_period();
	return 0;
}

