//header guards
#ifndef NODE_H
#define NODE_H

//all the libararies
#include <iostream>

using namespace std;

class Node{//class declaration
 public: //all public functions
  Node(string token); //constructor that stores a string
  void setNext(Node* node); //sets the next node
  Node* getNext(); //returns the next node
  string getToken(); //gets the token string
 private: //all private variables
  Node* next;
  string m_token;
};

#endif
