#ifndef __TASK__H
#define __TASK__H
#include<iostream>
#include<algorithm>
#include <ctime>



struct ITask
{
   virtual void run() = 0;
   virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
};

class Task1 : public ITask
{
	Task1();
	~Task1();
	
	void run();
    unsigned long getNextRunPeriod();
};

class Task2 : public ITask
{
	Task2();
	~Task2();
	
	void run();
    unsigned long getNextRunPeriod();
};

class Task3 : public ITask
{
	Task3();
	~Task3();
	
	void run();
    unsigned long getNextRunPeriod();
};

#endif //__TASK__H 
