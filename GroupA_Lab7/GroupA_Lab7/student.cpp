//
// Created by justme on 4/15/22.
//

// Created by justme on 4/15/22.
//
#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

static int numberOfStudents = 0;

Student::Student() {
    firstName = "";
    lastName = "";
    social_security = "";
    double examScore[4] = {0.0, 0.0, 0.0, 0.0};
    studentID = 0;

}

Student::Student(string fN, string lN, string socialSN, double examScoreTempArray[], int stuID) {
    firstName = fN;
    lastName = lN;
    social_security = socialSN;
  //  examScore[4] = examScoreTempArray[4];
  for (int i = 0; i < 4; i++)
  {
      examScore[i] = examScoreTempArray[i];
  }
    studentID = stuID;
    numberOfStudents += 1;
}

string Student::getFirstName() {

    return firstName;
}

string Student::getLastName() {
    return lastName;
}
string Student::getSocialSecurity() {
    return  social_security;
}

double Student::getExamScore(int examNum) {
    int examIndex = examNum - 1;
    return examScore[examIndex];
}

double * Student::getExamScoreArray(){
    return examScore;
}
// Setter functions.


void Student::setFirstName(string firstNameInbound) {

    firstName = firstNameInbound;

}


// This funciton sets the last name for our student object

void Student::setLastName(string lastNameInbound) {
    lastName = lastNameInbound;
}

// this function sets the social security number variable for the student object

void Student::setSocialSecurity(string socialSecurityInbound) {
    social_security = socialSecurityInbound;
}

void Student::setExamScore(double scores[]) {

    for (int i = 0; i < 4; i++)
    {
        examScore[i] = scores[i];
    }
}

double Student::getAverageScore() {
    double examTotal = 0.00;
    double examAverage = 0.00;

    int length = sizeof(examScore)/sizeof(examScore[0]);  // sizeof yeilds the size in bytes of the data type. This gives 32 bytes/ 8 or uint 4

    for(int i=0; i <= length; i++){

        examTotal = examTotal + examScore[i]; // could just use += here

    }

    examAverage = examTotal/4;

    return examAverage;

}

void Student::displayBasicStats() {
    double examTotal = 0.00;
    double examAverage = 0.00;



    for(int i=0; i < 4; i++){


        examTotal += examScore[i];

    }

    examAverage = examTotal/4;

    std::cout << setw(20) << lastName << setw(20) << firstName << setw(20) << social_security;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(10) << examScore[i];
    }
    cout << setw(10) << examAverage;
    cout << endl;
    /*setw(10) << "score 1"
       << setw(10) << "Score 2" << setw(10) << "score 3" << setw(10) << "score 4" << setw(10) << "average" << '\n';*/



    /*
    cout << "Last Name" <<
    cout << "\nStudent first name: " << firstName;
    cout << "\nStudent last name: " << lastName;
    cout << "\nStudent exam average: " << examAverage;
    cout << "\nExam score list: " << examScore[0] << ", " << examScore[1] << ", " << examScore[2] << ", " << examScore[3] << endl;
   */
}


int Student::getStudentID() {

    return studentID;
}

//Student::Student(string basicString, string basicString1, string basicString2, double *pDouble) {

//}
