#include "Window.h"

Window::Window()
{
  isOccupied = false;
  idleTime = 0;
  largestIdle = 0;
}

int Window::checkCurrentIdle()
{
  return idleTime;
}

int Window::checkLargestIdle()
{
  return largestIdle;
}

bool Window::checkOccupied()
{
  return isOccupied;
}

void Window::changeToOccupied(Student student)
{
  //add statistics to pile
  //set do checks for idle time
  //find out how many ticks student will be staying for

  isOccupied = true;
  currentStudent = student;
  totalTime += idleTime;
  if (idleTime > largestIdle)
  {
    largestIdle = idleTime;
    idleTime = 0;
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
