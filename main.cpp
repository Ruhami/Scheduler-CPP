int main()
{
	Scheduler s;
	///....add tasks
	while(1)
	{
		size_t t = s.getSleepingTime();
		if (t > 0)
			sleep(t);
		t.getNextTask().run();
	}
	/*std::vector<int> v1;
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(25);
	v1.push_back(15); 
	std::vector<int>::iterator it1;
	for (it1=v1.begin(); it1!=v1.end(); it1++) 
       std::cout << *it1 << " "; 
    std::cout << std::endl;
	make_heap(v1.begin(), v1.end()); 
	for (it1=v1.begin(); it1!=v1.end(); it1++) 
       std::cout << *it1 << " "; 
    std::cout << std::endl;
	v1.push_back(50);
	push_heap(v1.begin(), v1.end());
	for (it1=v1.begin(); it1!=v1.end(); it1++) 
       std::cout << *it1 << " "; 
    std::cout << std::endl;
    	make_heap(v1.begin(), v1.end()); 
	for (it1=v1.begin(); it1!=v1.end(); it1++) 
       std::cout << *it1 << " "; 
    std::cout << std::endl;
	return 0;*/
}

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
};
