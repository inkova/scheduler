#ifndef TASK_ONCE_H_
#define TASK_ONCE_H_ //! �������� ������� ������������ ��������

#include <string>
#include"task.h"

class Task_once : public Task {

public:
	Task_once(std::string name, std::string data, int imp, int time)  //!< �������� �������
		:Task(name, data, imp, time) {}

	void print() const;

};

#endif


