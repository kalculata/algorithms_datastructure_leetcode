#include <iostream>
#include <cstdlib>
#include <cxxabi.h>
#include <sstream>
#include "LinkedList.cpp"

using namespace std;

/// @brief All operations are performed in O(1) time.
template <typename T> class Stack {
  public:
    string type;

    Stack() {
      type = getType();
    }

    friend ostream& operator << (ostream& output, Stack& stack) {
      string repr = "[";
      if(stack.elements.isNotEmpty()) {
        for(int i=0; i<stack.elements.length; i++) {
          if(stack.type == "string") {
            repr += stack.elements.get(i);
          } else {
            stringstream ss;
            ss << stack.elements.get(i);         
            repr += ss.str();
          }

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

    std::string getType() {
      int status;
      std::string tname = typeid(T).name();
      char *demangled_name = abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status);

      if(status == 0) {
        tname = demangled_name;
        std::free(demangled_name);
      } 

      if(tname == "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >")  {
        return "string";
      }
      return tname;
    }
};

// int main() {
//   Stack<string> stack;

//   stack.push("1");
//   stack.push("2");
//   stack.push("5");

//   cout << stack << endl;

//   // stack.pop();
//   // cout << stack << endl;
// }