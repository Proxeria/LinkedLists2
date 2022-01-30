#include <iostream>
#include "node.h"

using namespace std;

//students have only ids at the moment
//students are under node, no user interaction yet

void add(Student* student);
void print(Node* next);

Node* head = NULL;

int main() {
  add(new Student((char*)("bob"), (char*)("joe"), 777, 7.7));
  print(head);
  add(new Student((char*)("phil"), (char*)("tom"), 888, 8.88));
  print(head);
  add(new Student((char*)("tim"), (char*)("tim"), 999, 9.99));
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
    cout << next->getStudent()->getFirstname() << " ";
    cout << next->getStudent()->getLastname() << " ";
    cout << next->getStudent()->getStudentID() << " ";
    cout << next->getStudent()->getGPA() << " ";
    print(next->getNext());
    
  }
  else {
    cout << endl;
  }
}
