//
//  main.cpp
//  GroupA_Lab7
//
//  Created by Logan Hoffman on 4/8/22.
//

#include <iostream>
#include "student.h"

int main(int argc, const char * argv[]) {
    
    double exams[4] = {90.0, 85.4, 79.3, 98.6};
    
    
    Student FirstStudent("Johnny", "Apple", "0010020003", exams, 1);
    FirstStudent.displayBasicStats();
    return 0;
}
