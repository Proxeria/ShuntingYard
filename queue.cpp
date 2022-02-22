//all the libararies
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(void) {
  head = NULL;
  tail = NULL;
}

void Queue::enqueue(string s) {
  //  cout << __FILE__ <<  ":" <<  __LINE__ << " " << "constructing queue with new Node" << endl;
  Node* newNode = new Node(s);
  
  if (tail == NULL) {
    assert(head == NULL);
    head = newNode;
    tail = newNode;
  }
  else {
    tail->setNext(newNode);
    tail = newNode;
  }
  
}

bool Queue::isEmpty(void) {
  return head == NULL;
}

string Queue::dequeue(void) {
  if (head == NULL) {
    assert(tail == NULL);
    return "";
  }
  else {
    Node* tempHead = head;
    head = head->getNext();
    //only 1 item was head and tail
    if (head == NULL) {
      tail = NULL;
    }
    string headStr = tempHead->getToken();
    delete tempHead;
    return headStr;
  }
}



 
