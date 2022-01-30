#include <iostream>
#include "node.h"

using namespace std;

//students have only ids at the moment
//students are under node, no user interaction yet

void add(Student* student);
void print(Node* next);
Student* getStudent();

Node* head = NULL;

int main() {

  add(getStudent());
  print(head);
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

Student* getStudent() {
  char input[50];
  char firstname[50];
  char lastname[50];
  int studentid;
  float studentgpa;
  //change to cstring stuff
  cout << "Student's first name: ";
  cin.getline(firstname, sizeof(firstname), '\n');
  cout << "Student's last name: ";
  cin.getline(lastname, sizeof(lastname), '\n');
  cout << "Student's ID#: ";
  cin.getline(input, 50, '\n');
  studentid = atoi (input);
  cout << "Student's GPA: ";
  cin.getline(input, 50, '\n');
  studentgpa = atof (input);

  return new Student(firstname, lastname, studentid, studentgpa);
}
