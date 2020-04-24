#include "Window.h"

Window::Window()
{
  isOccupied = false;
  idleTime = 0;
  largestIdle = 0;
  tickWillComplete = 0;
}

bool Window::checkOccupied()
{
  return isOccupied;
}

void Window::changeToOccupied(Student student, int currentTime)
{
  //add statistics to pile
  //set do checks for idle time
  //find out how many ticks student will be staying for

  isOccupied = true;
  currentStudent = student;
  totalStudentWait += currentTime - student.tickToAppear;
  totalIdleTime += idleTime;

  if (currentTime - student.tickToAppear > longestStudentWait)
  {
    longestStudentWait = currentTime - student.tickToAppear;
  }

  if (currentTime - student.tickToAppear > 10)
  {
    numOverTenMin++;
  }

  if (idleTime > largestIdle)
  {
    largestIdle = idleTime;
    idleTime = 0;
  }

  if (idleTime > 5)
  {
    numOverFiveMin++;
  }


  tickWillComplete = student.tickToAppear + student.timeNeeded;

  //cout << "window is now occupied! Will finish on tick: " << tickWillComplete;
}

bool Window::finishThisTick(int currentTime)
{
  if (currentTime == tickWillComplete)
  {
    isOccupied = false;
    //is finishing this turn
    return true;
  }else{
    if (isOccupied == true)
    {
      //not finishing this turn, but occupied
      return false;
    } else {
      //not finishing this turn, unoccupied
      idleTime++;
      return false;
    }
  }
}
