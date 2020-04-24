#include "Student.h"

class Window
{
  public:
    Window();
    int checkCurrentIdle();
    int checkLargestIdle();
    bool checkOccupied();
    void changeToOccupied(Student student);
    void setUnoccupied();
    void setCurrentStudent();
    bool finishThisTick(int currentTime);

    Student currentStudent;

    int totalTime;
    int tickWillComplete;
    int timeSpentHelping;
    bool isOccupied;
    int idleTime;
    int largestIdle;
};
