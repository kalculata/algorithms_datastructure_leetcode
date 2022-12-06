#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T> class QueueNode {
public:
  T value;
  QueueNode<T> *nextNode = nullptr;

  QueueNode<T>(T value) : value(value) {}
};

template <typename T> class Queue {
public:
  int length = 0;

  friend ostream& operator << (ostream& output, Queue& list) {
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

  bool isEmpty() {
    return length == 0;
  }

  bool isNotEmpty() {
    return length != 0;
  }

  void push(T value) {
    QueueNode<T> *newNode = new QueueNode<T>(value);

    if (isEmpty()) {
      front = newNode;
      tail = newNode;
    } else if(length == 1) {
      tail = newNode;
      front->nextNode = tail;
    } else {
      tail->nextNode = newNode;
      tail = newNode;
    }

    length++;
  }

  T pop() {
    T value;

    if(front != nullptr) {
      if(length == 1) { 
        value = front->value;
        delete front; 
        front = nullptr;
      } else {
        value = front->value;
        QueueNode<T>* newFront = front->nextNode;

        delete front;
        front = newFront;
      }
      length--;
    }
    return value;
  }

  void clear() {
    if(front) {
      QueueNode<T>* currentNode = front;
      QueueNode<T>* nextNode = currentNode->nextNode;

      while(currentNode->nextNode) {
        delete currentNode;
        currentNode = nextNode;
        nextNode = currentNode->nextNode;
      }

      delete nextNode;
      delete currentNode;
      front = nullptr;
    }

    length = 0;
  }
  
  void reverse() {
    if(length > 1) {
      QueueNode<T>* currentNode = front;
      QueueNode<T>* prevNode = nullptr;
      QueueNode<T>* nextNode;
      tail = front;

      while(currentNode) {
        nextNode = currentNode->nextNode;
        currentNode->nextNode = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
      }

      front = prevNode;
    }
  }

private:
  QueueNode<T> *front = nullptr;
  QueueNode<T> *tail  = nullptr;

  T get(int index) {
    return getNode(index)->value;
  }

  QueueNode<T> *getNode(int index) {
    if (index >= length || front == nullptr ) { throw out_of_range(""); }
 
    QueueNode<T> *currentNode = front;

    for (int i = 0; i < index; i++) {
      currentNode = currentNode->nextNode;
    }

    return currentNode;
  }
};
