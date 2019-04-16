#ifndef TASK_H_
#define TASK_H_

#include <string>

class Task {

		std::string name; //!< строковый идентификатор задания
		std::string data; //!< текст задания
		int importance; //!< уровень важности задания
		int time; //!< временную метку крайнего срока исполнения задания (целое число, описывающее число секунд от некоторого фиксированного в рамках приложения момента в прошлом)
		bool is_task_periodic;
public:
		Task(const std::string& name, const std::string& data, int imp, int time)  //!< создание задания
			: name(name), data(data), importance(imp), time(time) {}
		
		virtual bool get_periodic() const {
			return is_task_periodic;
		}

		int get_imp() const {        // выдача важности
			return importance;
		}

		int get_time() const {       // выдача времени
			return time;
		}

		const std::string& get_name(void) const{
			return name;
		}

		const std::string& get_data(void) const{
			return data;
     	}

		bool extension(int dtime) {     // продление времени
			if ((time + dtime) >= 0) {
				time += dtime;
				return true;
			}
			else { return false; }
		}

		bool change_imp(int dimp) {     // изменение важности
			if (dimp >= 0) {
				importance = dimp;
				return true;
			}
			else { return false; }
		}   
		virtual void print() const =0;
		virtual Task* clone() const = 0;
		virtual ~Task() {}
		bool operator <(const Task &t) const {
			return time < t.time;
        }

		bool operator >(const Task &t) const {
			return time > t.time;
        }

		bool operator ==(const Task &t) const {
			return time == t.time;
		}
};
#endif