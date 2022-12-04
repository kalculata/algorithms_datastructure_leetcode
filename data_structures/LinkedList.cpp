#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class LinkedListNode {
public:
  int value;
  LinkedListNode *nextNode = nullptr;

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

  void shift() {
    if(head) {
      if(length == 1) { 
        delete head; 
        head = nullptr;
      } else {
        LinkedListNode *tmp = head->nextNode;

        delete head;
        head = tmp;  
        length--;
      }
    }
  }

  /// @brief 
  /// Add element at the beginning of a Linked List is performed in O(1) constant time.
  /// @param value 
  void unshift(int value) {
    LinkedListNode *newNode = new LinkedListNode(value);
    LinkedListNode *tmp;

    tmp = head;
    head = newNode;
    newNode->nextNode = tmp;
  
    length++;
  }

  void append(int value) {
    LinkedListNode *newNode = new LinkedListNode(value);

    if (isEmpty()) {
      head = newNode;
    }
    else {
      LinkedListNode *last = lastNode();
      last->nextNode = newNode;
    }

    length++;
  }

  void insert(int index, int value) {
    if(index == length) { append(value); }
    else if(index == 0) {unshift(value); }
    else {
      LinkedListNode* newNode  = new LinkedListNode(value);
      LinkedListNode* prevNode = getNode(index-1);

      newNode->nextNode = prevNode->nextNode;
      prevNode->nextNode = newNode;
    }
    length++;
  }

  int get(int index) {
    return getNode(index)->value;
  }

  void pop() {
    if(head != nullptr) {
      if(length == 1) { 
        delete head; 
        head = nullptr;
      } else {
        LinkedListNode* newLastNode = getNode(length-2);
        LinkedListNode* oldLastNode = lastNode();

        delete oldLastNode;
        newLastNode->nextNode = nullptr;

      }
      length--;
    }
  }

  void remove(int index) {
    if(head) {
      if(index + 1 == length) { pop(); }
      else if(index == 0) { shift(); }

      else {
        LinkedListNode* prevNode = getNode(index-1);
        LinkedListNode* selectedNode = getNode(index);

        prevNode->nextNode = selectedNode->nextNode;
        delete selectedNode;
      }
      length--;
    }
  }

  void clear() {
    if(head) {
      LinkedListNode* currentNode = head;
      LinkedListNode* nextNode = currentNode->nextNode;

      while(currentNode->nextNode) {
        delete currentNode;
        currentNode = nextNode;
        nextNode = currentNode->nextNode;
      }

      delete nextNode;
      delete currentNode;
      head = nullptr;
    }

    length = 0;
  }
  
  void reverse() {
    if(length > 1) {
      LinkedListNode* currentNode = head;
      LinkedListNode* prevNode = nullptr;
      LinkedListNode* nextNode;

      while(currentNode) {
        nextNode = currentNode->nextNode;
        currentNode->nextNode = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
      }

      head = prevNode;
    }
  }
  
  void recursiveReverse(LinkedListNode* node) {
    if(node->nextNode == nullptr) {
      head = node;
      return;
    }

    recursiveReverse(node->nextNode);
    LinkedListNode* tmp = node->nextNode;
    tmp->nextNode = node;
    node->nextNode = nullptr;
  }

  LinkedListNode *getNode(int index) {
    if (index >= length || head == nullptr ) { throw out_of_range(""); }
 
    LinkedListNode *currentNode = head;

    for (int i = 0; i < index; i++) {
      currentNode = currentNode->nextNode;
    }

    return currentNode;
  }

private:
  LinkedListNode *head = nullptr;

  LinkedListNode *lastNode() {
    if (head) {
      LinkedListNode *currentNode = head;

      while (currentNode->nextNode != nullptr) {
        currentNode = currentNode->nextNode;
      }
      return currentNode;
    }

    return nullptr;
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
  list.pop();

  list.unshift(6);
  list.unshift(5);
  list.unshift(3);
  list.unshift(2);
  list.unshift(1);

  list.remove(2);
  cout << list << endl;
  list.recursiveReverse(list.getNode(0));
  cout << list;
}
