#include <iostream>
using namespace std;

template <typename T>
class GenListNode
{
  public:
          T data;
          GenListNode *next;
          GenListNode *prev;

          GenListNode(); //default
          GenListNode(T d); //overloaded
          ~GenListNode();
};

template <typename T>
GenListNode<T>::GenListNode()
{
  data = NULL;
  next = NULL; //or nullptr
  prev = NULL;
}

template <typename T>
GenListNode<T>::GenListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T>
GenListNode<T>::~GenListNode()
{
  //research
}


template <typename T>
class GenLinkedList //Doubly linked list
{
  public:
    GenLinkedList();
    ~GenLinkedList();

    //insert methods
    void insertFront(T data);
    void insertBack(T data);
    void insertAt(T data, int position);

    //removal methods
    T removeFront();
    T removeBack();
    T remove(T value);
    T removeAt(int position);

    //helper methods
    int search(T value); //returns position
    T valueAt(int positon);
    void printList();
    unsigned int getSize();
    bool isEmpty();

  private:
    GenListNode<T> *front;
    GenListNode<T> *back;
    unsigned int size;

};

template <typename T>
GenLinkedList<T>::GenLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <typename T>
GenLinkedList<T>::~GenLinkedList()
{
  //figure it out
}



template <typename T>
void GenLinkedList<T>::insertFront(T data)
{
  GenListNode<T> *node = new GenListNode<T>(data); //node to be inserted
  if (isEmpty())
  {
    back = node;
  } else
  {
    front -> prev = node;
    node -> next = front;
  }
  front = node;
  size++;
}

template <typename T>
void GenLinkedList<T>::insertBack(T data)
{
  GenListNode<T> *node = new GenListNode<T>(data); //node to be inserted
  if (isEmpty())
  {
    front = node;
  } else
  {
    back -> next = node;
    node -> prev = back;
  }
  back = node;
  size++;
}

template <typename T>
void GenLinkedList<T>::insertAt(T data, int position)
{
  //ACTUALLY DO THIS METHOD
}

template <typename T>
T GenLinkedList<T>::removeFront()
{
  GenListNode<T> *temp = front;

  if (front -> next == NULL)
  {
    //if there is one node in list
    back = NULL;
  } else {
    //there is more than one node in the list
    front->next->prev = NULL;
  }

  front = front-> next;
  temp->next = NULL;
  T holder = temp->data;

  delete temp;
  size--;
  return holder;
}

template <typename T>
T GenLinkedList<T>::removeBack()
{
  GenListNode<T> *temp = back;

  if (back -> prev == NULL)
  {
    //if there is one node in list
    back = NULL;
  } else {
    //there is more than one node in the list
    back->prev->next = NULL;
  }

  back = back-> prev;
  temp->prev = NULL;
  T holder = temp->data;

  delete temp;
  size--;
  return holder;
}

//need to find value in list before we can delete
//this function does NOT take in a position as a param

template <typename T>
T GenLinkedList<T>::remove(T value)
{
  GenListNode<T> *current = front;

  while (current -> data != value)
  {
    //keep iterating till we find value
    current = current -> next;
    if (current == NULL)
    {
      return -1;
    }
  }   //we found value
  if (current == front)
  {
    //if node found is in front
    front = current -> next;
  } else {
    //node to be deleted is not front
    current->prev->next = current -> next;
  }

  if (current == back)
  {
    back = current->prev;
  } else {
    //node to be deleted isnt front or back
    current -> next -> prev = current->prev;
  }

  current -> next = NULL;
  current -> prev = NULL;

  T temp = current->data;
  delete current;
  size--;
  return temp;

}

template <typename T>
T GenLinkedList<T>::removeAt(int position)
{
  int index = 0;
  GenListNode<T> *current = front;
  GenListNode<T> *previous = front;

  //loop until we find position
  while (index != position)
  {
    previous = current;
    current = current -> next;
    index++;
  }

  //found position of node to be deleted!
  previous -> next = current -> next;
  current->next = nullptr;
  T temp = current -> data;
  delete current;
  size--;
  return temp;
}

template <typename T>
int GenLinkedList<T>::search(T value)
{
  int position = -1;

  GenListNode<T> *current = front;
  while (current != NULL)
  {
    //iterate and attempt to find value
    position++;
    if (current->data == value)
    {
      break; //found it
    } else {
      current = current->next;
    }

    if (current == NULL)
    {
      position = -1; //got all the way to the end, didnt find it
    }
    return position;
  }
}

template <typename T>
T GenLinkedList<T>::valueAt(int position)
{
  if (getSize() >= position)
  {
    GenListNode<T> *current = front;
    for (int i = 1; i < position; ++i)
    {
      current = current -> next;
    }
    return current -> data;
  } else {
    cout << "out of bounds!" << endl;
    T* obj = {};
    return *obj;
  }
}

template <typename T>
unsigned int GenLinkedList<T>::getSize()
{
  return size;
}

template <typename T>
bool GenLinkedList<T>::isEmpty()
{
  return (size == 0);
}

template <typename T>
void GenLinkedList<T>::printList()
{
  GenListNode<T> *current = front;
  while (current != NULL)
  {
    cout << current -> data << endl;
    current = current -> next;
  }
}
