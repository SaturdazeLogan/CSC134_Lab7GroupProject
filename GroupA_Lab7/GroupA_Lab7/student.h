//
//  student.h
//  GroupA_Lab7
//
//  Created by Logan Hoffman on 4/12/22.
//

#ifndef student_h
#define student_h
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    // Note from Isaak. I cleaned up this header file a bit. I got rid of the unecceary implementation bits and move them all to
    // the student.cpp file. It has made this file significatnyl shorter. You will notice that I have left the bits that were initially in the file
    // in the file, but I just commented them out. When this project is to be turned in they should be deleted, but I left them for the time being.
    //Data memeber initialization

    //Student(string basicString, string basicString1, string basicString2, double pDouble[4]);

    string firstName = "";
    string lastName = "";
    string social_security = "";
    double examScore[4];
    int studentID;


    // Constructor: no parameters
    Student();//{
    //}


    // Constructor: with parameters for setup
    Student(string fN, string lN, string socialSN, double examScoreTempArray[4], int stuID);





    // Destructor: NEEDS AN UPDATE/BUG FIX
    //~Student();

    // Getter functions for all member variables

    string getFirstName();//{



    string getLastName();//{



    string getSocialSecurity();//{



    double getExamScore(int examNum);//{


    double * getExamScoreArray();

    void setFirstName(string firstNameInbound);//{



    void setLastName(string lastNameInbound);//{



    void setSocialSecurity(string socialSecurityInbound);//{



    // }
    void setExamScore(double scores[]);
    // In the insturctions the professor singled out that we need to have the function that sets
    // the values of the exam score array use an array as input.



    double getAverageScore();
    /*{


    }*/

    //displayBasicStats displays the first and last name, exam scores and exam average to the console.

    void displayBasicStats();

    //Returns student object ID

    int getStudentID();//{

    //return studentID;

    //}

};


#endif /* student_h */
