#include "fundamentals_2.hpp"

char calcLetterGrade(double avg)
{
    if(avg >= 90){
        return 'A';   
    }else if(avg >= 80){
        return 'B';   
    }else if(avg >= 70){
        return 'C';
    }else if(avg >= 60){
        return 'D';
    }else{
        return 'F';
    }
}

void addStudentData(studentData student[], string studentName, int homework, int recitation, int quiz, int exam, int index)
{
    int i = index;
    student[i].studentName = studentName;
    student[i].homework = homework;
    student[i].recitation = recitation;
    student[i].quiz = quiz;
    student[i].exam = exam;
    student[i].average = (double)(homework+recitation+quiz+exam)/4;
    
}