#include "Student.h"

Student::Student()
{
  timeNeeded  = 2;
  tickToAppear = 0;
  timeWaiting = 0;
  beingHelped = false;
}

Student::Student(int time, int tick)
{
  timeNeeded  = time;
  tickToAppear = tick;
  timeWaiting = 0;
  beingHelped = false;
}

bool Student::overTenMinWait()
{
  if (timeWaiting > 10)
  {
    return true;
  } else {
    return false;
  }
}

void Student::incrementTime()
{
  timeWaiting++;
}

int Student::getTimeNeeded()
{
  return timeNeeded;
}

int Student::getTimeWaiting()
{
  return timeWaiting;
}

bool Student::getHelpStatus()
{
  return beingHelped;
}
