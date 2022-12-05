#include <iostream>
#include <string>
#include <sstream>
#include "../data_structures/Stack.cpp"

using namespace std;

string char_to_string(char c) {
  std::string str;
  std::stringstream strStream;
  strStream << c;
  strStream >> str;
  return str;
}

int main() {
  Stack<string> reverseStr; 
  string str = "Huzaifa Nimushimirimana";

  for(int i=0; i<str.length(); i++) {
    reverseStr.push(char_to_string(str[i]));
  }

  cout << reverseStr;
}
