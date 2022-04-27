//
// Created by justme on 4/24/22.
//

#ifndef CSC134_LAB7GROUPPROJECT_CLASSROOM_H
#define CSC134_LAB7GROUPPROJECT_CLASSROOM_H

#include "student.h"
using namespace std;

class ClassRoom
{
public:
    string classRoomName;
    int numOfStudentObjects;
    Student StudentArray[24];


    ClassRoom(string classRoomName);

    Student* getStudentArray();
    void setStudentArray(Student StudentArray[24], int numberofStudenObjects);
    void createStudentArray(string fileName);

    void setNumStudentObjects(int n);
    void getNumStudentObjects(int n);

    void setClassRoomName(string classRoomName);

    string getClassRoomName();
    
    double getClassAvgScores();

    void read();

    void sortByAvg();

    void sortByLastName();

    void displayAllStudentInfo();

    int getNoOfStudents();

};
#endif //CSC134_LAB7GROUPPROJECT_CLASSROOM_H

