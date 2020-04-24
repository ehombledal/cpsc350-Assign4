#include "Student.h"

Student::Student()
{
  timeNeeded  = 2;
  tickToAppear = 0;
  timeWaiting = 0;
}

Student::Student(int time, int tick)
{
  timeNeeded  = time;
  tickToAppear = tick;
  timeWaiting = 0;
}
