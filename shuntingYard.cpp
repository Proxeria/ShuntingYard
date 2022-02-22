#include<iostream>
#include<vector>
#include<sstream>
#include<iterator>
#include<string>

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

bool isOper(string s) {
  return false;
}

bool isRParen(string s) {
  return false;
}

bool isLParen(string s) {
  return false;
}


//wikipedia shuntingYard algorithm
void shuntingYard(std::vector<std::string> tokens) {
//     while there are tokens to be read
  for (string  thisToken: tokens) {
//     if the token is:
//     - a number:
    if (isNumber(thisToken)) {
//         put it into the output queue
    }
//     - an operator o1:
    else if (isOper(thisToken)) {
//         while (
//             there is an operator o2 other than the left parenthesis at the top
//             of the operator stack, and (o2 has greater precedence than o1
//             or they have the same precedence and o1 is left-associative)
//         ):
      while (false) {
//             pop o2 from the operator stack into the output queue
      }
//         push o1 onto the operator stack
    }
    
//     - a left parenthesis (i.e. "("):
    else if (isLParen(thisToken)) {
//         push it onto the operator stack
    }
//     - a right parenthesis (i.e. ")"):
    else if (isRParen(thisToken)) {
//         while the operator at the top of the operator stack is not a left parenthesis:
//             {assert the operator stack is not empty}
// 	    // If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
// pop the operator from the operator stack into the output queue
//         {assert there is a left parenthesis at the top of the operator stack}
//         pop the left parenthesis from the operator stack and discard it
//         if there is a function token at the top of the operator stack, then:
//             pop the function from the operator stack into the output queue
    }
  }
// //After the while loop, pop the remaining items from the operator stack into the output queue.
// while there are tokens on the operator stack:
// //If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses.
// {assert the operator on top of the stack is not a (left) parenthesis}
//     pop the operator from the operator stack onto the output queue
}


int main() {
  string inStr;
  cout << "Put stuff here: " << endl;
  getline(cin, inStr);
  std::vector<std::string> testVec = split(inStr, ' ');

  cout << "Tokens:" << endl;
  for (string  thisToken: testVec) {
    cout << thisToken << endl;
  }
  return 0;
}
