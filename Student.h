#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student(int newStudentID);
  ~Student();
  int getStudentID();
 private:
  // char firstname[50];
  //char lastName[50];
  int studentID;
  //float studentGPA;
};
#endif
