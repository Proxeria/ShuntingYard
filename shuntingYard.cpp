#include<iostream>
#include<vector>
#include<sstream>
#include<iterator>
#include<string>
#include "stack.h"
#include "queue.h"

using namespace std;

//https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
template <typename Out>
void split(const std::string &s, char delim, Out result) {
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim)) {
    *result++ = item;
  }
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

//https://www.geeksforgeeks.org/program-check-input-integer-string/
bool isNumber(string s)
{
  for (int i = 0; i < s.length(); i++)
    if (isdigit(s[i]) == false)
      return false;

  return true;
}

bool isOper(string thisToken) {
  if (thisToken == "+" || thisToken == "-" || thisToken == "*" || thisToken == "/") {
    return true;
  }
  return false;
}

bool isRParen(string s) {
  return (s != "" && s == ")");
}

bool isLParen(string s) {
  return (s != "" && s == "(");
}

//compares preceadence of 2 ops
//returns -1 if left has higher precadence than the right or 1 if vise versa or 0 if same
int opHigher(string left, string right) {
  switch (left[0]) {
  case '(' :
  case ')' :
    switch (right[0]) {
    case '(' :
    case ')' :
      return 0;
    default :
      return -1;
    }
    break;
  case '*' :
  case '/' :
    switch (right[0]) {
    case '(' :
    case ')' :
      return 1;
    case '*' :
    case '/' :
      return 0;
    default :
      return -1;
    }
    break;
  case '+' :
  case '-' :
  default :
    switch (right[0]) {
    case '(' :
    case ')' :
    case '*' :
    case '/' :
      return 1;
    default :
      return 0;
    }
    break;
  }
}

bool isLAssoc(string opStr) {
  if (opStr != "(" && opStr != ")") {
    return true;
  }
  else {
    return false;
  }
}


//wikipedia shuntingYard algorithm
void shuntingYard(std::vector<std::string> tokens) {
  Stack opStack;
  Queue outQueue;
  string tempToken;
  // while there are tokens to be read
  for (string  thisToken: tokens) {
    cout << "This token is: " << thisToken << endl;
    // if the token is:
    // - a number:
    if (isNumber(thisToken)) {
      cout << "number" << endl;
      outQueue.enqueue(thisToken);
    }
    // - an operator o1:
    else if (isOper(thisToken)) {
      cout << "Token is: " << thisToken << " Top of opStack: " << opStack.peek() << endl;
      // while there is an operator o2 other than the left parenthesis at the top
      // of the operator stack, and (o2 has greater precedence than o1
      // or they have the same precedence and o1 is left-associative)
      while ((isOper(opStack.peek()) && (opStack.peek() != "(")) &&
	     ((opHigher(opStack.peek(), thisToken) == 1) ||
	      ((opHigher(opStack.peek(), thisToken) == 0) && isLAssoc(thisToken)))) {
	// pop o2 from the operator stack into the output queue
	tempToken = opStack.pop();
	outQueue.enqueue(tempToken);
      }
      // push o1 onto the operator stack
      opStack.push(thisToken);
    }
    
    // - a left parenthesis (i.e. "("):
    else if (isLParen(thisToken)) {
      opStack.push(thisToken);
    }
    // - a right parenthesis (i.e. ")"):
    else if (isRParen(thisToken)) {
      // while the operator at the top of the operator stack is not a left parenthesis:
      while (!isLParen(opStack.peek())) {
	// {assert the operator stack is not empty}
	// If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
	assert(opStack.peek() != "");
	// pop the operator from the operator stack into the output queue
	tempToken = opStack.pop();
	outQueue.enqueue(tempToken);
      }
      // {assert there is a left parenthesis at the top of the operator stack}
      assert(isLParen(opStack.peek()));
      // pop the left parenthesis from the operator stack and discard it
      opStack.pop();
    }
  }
  // //After the while loop, pop the remaining items from the operator stack into the output queue.
  // while there are tokens on the operator stack:
  cout << "after while" << endl;
  while (opStack.peek() != "") {
    cout << "top of stack: " << opStack.peek() << endl;
    // //If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
    // {assert the operator on top of the stack is not a (left) parenthesis}
    assert(!isLParen(opStack.peek()));
    // pop the operator from the operator stack onto the output queue
    tempToken = opStack.pop();
    outQueue.enqueue(tempToken);
  }

  // dump queue
  cout << "out queue: ";
  while (!outQueue.isEmpty()) {
    cout << outQueue.dequeue() << " ";
  }
  cout << endl;
}
    
void stackTest(void) {
  Stack test;
  cout << "peeking on empty" << endl;
  cout << test.peek() << endl;
  cout << "pushing 1" << endl;
  test.push("1");
  cout << "peeking 1" << endl;
  cout << test.peek() << endl;
  test.push("2");
  cout << "peeking 2" << endl;
  cout << test.peek() << endl;
  cout << "popping 2" << endl;
  cout << test.pop() << endl;
  cout << "peeking 1" << endl;
  cout << test.peek() << endl;
  cout << "popping 1" << endl;
  cout << test.pop() << endl;
  cout << "popping empty" << endl;
  cout << test.pop() << endl;
  cout << "didnt explode" << endl; 
}

void queueTest(void) {
  Queue test;
  if (test.isEmpty()) {
    cout << "queue is empty" << endl;
  }
  cout << "dequeueing from empty" << endl;
  cout << test.dequeue() << endl;
  cout << "enqueue 1" << endl;
  test.enqueue("1");
  if (test.isEmpty()) {
    cout << "queue is empty, shouldnt be!!" << endl;
  }
  cout << "dequeueing 1" << endl;
  cout << test.dequeue() << endl;
  if (test.isEmpty()) {
    cout << "queue is empty, SHOULD be" << endl;
  }
  cout << "endqueueing 2" << endl;
  test.enqueue("2");
  cout << "enqueueing 3" << endl;
  test.enqueue("3");
  cout << "dequeueing 2" << endl;
  cout << test.dequeue() << endl;
  cout << "dequeueing 3" << endl;
  cout << test.dequeue() << endl;
  cout << "didnt explode" << endl; 
}

int main() {
  stackTest();
  queueTest();
  string inStr;
  cout << "Put stuff here: " << endl;
  getline(cin, inStr);
  std::vector<std::string> testVec = split(inStr, ' ');

  cout << "Tokens:" << endl;
  for (string  thisToken: testVec) {
    cout << thisToken << endl;
  }
  cout << "yard" << endl;
  shuntingYard(testVec);

  return 0;
}
