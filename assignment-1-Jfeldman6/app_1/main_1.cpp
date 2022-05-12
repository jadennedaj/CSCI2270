#include <iostream>
#include <fstream>
#include "../code_1/fundamentals_1.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "File name missing" << endl;
        return -1;
    }
    
    string fileName = argv[1];
    ifstream inFile;
    inFile.open(fileName);
    
    if(inFile.is_open()){
        string line;
        float array[100];
        int counter = 0;
        
        while(getline(inFile, line)){
            float s = stof(line);
            addToArrayDesc(array, counter, s);
            counter ++;
            for(int i = 0; i < counter; i++){
                if(i < counter - 1){
                    cout << array[i] << ",";
                }else{
                    cout << array[i] << endl;
                }
            }
        }
    }else{
        cout << "Failed to open the file." << endl;
    }
    return 0;
}