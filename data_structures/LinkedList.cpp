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

  void unshift(int value) {
    LinkedListNode *newNode = new LinkedListNode(value);
    LinkedListNode *tmp;

    tmp = head;
    head = newNode;
    newNode->nextElement = tmp;
  
    length++;
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

  void insert(int index, int value) {
    if(index == length) { append(value); }
    else if(index == 0) {unshift(value); }
    else {
      LinkedListNode* newNode  = new LinkedListNode(value);
      LinkedListNode* prevNode = getNode(index-1);

      newNode->nextElement = prevNode->nextElement;
      prevNode->nextElement = newNode;
    }
    length++;
  }

  int get(int index) {
    return getNode(index)->value;
  }

  void pop() {
    if(head) {
      if(length == 1) {
        delete head;
      }
      else {
        LinkedListNode* newLastNode = getNode(length-2);
        LinkedListNode* oldLastNode = lastNode();

        delete oldLastNode;
        newLastNode->nextElement = nullptr;

      }
      length--;
    }
  }

  int remove(int index) {
    return 0;
  }

  void search(int value) {
  }

  void clear() {
    if(head) {
      LinkedListNode* currentNode = head;
      LinkedListNode* nextNode = currentNode->nextElement;

      while(currentNode->nextElement) {
        delete currentNode;
        currentNode = nextNode;
        nextNode = currentNode->nextElement;
      }

      delete nextNode;
    }

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

  LinkedListNode *getNode(int index) {
    if (index >= length || head == nullptr ) { throw out_of_range(""); }
 
    LinkedListNode *currentNode = head;

    for (int i = 0; i < index; i++) {
      currentNode = currentNode->nextElement;
    }

    return currentNode;
  }
};

int main() {
  LinkedList list;

  list.append(9);
  list.append(12);
  list.insert(1, 20);
  list.pop();
  list.pop();
  list.pop();

  cout << list;
}
