#include "Time.h"

Time::Time(unsigned long period)
{
    clockid_t clk_id;
    clk_id = CLOCK_REALTIME;
    clock_gettime(clk_id, &m_time);

    period *= 1000000;
    period += m_time.tv_nsec;

    m_time.tv_nsec = period % 1000000000;
    m_time.tv_sec += period / 1000000000;
}

Time::Time()
{
   clockid_t clk_id;
   clk_id = CLOCK_REALTIME;
   clock_gettime(clk_id, &m_time);
}



bool Time::operator < (const  Time & other ) const 
{
   if (m_time.tv_sec == other.m_time.tv_sec)
        return m_time.tv_nsec < other.m_time.tv_nsec;

   return m_time.tv_sec < other.m_time.tv_sec;
}


Time& Time::operator + (unsigned long  period)
{
   
    period += m_time.tv_nsec;

    m_time.tv_nsec = period % 1000000000;
    m_time.tv_sec += period / 1000000000;

    return *this;

}

void Time::sleep()
{
	Time now_time;
	if (now_time < *this);
	{
		long nano = (m_time.tv_sec - now_time.m_time.tv_sec) / 1000000000 + m_time.tv_nsec - now_time.m_time.tv_nsec;

		timespec req;
		req.tv_sec = nano / 1000000000;
		req.tv_nsec = nano % 1000000000;
		nanosleep(&req, NULL);
	}
}
