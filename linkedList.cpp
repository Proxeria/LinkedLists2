#include <iostream>
#include "node.h"

using namespace std;

//students have only ids at the moment
//students are under node, no user interaction yet

void add(Student* student);
void print(Node* next);
Student* getStudent();
float average(Node* next);

Node* head = NULL;

int main() {
  
  char input[50];
  // add(getStudent());
  // print(head);
  // add(new Student((char*)("bob"), (char*)("joe"), 777, 7.7));
  // print(head);
  // add(new Student((char*)("phil"), (char*)("tom"), 888, 8.88));
  // print(head);
  // add(new Student((char*)("tim"), (char*)("tim"), 999, 9.99));
  // print(head);

  while (true) {
  
      cout << "COMMANDS: "<< endl << "ADD: Create a new entry to the student list"
	   << endl << "PRINT: Prints all current entries in the student list"
	   << endl << "DELETE: Deletes speciied student from the list"
	   << endl << "AVERAGE: Prints the average of all student GPAs"
	   << endl << "QUIT: Exits the program" << endl;
      cin.getline(input, 50, '\n');
      //if ADD, add new student
      if (strcmp(input,"ADD") == 0 || strcmp(input,"add") == 0) {
	add(getStudent());
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
	//delId = atoi (input);
	// vector<Student>::iterator it;
	// for (it = students.begin(); it != students.end(); it++) {
	// if (delId == it->id) {
	//	students.erase(it);
	//  }
	//}
      }
      else if (strcmp(input,"AVERAGE") == 0 || strcmp(input,"average") == 0) {
	cout << average(head) << endl;
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
