#include <iostream>
#include "../data_structures/Stack.cpp"

using namespace std;

int evaluate(string exp) {
  Stack<int> list;
  int res = 0;

  for(int i=0; i<exp.length(); i++) {
    int tmp;

    if(exp[i] != '*' && exp[i] != '/' && exp[i] != '-' && exp[i] != '+') {
      tmp = exp[i] - '0';
      list.push(tmp);
    } 
    else {
      int b = list.pop();
      int a = list.pop();

      if(exp[i] == '+') {
        tmp = a + b;
      } else if(exp[i] == '*') {
        tmp = a * b;
      } else if(exp[i] == '-') {
        tmp = a - b;
      }

      list.push(tmp);
    }
    cout << list << endl;
  }


  return 1;
}

int main() {
  evaluate("23*54*+9-");
}