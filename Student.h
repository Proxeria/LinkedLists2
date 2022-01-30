#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student(char* newFirstname, char* newLastname, int newStudentID, float newStudentGPA);
  ~Student();
  char* getFirstname();
  char* getLastname();
  int getStudentID();
  float getGPA();
  
 private:
  char* firstname;
  char* lastname;
  int studentID;
  float studentGPA;
};
#endif
