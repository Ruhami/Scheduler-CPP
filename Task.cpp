#include "Task.h"
#include <stdio.h>
#include <unistd.h>

void Task1::run()
{
   printf("****************Task 1 is runing******************\n");
}

unsigned long Task1::getNextRunPeriod()
{
   return 2000;
}

void Task2::run()
{
   printf("****************Task 2 is runing******************\n");
//    sleep(3000);
}

unsigned long Task2::getNextRunPeriod()
{
//    sleep(3000);
   return 3000;

}

void Task3::run()
{
   printf("****************Task 3 is runing******************\n");
}

unsigned long Task3::getNextRunPeriod()
{
//    usleep(3);
   return 4000;

}
