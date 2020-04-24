class Student
{
  public:
    Student(); //default constructor
    Student(int time, int tick); //overloaded

    bool overTenMinWait();
    void incrementTime();
    int getTimeNeeded();
    int getTimeWaiting();
    bool getHelpStatus();

    int tickToAppear; //tick where student enters line 
    int timeNeeded; //time students need at window
    int timeWaiting; //time students been waiting
    bool beingHelped; //if at window, true
};
