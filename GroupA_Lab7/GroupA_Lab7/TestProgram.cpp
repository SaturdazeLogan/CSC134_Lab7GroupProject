//
// Created by justme on 4/15/22.
//
#include "student.h"
#include "ClassRoom.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]){
    // Create ClassRoom Object

    ClassRoom myClassRoom("myClassRoom");
    
    // Use ClassRoom object to create student object by reading student records from the input file students.txt and put the students objects in the array of
        
    myClassRoom.createStudentArray();
    
    // Sutdents which is the data member of classRoom Object

    
    
    // USe the ClassRoom object ot sort the array of students by student average score
    
    myClassRoom.sortByAvg();
    
    // Use the ClassRoom Object to display the students sorted by student average scdore.

    myClassRoom.displayAllStudentInfo();
    
    // Use the ClassRoom object to sort the array of students by student last name

    myClassRoom.sortByLastName();
    
    // Use the classRoom object to display the number of Student objects created.

    myClassRoom.getNoOfStudents();
    
    // Use the clasRoom object to calculate and display the average score of all students.
    
   myClassRoom.displayAllStudentInfo();
    
    myClassRoom.getClassAvgScores();
    
    
}
