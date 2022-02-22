//header guards
#ifndef STACK_H
#define STACK_H

//all the libararies
#include <iostream>
#include "node.h"

using namespace std;

class Stack{//class declaration
 public: //all public functions
  Stack(void); //constructor that stores a string
  void push(string s);
  string pop(void);
  string peek(void);
 private: //all private variables
  Node* top;
 };

#endif
