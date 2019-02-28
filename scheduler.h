#ifndef __SCHEDULAR_H__
#define __SCHEDULAR_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

#include "Task.h"
#include "SharedPtr.h"
#include "Time.h"

typedef std::pair<SharedPtr<ITask >, Time> taskTime;

class Scheduler
{
public:
	Scheduler();
	Scheduler(SharedPtr<ITask> task);

	~Scheduler();
	
	void add(SharedPtr<ITask> task);
        void run();


private:
    std::vector<taskTime> m_heapTasks;
};

#endif //__SCHEDULAR_H__
