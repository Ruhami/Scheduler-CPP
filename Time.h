#ifndef __TIME__H
#define __TIME__H
#include<iostream>
#include<algorithm>
#include <ctime>
#include "SharedPtr.h"

class Time
{
  public: 
    Time(unsigned long period);
    Time();

    bool operator < (const Time & other) const ;
    Time& operator + (unsigned long period);
    timespec get_time() const;
   
    void sleep();
    

 private:
   timespec m_time;

};



inline timespec Time::get_time()const
{
  return m_time;
}

#endif // time
