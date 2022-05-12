#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

using namespace std;


void printData(const studentData student[], int index){
      for(int i = 0; i < index; i++){
           cout << student[i].studentName << ", " << student[i].average << ", " << calcLetterGrade(student[i].average) << endl;
      }
}

int main(int argc, char* argv[])
{
    // your code here
        
        string inFile = argv[1];
        string outFile = argv[2];
        char* lowBound = argv[3];
        char* upBound = argv[4];
        string line;
        string studentName;
        string homework;
        string quiz;
        string recitation;
        string exam;
        studentData student[10];
        int index = 0;
        
        //if(*lowBound <= *upBound){
           // return 0;
        //}
        
       
        ifstream in(argv[1]);
        //in.open(inFile);
        ofstream outF(argv[2]);
        //outF.open(outFile);
    
        if(in.fail()){
            cout << "Unable to open file: " << inFile << endl;
            return 0;
        }else if(outF.fail()){
            cout << "Unable to open file: " << outFile << endl;
            return 0;
        }else{
        
    
        
        while(getline(in, line)){
            stringstream s(line);
            getline(s, studentName, ',');
            getline(s, homework, ',');
            getline(s, recitation, ',');
            getline(s, quiz, ',');
            getline(s, exam);

            addStudentData(student, studentName, stoi(homework), stoi(recitation), stoi(quiz), stoi(exam), index);
            if(calcLetterGrade(student[index].average) <= *lowBound){
                if(calcLetterGrade(student[index].average) >= *upBound){
                outF << student[index].studentName << "," << student[index].average << "," << calcLetterGrade(student[index].average) << endl;
                cout << student[index].studentName << "," << student[index].average << "," << calcLetterGrade(student[index].average) << endl;
            }
            }
            
            index ++;
        }
        in.close();
            
        //printData(student, index);
        outF.close();
    }
    
 
    return 0;
}


