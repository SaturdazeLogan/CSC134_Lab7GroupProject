#include<iostream>
#include<string>
#include<fstream>
#include"ClassRoom.h"
#include "student.h"
using namespace std;


void ClassRoom::read()
{
    ifstream fin ("student.txt"); //
    int size=0;
    string fname;
    string lname;
    string ssn;
    double grades[4];
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

void ClassRoom::sortbylastname()
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
