#include "LinkedList.cpp"


/// @brief All operations are performed in O(1) time.
class Stack {
  friend ostream& operator << (ostream& output, LinkedList& list) {
    string repr = "[";
    if(list.isNotEmpty()) {
      for(int i=0; i<list.length; i++) {
        repr += to_string(list.get(i));

        if(i+1 < list.length) repr += ", ";
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

  private:
    LinkedList elements;
};