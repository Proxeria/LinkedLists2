//libraries
#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Student* student){//constructor class
  kid = student; //copies the passed in student pointer parameter into the variable titled "kid" 
  next = NULL;//sets the next node to null
}

void Node::setNext(Node* node){//sets the next node to be the node passed in as a parameter
  next = node; //sets the variable "next" (Node in the header file) to be equal to the node passed in as parameter
}

Node* Node::getNext(){//returns the next node in the sequence
  return next;
}

Student* Node::getStudent(){ //returns a pointer to the student associated with the particular node
  return kid;
}

Node::~Node(){//destructor
  delete kid;
}
