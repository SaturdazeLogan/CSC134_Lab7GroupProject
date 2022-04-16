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
    
    //Data memeber initialization
    
    string firstName = "";
    string lastName = "";
    string social_security = "";
    double examScore[4];
    int studentID;
    
    
    // Constructor: no parameters
    Student(){
    }
    
    
    // Constructor: with parameters for setup
    Student(string fN, string lN, string socialSN, double examScoreTempArray[], int stuID){
        
        firstName = fN;
        lastName = lN;
        social_security = socialSN;
        studentID = stuID;
        
        
        
        for(int i=0; i < 4; i++){
            
            examScore[i] = examScoreTempArray[i];
            
        }
        
    }
    
    
    // Destructor: NEEDS AN UPDATE/BUG FIX
    //~Student();
    
    // Getter functions for all member variables
    
    string getFirstName(){
        
        return firstName;
        
    }
    
    string getLastName(){
        
        return lastName;
        
    }
    
    string getSocialSecurity(){
        
        return social_security;
        
    }
    
    double getExamScore(int examNum){
        
        return examScore[examNum];
        
    }
    
    // Setter functions for all member variables
    
    void setFirstName(string *firstNameInbound){
        
        firstName = firstNameInbound;
        
    }
    
    void setLastName(string lastNameInbound){
        
        lastName = lastNameInbound;
        
    }
    
    void setSocialSecurity(string socialSecurityInbound){
        
        social_security = socialSecurityInbound;    // Do most of these setters need to be pointers.
        
    }
    
    void setExamScore(int examNum, double examScoreInbound){
        
        examScore[examNum] = examScoreInbound;
        
    }
    
    //getAverageScore calculates and then returns the exam average of the student.
    
    double getAverageScore(){
        
        double examTotal = 0.00;
        double examAverage = 0.00;
        
        int length = sizeof(examScore)/sizeof(examScore[0]);  // sizeof yeilds the size in bytes of the data type. This gives 32 bytes/ 8 or uint 4
        
        for(int i=0; i <= length; i++){
            
            examTotal = examTotal + examScore[i]; // could just use += here
            
        }
        
        examAverage = examTotal/4;
        
        return examAverage;
        
    }
    
    //displayBasicStats displays the first and last name, exam scores and exam average to the console.
    
    void displayBasicStats(){
        
        double examTotal = 0.00;
        double examAverage = 0.00;
        

        
        for(int i=0; i < 4; i++){
        
            
            examTotal += examScore[i];
            
        }
        
        examAverage = examTotal/4;
        
        cout << "\nStudent first name: " << firstName;
        cout << "\nStudent last name: " << lastName;
        cout << "\nStudent exam average: " << examAverage;
        cout << "\nExam score list: " << examScore[0] << ", " << examScore[1] << ", " << examScore[2] << ", " << examScore[3] << endl;
        
    }
    
    //Returns student object ID
    
    int getStudentID(){
        
        return studentID;
        
    }
    
};


#endif /* student_h */
