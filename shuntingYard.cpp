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

int main() {
  string testStr = "1 + 2";
  std::vector<std::string> testVec = split(testStr, ' ');

  for (string  thisToken: testVec) {
    cout << thisToken << endl;
  }
  return 0;
}
