//
// Created by justme on 4/15/22.
//
#include "student.h"
using namespace std;

 static int numberOfStudents = 0;

 Student::Student() {
     firstName = "";
     lastName = "";
     social_security = "";
     examScore[] = {0.0, 0.0, 0.0, 0.0};
     studentID = 0;

 }

 Student::Student(string fN,string lN, string socialSN, double examScoreTempArray[], int stuID) {
     firstName = fn;
     lastName = lN;
     social_security = socialSN;
     examScore[4] = examScoreTempArray;
     studentID = stuID;
     *numberOfStudents += 1
 }

 string Student::getFirstName() {

     return *firstName;
 }

 string Student::getLastName() {
     return *lastName;
 }
 string Student::getSocialSecurity() {
     return  *social_security;
 }

 double Student::getExamScore(int examNum) {
     int examIndex = examNum - 1;
     return *examScore[examIndex];
 }

 // Setter functions.


 void Student::setFirstName(string firstNameInbound) {


 }