#ifndef TASK_ONCE_H_
#define TASK_ONCE_H_ //! описание задания выполняемого единожды

#include <string>
#include"task.h"

class Task_once : public Task {

public:
	Task_once(std::string name, std::string data, int imp, int time)  //!< создание задания
		:Task(name, data, imp, time) {}

	void print() const;

};

#endif


