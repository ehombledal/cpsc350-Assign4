#include <iostream>
#include "GenLinkedList.h"
using namespace std;

template <typename T>
class GenQueue
{
  public:
    GenQueue(); //default
    GenQueue(int maxSize); //overloaded
    ~GenQueue(); //destructor

    //functions
    void insert(T data); //insert
    T remove();  //remove

    //helper functions
    bool isFull();
    bool isEmpty();
    T peek();
    int getSize();
    void printQueue();

    //variables
    int m_size;  //max size
    int numElements; //number of current elements
    GenLinkedList<T> *myQueue; //pointer to array as we dont have the array built yet. Build at runtime.
};

//IMPLEMENTATION

template <typename T>
GenQueue<T>::GenQueue() //default constructor
{
  myQueue = new GenLinkedList<T>;
  m_size = 128;
  numElements = 0;
}

template <typename T>
GenQueue<T>::GenQueue(int maxSize) //overloaded
{
  myQueue = new GenLinkedList<T>;
  m_size = maxSize;
  numElements = 0;
}

template <typename T>
GenQueue<T>::~GenQueue() //destructor
{
  delete *myQueue;
}

template <typename T>
void GenQueue<T>::insert(T data)
{
  if (numElements <= m_size)
  {
    myQueue -> insertBack(data);
    ++numElements;
  } else {
    cout << "Queue is full! Can't add any more!" << endl;
  }

}

template <typename T>
T GenQueue<T>::remove()
{
  T data;
  if (numElements >= 0)
  {
    data = myQueue -> removeFront();
    --numElements;
  } else {
    cout << "Queue is empty! Can't remove!" << endl;
  }

  return data;
}

template <typename T>
T GenQueue<T>::peek()
{
  if (numElements >= 0)
  {
    return myQueue -> valueAt(1);
  } else {
    cout << "Queue is empty! Nothing to peek!" << endl;
  }
}

template <typename T>
bool GenQueue<T>::isFull()
{
  return (numElements == m_size);
}

template <typename T>
bool GenQueue<T>::isEmpty()
{
  return (numElements == 0);
}

template <typename T>
int GenQueue<T>::getSize()
{
  return numElements;
}

template <typename T>
void GenQueue<T>::printQueue()
{
  return myQueue -> printList();
}
