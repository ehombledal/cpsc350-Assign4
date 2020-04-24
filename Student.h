class Student
{
  public:
    Student(); //default constructor
    Student(int time, int tick); //overloaded

    int tickToAppear; //tick where student enters line
    int timeNeeded; //time students need at window
    int timeWaiting; //time students been waiting
};
