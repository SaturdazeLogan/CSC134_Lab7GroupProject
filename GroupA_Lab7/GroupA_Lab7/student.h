//
//  student.h
//  GroupA_Lab7
//
//  Created by Logan Hoffman on 4/12/22.
//

#ifndef student_h
#define student_h
#include<iostream>
using namespace std;

class Student
{
    
    //Data memeber initialization
    
    string firstName = "";
    string lastName = "";
    string social_security = "";
    double examScore[4];
    static int studentID;
    
    
    // Constructor: no parameters
    Student(){
    }
    
    
    // Constructor: with parameters for setup
    Student(string fN, string lN, string socialSN, double examScoreTempArray[], int stuID){
        
        firstName = fN;
        lastName = lN;
        social_security = socialSN;
        studentID = stuID;
        
        int length = sizeof(examScoreTempArray)/sizeof(examScoreTempArray[0]);
        
        for(i=0; i <= length, i++){
            
            examScore[i] = examScoreTempArray[i];
            
        }
        
    }
    
    
    // Destructor
    ~Student();
    
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
    
    void setFirstName(string firstNameInbound){
        
        firstName = firstNameInbound;
        
    }
    
    void setLastName(string lastNameInbound){
        
        lastName = lastNameInbound;
        
    }
    
    void setSocialSecurity(string socialSecurityInbound){
        
        social_security = socialSecurityInbound;
        
    }
    
    void setExamScore(int examNum, double examScoreInbound){
        
        examScore[examNum] = examScoreInbound;
        
    }
    
    //getAverageScore calculates and then returns the exam average of the student.
    
    double getAverageScore(){
        
        double examTotal = 0.00;
        double examAverage = 0.00;
        
        int length = sizeof(examScore)/sizeof(examScore[0]);
        
        for(i=0; i <= length, i++){
            
            examTotal = examTotal + examScore[i];
            
        }
        
        examAverage = examTotal/4;
        
        return examAverage;
        
    }
    
    //displayBasicStats displays the first and last name, exam scores and exam average to the console.
    
    void displayBasicStats(){
        
        double examTotal = 0.00;
        double examAverage = 0.00;
        
        int length = sizeof(examScore)/sizeof(examScore[0]);
        
        for(i=0; i <= length, i++){
            
            examTotal = examTotal + examScore[i];
            
        }
        
        examAverage = examTotal/4;
        
        cout << "\nStudent first name: " << firstName;
        cout << "\nStudent last name: " << lastName;
        cout << "\nStudent exam average: " << examAverage;
        cout << "\nExam score list: " << examScore[0] << ", " << examScore[1] << ", " << examScore[2] << ", " << examScore[3];
        
    }
    
    //Returns student object ID
    
    static int getStudentID(){
        
        return studentID;
        
    }
    
};


#endif /* student_h */
