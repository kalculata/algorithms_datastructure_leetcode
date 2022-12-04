#include <iostream>
#include "LinkedList.cpp"

using namespace std;

/// @brief All operations are performed in O(1) time.
template <typename T> class Stack {
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

    void push(T value) {
      elements.unshift(value);
    }

    void pop() {
      elements.remove(0);
    }

    T top() {
      return elements.get(0);
    }

    bool isEmpty() {
      return elements.isEmpty();
    }

    int size() {
      return elements.length;
    }

  private:
    LinkedList<T> elements;
};

// int main() {
//   Stack<int> stack;

//   stack.push(1);
//   stack.push(2);
//   stack.push(5);

//   cout << stack << endl;

//   stack.pop();
//   cout << stack;
// }