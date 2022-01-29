#include "Student.h"

//Just enough to demonstrate node functionality

Student::Student(int newStudentID) {
  studentID = newStudentID;
}

Student::~Student() {
  
}

int Student::getStudentID() {
  return studentID;
}
