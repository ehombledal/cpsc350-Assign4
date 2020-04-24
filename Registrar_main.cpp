#include "GenQueue.h"
#include "Window.h"
#include <string>
#include <fstream>

Window *windows;
int countedStudents;
int totalStudents;
int currTime = 0;
int numWindows;

GenQueue<Student> *studentsRemaining = new GenQueue<Student>;
GenQueue<Student> *inLine = new GenQueue<Student>;

int parseFile(string file)
{
  ifstream inFS;
  string windowParse;

  string tickParse;
  string waitTimeParse;
  string numStudentParse;

  cout << "Opening file " << file << endl;
  inFS.open(file);

  if (!inFS.is_open())
  {
     cout << "Could not open file " <<file << endl;
     return 1; // 1 indicates error
  }

  inFS >> windowParse; //parses first line, always number of windows.
  int windowCount = stoi(windowParse);
  cout << "window count is" << windowParse << endl;
  windows = new Window[windowCount];

  for (int i = 0; i < windowCount; ++i)
  {
    Window *newWindow = new Window();
    windows[i] = *newWindow;
    numWindows++;
  }

  //WINDOW ARRAY DONE

  while (!inFS.eof()) //goes until end of file
   {
     inFS >> tickParse; //what tick this is
     inFS >> numStudentParse; //how many students there are in this tick.
     int studentTimeHolder[stoi(numStudentParse)];

     for (int i = 0; i < stoi(numStudentParse); i++)
     {
       inFS >> waitTimeParse;
       studentTimeHolder[i] = stoi(waitTimeParse);
     }

     if (!inFS.fail())
      {
        for (int i = 0; i < stoi(numStudentParse); ++i)
        {
          Student *student = new Student(studentTimeHolder[i], stoi(tickParse));
          totalStudents++;
          studentsRemaining -> insert(*student);
        }
      }
   }

   cout << "Closing file " << file << endl;
   inFS.close(); // Done with file, so close it
   return 0;
}

void checkToEnter(int tick)
{
  if (studentsRemaining -> isEmpty() == true)
  {
    return;
  }

  int topStudentTick = studentsRemaining ->peek().tickToAppear;
  while(topStudentTick == tick)
  {
    inLine -> insert(studentsRemaining -> remove());
    countedStudents++;
    if (studentsRemaining -> isEmpty() == false)
    {
      topStudentTick = studentsRemaining ->peek().tickToAppear;
    } else {
      cout << "all students have been added to line!" << endl;
      break;
    }
  }
}

void checkIfDone(int currentTime)
{
  //check all windows to see if a student finished
    //if they did finish, calculate statistics, discard student
  for (int i = 0; i < numWindows; ++i)
  {
    if(windows[i].finishThisTick(currentTime) == true)
    {
      cout << "window " << i << " is done on tick " << currentTime << endl;
      //calculateStatistics(windows[i]);
     }
  }
}

void checkIfOpen(int currTime)
{
  if (inLine -> isEmpty() == false) //means someone is in line
  {
    for (int i = 0; i < numWindows; ++i) //check if any windows are open
    {
      if (windows[i].checkOccupied() == false)
      {
        windows[i].changeToOccupied(inLine -> remove());  //puts student into window, gets all statistics
        cout << "window " << i << " has been set to occupied" << endl;
        break;
      }
    }
  }
}

void calculateStatistics()
{
  cout << "Mean Student Wait Time: " << << endl;
  cout << "Median Student Wait Time: " << << endl;
  cout << "Longest Student Wait: " << << endl;
  cout << "Number of students waiting over 10 minutes: " << << endl;
  cout << "Mean window idle: " << <<endl;  
  //printout of statistics go here.
  //mean student wait
  //median student wait
  //longest student wait
  //num students waiting over 10
  //mean window idle
  //longest window idle
  //num of windows idled for over 5
}


int main(int argc, char **argv)
{
  string fileName = argv[1];
  parseFile(fileName); //puts students in list
  //AT THIS POINT: Have a list of all students stored (studentsRemaining), with the tick they need to enter saved to them.
  int i = 0;
  while ( i < 20)
  {
    //cout << "total students: " << totalStudents << "  countedStudents: " << countedStudents << endl;
    //cout << "checking students to enter line" << endl;
    checkToEnter(currTime); //pulls students from array based on tick and puts them into line, uses for loop
    checkIfDone(currTime); // checks if the people at the window finished this tick. Also calculates statistics
    checkIfOpen(currTime); //checks if a person is waiting. If there is, put them at a window!
    currTime++;
    i++;
  }
  cout << "got out of loop " << endl;
  calculateStatistics();
}
