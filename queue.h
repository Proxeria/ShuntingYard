//header guards
#ifndef QUEUE_H
#define QUEUE_H

//all the libararies
#include <iostream>
#include<cassert>
#include "node.h"

using namespace std;

class Queue{//class declaration
public: //all public functions
  Queue(void); //constructor that stores a string
  void enqueue(string s);
  string dequeue(void);
  bool isEmpty(void);
private: //all private variables
  Node* head;
  Node* tail;
};

#endif
