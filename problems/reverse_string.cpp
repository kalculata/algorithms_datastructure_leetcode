#include <iostream>
#include <string>

#include "../data_structures/Stack.cpp"

using namespace std;

int main() {
  Stack reverseStr; 
  string str = "Huzaifa Nimushimirimana";

  for(int i=0; i<str.length(); i++) {
    reverseStr.push(str[i]);
  }

  cout << reverseStr;
}
