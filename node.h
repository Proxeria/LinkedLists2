//header guards
#ifndef NODE_H
#define NODE_H

//all the libararies
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

class Node{//class declaration
 public: //all public functions
  Node(Student* student); //constructor that takes in and stores a student pointer
  void setNext(Node* node); //sets the next node
  Node* getNext(); //returns the next node
  Student* getStudent(); //gets the student pointer
  ~Node(); //destructor
 private: //all private variables
  Node* next; //the next node
  Student* kid;
};

#endif
