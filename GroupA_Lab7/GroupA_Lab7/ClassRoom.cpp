/*

 Originally written by Q. Daniel
 Modified and debugged by L. Hoffman, I. Boehlert
 4/26/22
 Classroom.cpp uses the functions outline in Classroom.h to create
 ClassRoom objects, set name of the classroom object, fill StudentArray,
 retrieve StudentArray, and sort by average score.

*/
 
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"ClassRoom.h"
#include "student.h"
using namespace std;

//Constructor
ClassRoom::ClassRoom(string cname) {
    classRoomName = cname;
    numOfStudentObjects = 0;
}

//Setter-class name
void ClassRoom::setClassRoomName(string name) {
    classRoomName = name;
}

//Setter-number of students
void ClassRoom::setNumStudentObjects(int n) {
    numOfStudentObjects = n;
}

//Getter-class name
string ClassRoom::getClassRoomName() {
    return classRoomName;
}

//Getter-number of students
void ClassRoom::getNoOfStudents() {
    cout << "\n" << "Total students in this class: " << numOfStudentObjects << endl;

}

//Method to fill StudentArray array
void ClassRoom::setStudentArray(Student students[], int numStudent) {
    numOfStudentObjects = numStudent;
    for(int i = 0; i < numStudent; i++)
        StudentArray[i] = students[i];
}

//Getter for students array
Student* ClassRoom::getStudentArray() {
    return StudentArray;
}

// method to read given text file and fill StudentArray
void ClassRoom::createStudentArray() {
    ifstream file;

    // open file
    file.open("students.txt");

    // check if file is successfully opened
    if(!file.is_open()) {
        cout << "'" << "students.txt" << "'" << " file not found !!!" << endl;
        exit(1);
    }

    string fname;
    string lname;
    string social_security;
    double examScore[4];
    int i=0;

       while(file && i != 16) {
        // read data
           
          // cout << "Student No. " << i << endl;   DEBUG NO LONGER NEEDED
           
           file >> fname;
        StudentArray[i].setFirstName(fname); // set first name
          // cout << "First Name: " << fname << endl;   DEBUG NO LONGER NEEDED
           file >> lname;
           StudentArray[i].setLastName(lname); // set last name
           
          // cout << "Last Name: " << lname << endl;    DEBUG NO LONGER NEEDED
           
           
           file >> social_security;
        StudentArray[i].setSocialSecurity(social_security); // set SSN

        file >> examScore[0] >> examScore[1] >> examScore[2] >> examScore[3];
        StudentArray[i].setExamScore(examScore); // set scores

        i++;
    }

    // set number of students
    numOfStudentObjects = i;

    file.close();
}

// method to sort students data by their average score
void ClassRoom::sortByAvg() {
    int min_idx;

    // apply selection sort algorithm
    for (int i = 0; i < numOfStudentObjects - 1; i++) {
        min_idx = i;
        for (int j = i+1; j < numOfStudentObjects; j++) {
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
    for (int i = 0; i < numOfStudentObjects - 1; i++) {
        min_idx = i;
        for (int j = i+1; j < numOfStudentObjects; j++) {
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
void ClassRoom::getClassAvgScores() {
    double avg = 0;

    for(int i = 0; i < numOfStudentObjects; i++) {
        // add average average scores
        avg += StudentArray[i].getAverageScore();
    }
    // compute average and return
    
    cout << "\n" << "Average Class Score: " << avg/(numOfStudentObjects) << endl;
    
}

void ClassRoom::displayAllStudentInfo() {

    std::cout
            << setw(20) << "Last Name" << setw(20) << "First Name" << setw(20) << "SSN" << setw(10) << "score 1"
            << setw(10) << "Score 2" << setw(10) << "score 3" << setw(10) << "score 4" << setw(10) << "average" << '\n';
    
  for(int i = 0; i < numOfStudentObjects; i++) {
        StudentArray[i].displayBasicStats(); // print data
}

}
