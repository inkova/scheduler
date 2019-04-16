#ifndef TASK_PERIOD_H_
#define TASK_PERIOD_H_

#include "task.h"

class Task_period : public Task {
	int period;
	bool is_task_periodic=true;
public :
	Task_period (const std::string& name, const std::string& data, int imp, int time, int period)  // �������� �������
		:Task(name, data, imp, time), period(period) {}

	int get_period() const {       // ������ �������
		return period;
	}
	void print() const;
	
	Task_period* clone() const { return new Task_period(*this); }

	bool miss() {
		if(extension(period))  
			return true;
	    else { return false; }
	}
	bool get_periodic() const {
		return is_task_periodic;
	}
};
#endif