#include <iostream>
#include "LinkedList.cpp"

using namespace std;

/// @brief All operations are performed in O(1) time.
class Stack {
  public:
    friend ostream& operator << (ostream& output, Stack& stack) {
      string repr = "[";
      if(stack.elements.isNotEmpty()) {
        for(int i=0; i<stack.elements.length; i++) {
          repr += to_string(stack.elements.get(i));

          if(i+1 < stack.elements.length) repr += ", ";
        }
      }
      repr += "]";

      output << repr;
      return output;
    }

    void push(int x) {
      elements.unshift(x);
    }

    void pop() {
      elements.remove(0);
    }

    int top() {
      return elements.get(0);
    }

    bool isEmpty() {
      return elements.isEmpty();
    }

    int size() {
      return elements.length;
    }

  private:
    LinkedList elements;
};

int main() {
  Stack stack;

  stack.push(1);
  stack.push(2);
  stack.push(5);

  cout << stack;

  stack.pop();
  cout << stack;
}