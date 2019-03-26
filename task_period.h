#ifndef TASK_PERIOD_H_
#define TASK_PERIOD_H_

#include "task.h"

class Task_period : public Task {
	int period;

public :
	Task_period (std::string name, std::string data, int imp, int time, int period)  // создание задания
		:Task(name, data, imp, time), period(period) {}

	int get_period() const {       // выдача периода
		return period;
	}
	void print() const;

	bool miss() {
		if(extension(period))  
			return true;
	    else { return false; }
	}
};
#endif