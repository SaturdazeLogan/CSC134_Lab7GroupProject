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
    Student setStudentArray(Student StudentArray[24], int numberofStudenObjects);

    int setNumStudentObjects();
    int getNumStudentObjects();

    string setClassRoomName(string classRoomName);

    string getClassRoomName();

    void read();

    void sortbyAvg();

    void sortbylastname();

    void calcAvg();

    void displayAllStudenInfo();

    int returnNumStudentsinclass();

};
#endif //CSC134_LAB7GROUPPROJECT_CLASSROOM_H

