#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T> class LinkedListNode {
public:
  T value;
  LinkedListNode<T> *nextNode = nullptr;

  LinkedListNode<T>(T value) : value(value) {}
};

template <typename T> class LinkedList {
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
        LinkedListNode<T> *tmp = head->nextNode;

        delete head;
        head = tmp;  
      }
      length--;
    }
  }

  /// @brief 
  /// Add element at the beginning of a Linked List is performed in O(1) constant time.
  /// @param value 
  void unshift(T value) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);
    LinkedListNode<T> *tmp;

    tmp = head;
    head = newNode;
    newNode->nextNode = tmp;
  
    length++;
  }

  void append(T value) {
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);

    if (isEmpty()) {
      head = newNode;
    }
    else {
      LinkedListNode<T> *last = lastNode();
      last->nextNode = newNode;
    }

    length++;
  }

  void insert(int index, T value) {
    if(index == length) { append(value); }
    else if(index == 0) {unshift(value); }
    else {
      LinkedListNode<T>* newNode  = new LinkedListNode<T>(value);
      LinkedListNode<T>* prevNode = getNode(index-1);

      newNode->nextNode = prevNode->nextNode;
      prevNode->nextNode = newNode;
    }
    length++;
  }

  T get(int index) {
    return getNode(index)->value;
  }

  void pop() {
    if(head != nullptr) {
      if(length == 1) { 
        delete head; 
        head = nullptr;
      } else {
        LinkedListNode<T>* newLastNode = getNode(length-2);
        LinkedListNode<T>* oldLastNode = lastNode();

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
        LinkedListNode<T>* prevNode = getNode(index-1);
        LinkedListNode<T>* selectedNode = getNode(index);

        prevNode->nextNode = selectedNode->nextNode;
        delete selectedNode;
        length--;
      }
    }
  }

  void clear() {
    if(head) {
      LinkedListNode<T>* currentNode = head;
      LinkedListNode<T>* nextNode = currentNode->nextNode;

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
      LinkedListNode<T>* currentNode = head;
      LinkedListNode<T>* prevNode = nullptr;
      LinkedListNode<T>* nextNode;

      while(currentNode) {
        nextNode = currentNode->nextNode;
        currentNode->nextNode = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
      }

      head = prevNode;
    }
  }
  
  void recursiveReverse(LinkedListNode<T>* node) {
    if(node->nextNode == nullptr) {
      head = node;
      return;
    }

    recursiveReverse(node->nextNode);
    LinkedListNode<T>* tmp = node->nextNode;
    tmp->nextNode = node;
    node->nextNode = nullptr;
  }

  LinkedListNode<T> *getNode(int index) {
    if (index >= length || head == nullptr ) { throw out_of_range(""); }
 
    LinkedListNode<T> *currentNode = head;

    for (int i = 0; i < index; i++) {
      currentNode = currentNode->nextNode;
    }

    return currentNode;
  }

private:
  LinkedListNode<T> *head = nullptr;

  LinkedListNode<T> *lastNode() {
    if (head) {
      LinkedListNode<T> *currentNode = head;

      while (currentNode->nextNode != nullptr) {
        currentNode = currentNode->nextNode;
      }
      return currentNode;
    }

    return nullptr;
  }
};

// int main() {
//   LinkedList<int> list;

//   list.append(0);
//   list.append(1);
//   list.append(2);
//   list.pop();
//   list.pop();
//   list.pop();
//   list.pop();

//   list.unshift(6);
//   list.unshift(5);
//   list.unshift(3);
//   list.unshift(2);
//   list.unshift(1);

//   list.remove(2);
//   cout << list << endl;
//   list.remove(2);

//   list.recursiveReverse(list.getNode(0));
//   cout << list;
// }
