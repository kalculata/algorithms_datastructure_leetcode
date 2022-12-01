#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class LinkedListNode {
public:
  int value;
  LinkedListNode *nextElement = nullptr;

  LinkedListNode(int value) : value(value) {}
};

class LinkedList {
public:
  int length = 0;

  friend ostream& operator << (ostream& output, LinkedList& list) {
    string repr = "[";
    if(list.isNotEmpty()) {
      for(int i=0; i<list.length; i++) {
        repr += to_string(list.get(i));

        if(i+1 < list.length) repr += " -> ";
      }
    }
    repr += "]";

    output << repr;
    return output;
  }

  bool isEmpty() {
    return length == 0;
  }

  bool isNotEmpty() {
    return length != 0;
  }

  void append(int value) {
    LinkedListNode *newNode = new LinkedListNode(value);

    if (isEmpty()) {
      head = newNode;
    }
    else {
      LinkedListNode *last = lastNode();
      last->nextElement = newNode;
    }

    length++;
  }

  void insert(int index, int value)
  {
    length++;
  }

  int get(int index) {
    if (index >= length || head == nullptr ) { throw out_of_range(""); }
 
    LinkedListNode *currentNode = head;

    for (int i = 0; i < index; i++) {
      currentNode = currentNode->nextElement;
    }

    return currentNode->value;
  }

  int remove(int index) {
    length--;
    return 0;
  }

  void search(int value) {
  }

  void clear() {
    length = 0;
  }

  
private:
  LinkedListNode *head = nullptr;

  LinkedListNode *lastNode() {
    if (head) {
      LinkedListNode *currentNode = head;

      while (currentNode->nextElement != nullptr) {
        currentNode = currentNode->nextElement;
      }
      return currentNode;
    }

    return nullptr;
  }
};

int main() {
  LinkedList list;

  list.append(5);
  list.append(5);
  list.append(6);
  list.append(6);
  list.append(6);
  list.append(6);
  list.append(9);
  list.append(12);

  cout << list;
}
