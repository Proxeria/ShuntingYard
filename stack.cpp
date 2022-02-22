//all the libararies
#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(void) {
  top = NULL;
}

void Stack::push(string s) {
  //  cout << __FILE__ <<  ":" <<  __LINE__ << " " << "constructing stack with new Node" << endl;
  Node* newNode = new Node(s);
  //  cout << __FILE__ <<  ":" <<  __LINE__ << " " << "have new node" << endl;
  //cout << __FILE__ <<  ":" <<  __LINE__ << " " << "old top is " << top << endl;

  newNode->setNext(top);
  top = newNode;
}

string Stack::pop(void) {
  return "";
}

string Stack::peek(void) {
  if (top == NULL) {
    return "";
  }
  else {
    return top->getToken();
  }
}

 
