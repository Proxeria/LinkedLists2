#include "Student.h"
#include <cstring>

//Just enough to demonstrate node functionality

Student::Student(char* newFirstname, char* newLastname, int newStudentID, float newStudentGPA) {
  firstname = new char[50];
  strcpy(firstname, newFirstname);
  lastname = new char[50];
  strcpy(lastname, newLastname);
  studentID = newStudentID;
  studentGPA = newStudentGPA;
}

Student::~Student() {
  delete firstname;
  delete lastname;
}

char* Student::getFirstname() {
  return firstname;
}

char* Student::getLastname() {
  return lastname;
}

int Student::getStudentID() {
  return studentID;
}

float Student::getGPA() {
  return studentGPA;
}
