#include "Student.h"

class Window
{
  public:
    Window();
    bool checkOccupied();
    void changeToOccupied(Student student, int currentTime);
    bool finishThisTick(int currentTime);

    Student currentStudent;
    int totalStudentWait;
    int longestStudentWait;
    int numOverTenMin;
    int numOverFiveMin;
    int totalIdleTime;
    int tickWillComplete;
    int timeSpentHelping;
    bool isOccupied;
    int idleTime;
    int largestIdle;
};
