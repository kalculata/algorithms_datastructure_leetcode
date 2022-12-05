#include <iostream>
#include "../data_structures/Stack.cpp"

using namespace std;

bool validate(string parantheses) {
  Stack<char> stack;

  for(int i=0; i<parantheses.length(); i++) {
    if(parantheses[i] != ')' && parantheses[i] != ']' && parantheses[i] != '}') {
      stack.push(parantheses[i]);
    } 
    else {
      if(parantheses[i] == ')' && stack.top() == '(') {
        stack.pop();
      } else if(parantheses[i] == ']' && stack.top() == '[') {
        stack.pop();
      } else if(parantheses[i] == '}' && stack.top() == '{') {
        stack.pop();
      } else {
        return false;
      }
    }
  }

  return stack.isEmpty();
}

int main() {
  string parantheses =  "(){";
  cout << "valid: " << validate(parantheses);
}