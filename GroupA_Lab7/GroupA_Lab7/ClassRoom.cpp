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

    while(fin>>fname)
    {
        fin>>lname;
        fin>>ssn;
        fin>>grades[0];
        fin>>grades[1];
        fin>>grades[2];
        fin>>grades[3];
        s[i].setFirstName(fname);
        s[i].setLastName(lname);
        s[i].setSocialSecurity(ssn);
        s[i].setExamScore(grades);
        s[i].getAverageScore();
        i++;
        Student::num++;
    }
    count=Student::num;
}

void ClassRoom::displayAllStudentInfo() {
    for(int i=0;i<count;++i)
    {
        cout<<"STUDENT "<<i+1<<" DATA: \n";
        s[i].print();
    }
}

void ClassRoom::calcAvg()
{
    double sum=0;
    for(int i=0;i<count;++i)
    {
        sum+=s[i].getAvg();
    }
cout<<"AVERAGE IS: "<<sum/count<<endl;
}

void ClassRoom::sortbyAvg()
{
    for(int i=0;i<count;++i)
    {
        for(int j=0;j<count-i-1;++j)
        if (s[j].getAvg() > s[j+1].getAvg())
        {
            Student temp = s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
    }
}

void ClassRoom::sortbylastName()
{
    for(int i=0;i<count;++i)
    {
        for(int j=0;j<count-i-1;++j)
        if (s[j].getLName().compare(s[j+1].getLName())<0)
        {
            Student temp = s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
    }
}
