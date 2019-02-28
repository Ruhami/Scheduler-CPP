#include "scheduler.h"

bool comp(taskTime i, taskTime j)
{
	return j.second < i.second;
}

Scheduler::Scheduler()
{
}

Scheduler::Scheduler(SharedPtr<ITask> task)
{
	unsigned long nano = task->getNextRunPeriod();
	if(nano)
	{
		Time t(task->getNextRunPeriod());
		m_heapTasks.push_back(std::make_pair(task, t));
		make_heap(m_heapTasks.begin(), m_heapTasks.end(), comp); 
	}
}

Scheduler::~Scheduler()
{

}

void Scheduler::add(SharedPtr<ITask> task)
{
	unsigned long nano = task->getNextRunPeriod();
	if(nano)
	{
		Time t(nano);
		m_heapTasks.push_back(std::make_pair(task, t));
		push_heap(m_heapTasks.begin(), m_heapTasks.end(), comp);
	}
}

void Scheduler::run()
{
	while(!m_heapTasks.empty())
	{
	   std::pop_heap(m_heapTasks.begin(), m_heapTasks.end(), comp);
    	   taskTime now_task = m_heapTasks.back();
    	   m_heapTasks.pop_back();
    	
    	   now_task.second.sleep();
    	
    	   now_task.first->run();

	   add(now_task.first);
	}
}
