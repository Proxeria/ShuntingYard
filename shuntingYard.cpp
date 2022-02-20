#include<iostream>
#include<vector>
#include<stdio>

using namespace std;
/*
while there are tokens to be read:
    read a token
    if the token is:
    - a number:
        put it into the output queue
    - a function:
        push it onto the operator stack 
    - an operator o1:
        while (
            there is an operator o2 other than the left parenthesis at the top
            of the operator stack, and (o2 has greater precedence than o1
            or they have the same precedence and o1 is left-associative)
        ):
            pop o2 from the operator stack into the output queue
        push o1 onto the operator stack
    - a left parenthesis (i.e. "("):
        push it onto the operator stack
    - a right parenthesis (i.e. ")"):
        while the operator at the top of the operator stack is not a left parenthesis:
            {assert the operator stack is not empty}
            /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
//    pop the operator from the operator stack into the output queue
	    //    {assert there is a left parenthesis at the top of the operator stack}
// pop the left parenthesis from the operator stack and discard it
	//	if there is a function token at the top of the operator stack, then:
	      //            pop the function from the operator stack into the output queue
	      /* After the while loop, pop the remaining items from the operator stack into the output queue. */
	      //  while there are tokens on the operator stack:
	      /* If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses. */
	      /*
	{assert the operator on top of the stack is not a (left) parenthesis}
    pop the operator from the operator stack onto the output queue


 */
struct Node {
  int data;
  struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
  struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
  newnode->data = val;
  newnode->next = top;
  top = newnode;
}
void pop() {
  if(top==NULL)
    cout<<"Stack Underflow"<<endl;
  else {
    cout<<"The popped element is "<< top->data <<endl;
    top = top->next;
  }
}
void display() {
  struct Node* ptr;
  if(top==NULL)
    cout<<"stack is empty";
  else {
    ptr = top;
    cout<<"Stack elements are: ";
    while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
    }
  }
  cout<<endl;
}
int main() {
  int ch, val;
  cout<<"1) Push in stack"<<endl;
  cout<<"2) Pop from stack"<<endl;
  cout<<"3) Display stack"<<endl;
  cout<<"4) Exit"<<endl;
  do {
    cout<<"Enter choice: "<<endl;
    cin>>ch;
    switch(ch) {
    case 1: {
      cout<<"Enter value to be pushed:"<<endl;
      cin>>val;
      push(val);
      break;
    }
    case 2: {
      pop();
      break;
    }
    case 3: {
      display();
      break;
    }
    case 4: {
      cout<<"Exit"<<endl;
      break;
    }
    default: {
      cout<<"Invalid Choice"<<endl;
    }
    }
  }while(ch!=4);
  return 0;
}
