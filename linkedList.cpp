#include <iostream>
#include <iomanip>
#include "node.h"

using namespace std;

//students have only ids at the moment
//students are under node, no user interaction yet

void add(Node*, Node*, Student* student);
void print(Node* next);
Student* getStudent();
float average(Node* next);
void deleteNode(Node*, Node*, int);

Node* head = NULL;

int main() {
  
  char input[50];
  while (true) {
    
    cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	 << endl << "PRINT: Prints all current entries in the student list"
	 << endl << "DELETE: Deletes speciied student from the list"
	 << endl << "AVERAGE: Prints the average of all student GPAs"
	 << endl << "QUIT: Exits the program" << endl;
    cin.getline(input, 50, '\n');
    //if ADD, add new student
    if (strcmp(input,"ADD") == 0 || strcmp(input,"add") == 0) {
      add(NULL, head, getStudent());
      cout << "Student added! " << endl;
    }
    //if PRINT, print all currently stored students
    else if (strcmp(input,"PRINT") == 0 || strcmp(input,"print") == 0) {
      print(head);
    }
    //if DELETE, delete student from list
    else if (strcmp(input,"DELETE") == 0 || strcmp(input,"delete") == 0) {
      int delId;
      cout << "Enter the id of the student you would like to remove from the list: " << endl;
      cin.getline(input, 50, '\n');
      delId = atoi (input);
      deleteNode(NULL, head, delId);
    }
    else if (strcmp(input,"AVERAGE") == 0 || strcmp(input,"average") == 0) {
      cout << std::fixed;
      cout << std::setprecision(2) << average(head) << endl;
    }
    //if QUIT, exit program
    else if (strcmp(input,"QUIT") == 0 || strcmp(input,"quit") == 0) {
      break;
    }
    //else, cmd not recognized
    else if (strcmp(input,"QUIT") != 0 && strcmp(input,"quit") != 0
	     && strcmp(input,"DELETE") != 0 && strcmp(input,"delete") != 0 &&
	     strcmp(input,"PRINT") != 0 && strcmp(input,"print") != 0
	     && strcmp(input,"ADD") != 0 && strcmp(input,"add") != 0) {
      cout << "Command not recognized" << endl;
    }
  }
}



void add(Node* previous, Node* current, Student* student) {
  Node* newNode = NULL;
  if (current == NULL) {
    newNode = new Node(student);
    if (previous != NULL) {
      previous->setNext(newNode);
    }
    else {
      head = newNode;
    }
  }
  else {
    if (current != NULL && student->getStudentID() > current->getStudent()->getStudentID()) {
      add(current, current->getNext(), student);
      return;
    }
    newNode = new Node(student);
    if (previous == NULL) {
      head = newNode;
    }
    else {
      previous->setNext(newNode);
    }
    
    newNode->setNext(current);
  }
}

void print(Node* next) {
  if (next != NULL) {
    cout << next->getStudent()->getFirstname() << " ";
    cout << next->getStudent()->getLastname() << " ";
    cout << next->getStudent()->getStudentID() << " ";
    cout << next->getStudent()->getGPA() << " ";
    cout << endl;
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

void deleteNode(Node* previous, Node* next, int studentID) {
  if (next == NULL) {
    return;
  }
  else {
    if (studentID != next->getStudent()->getStudentID()) {
      deleteNode(next, next->getNext(), studentID);
      return;
    }
    else {
      if (previous == NULL) {
	head = next->getNext();
      }
      else {
	previous->setNext(next->getNext());
      }
      delete next;
    }
  }
}

float sum(Node* next) {
  if (next != NULL) {
    return next->getStudent()->getGPA() + sum(next->getNext()); 
  }
  else {
    return 0;
  }
}
int count(Node* next) {
  if (next != NULL) {
    return 1 + count(next->getNext()); 
  }
  else {
    return 0;
  }
}

float average(Node* next) {
  if (next != NULL) {
    return sum(next) / count(next);
  }
  else {
    return 0;
  }
}
