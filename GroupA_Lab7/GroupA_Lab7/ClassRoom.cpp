#include<iostream>
#include<string>
#include<fstream>
#include"ClassRoom.h"
#include "student.h"
using namespace std;

//Constructor
ClassRoom::ClassRoom(string cname) {
    classRoomName = cname;
    noOfStudents = 0;
}

//Setter-class name
void ClassRoom::setClassRoomName(string name) {
    classRoomName = name;
}

//Setter-number of students
void ClassRoom::setNoOfStudents(int n) {
    noOfStudents = n;
}

//Getter-class name
string ClassRoom::getClassRoomName() {
    return classRoomName;
}

//Getter-number of students
int ClassRoom::getNoOfStudents() {
    return noOfStudents;
}

//Method to fill StudentArray array
void ClassRoom::setStudentArray(Student students[], int numStudent) {
    noOfStudents = numStudent;
    for(int i = 0; i < numStudent; i++)
        StudentArray[i] = students[i];
}

//Getter for students array
Student* ClassRoom::getStudentArray() {
    return StudentArray;
}
// method to read given text file and fill StudentArray
void ClassRoom::createStudentArray(string filename) {
    ifstream file("student.txt");

    // open file
    file.open(filename);

    // check if file is successfully opened
    if(!file.is_open()) {
        cout << "'" << filename << "'" << " file not found !!!" << endl;
        exit(1);
    }

    string firstName;
    string lastName;
    string social_security;
    double examScore[4];
    double avg;
    int i=0;

       while(!file.eof()) {
        // read data
        file >> fname;
        StudentArray[i].setFirstName(fname); // set first name

        file >> lname;
        StudentArray[i].setLastName(lname); // set last name

        file >> ssn;
        StudentArray[i].setSocialSecurity(ssn); // set SSN

        file >> score[0] >> examScore[1] >> examScore[2] >> examScore[3];
        StudentArray[i].setExamScore(examScore); // set scores

        i++;
    }

    // set number of students
    noOfStudents = i;

    file.close();
}

// method to sort students data by their average score
void ClassRoom::sortByAvgScores() {
    int min_idx;

    // apply selection sort algorithm
    for (int i = 0; i < noOfStudents - 1; i++) {
        min_idx = i;
        for (int j = i+1; j < noOfStudents; j++) {
            if (StudentArray[j].getAverageScore() < StudentArray[min_idx].getAverageScore()) {
                min_idx = j;
            }
        }
        // swap the data
        Student temp = StudentArray[i];
        StudentArray[i] = StudentArray[min_idx];
        StudentArray[min_idx] = temp;
    }
}

// method to sort students data by their last name
void ClassRoom::sortByLastName() {
    int min_idx;

    // apply selection sort algorithm
    for (int i = 0; i < noOfStudents - 1; i++) {
        min_idx = i;
        for (int j = i+1; j < noOfStudents; j++) {
            if (StudentArray[j].getLastName() < StudentArray[min_idx].getLastName()) {
                min_idx = j;
            }
        }
        // swap the data
        Student temp = StudentArray[i];
        StudentArray[i] = StudentArray[min_idx];
        StudentArray[min_idx] = temp;
    }
}

// method to get class average score
double ClassRoom::getClassAvgScores() {
    double avg = 0;

    for(int i = 0; i < noOfStudents; i++) {
        // add average average scores
        avg += StudentArray[i].getAverageScore();
    }
    // compute average and return
    return avg/noOfStudents;
}

void ClassRoom::displayAllStudentInfo() {
        //To print
       cout << left << setw(15) << "last Name" 
            << left << setw(15) << "first Name" 
            << left << setw(20) << "SSN" 
            << left << setw(15) << "examScore1" 
            << left << setw(15) << "examScore2" 
            << left << setw(15) << "examScore3" 
            << left << setw(15) << "examScore4" 
            << left << setw(15) << "Average" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
  for(int i = 0; i < noOfStudents; i++) {
        StudentArray[i].display(); // print data
}

}
