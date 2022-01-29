#include <iostream>
#include "Node.h"

using namespace std;

//students have only ids at the moment
//students are under node, no user interaction yet

void add(Student* student);
void print(Node* next);

Node* head = NULL;

int main() {
  add(new Student(3));
  print(head);
  add(new Student(5));
  print(head);
  add(new Student(7));
  print(head);
}

void add(Student* student) {
  Node* current = head;
  if (current == NULL) {
    head = new Node(student);
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node(student));
  }
}

void print(Node* next) {
  if (next == head) {
    cout << "list:";
  }
  if (next != NULL) {
    cout << next->getStudent()->getStudentID() << " ";
    print(next->getNext());
  }
  else {
    cout << endl;
  }
}
