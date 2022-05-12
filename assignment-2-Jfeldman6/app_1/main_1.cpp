#include <iostream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // your code here
    if (argc<4){
        std::cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << std::endl;
    }else{
        int num = stoi(argv[1]);
        string inFile = argv[2];
        const char* ignore = argv[3];
        string ignoreWords[50];
        string word;
        int size = 100;
        wordRecord *arr = new wordRecord[size];
        int count = 0;
        int distinct = 0;
        int nonIgnore = 0;
        
        ifstream in;
        ifstream ignoreIn;
        in.open(inFile);
        ignoreIn.open(ignore);
        if(!ignoreIn.is_open() || !in.is_open()){
            cout << "File(s) did not open" << endl;
            return 0;
        }else{
            
            getIgnoreWords(ignore, ignoreWords);
            
            while(in >> word){
                if(isIgnoreWord(word, ignoreWords, 50) == false){
                    bool found = false;
                    for(int i = 0; i < distinct; i++){
                        if(arr[i].word == word){
                            arr[i].count++;
                            found = true;
                        }
                    }
                    
                    if(found == false){
                        if(distinct == size){
                            int newSize = size*2;
                            wordRecord *newArray = new wordRecord[newSize];
                            for(int i = 0; i < size; i++){
                                newArray[i] = arr[i];
                            }
                            delete[] arr;
                            arr = nullptr;
                            size = newSize;
                            arr = newArray;
                            count++;
                        }
                        
                        arr[distinct].word = word;
                        arr[distinct].count = 1;
                        distinct++;
                    }
                }
                
                nonIgnore = getTotalNumberNonIgnoreWords(arr, distinct);
                
            }
            
            sortArray(arr, distinct);
            cout << "Array doubled: " << count << endl;
            cout << "Distinct non-common words: " << distinct << endl;
            cout << "Total non-common words: " << nonIgnore << endl;
            cout << "Probability of next 10 words from rank " << num << endl;
            cout << "---------------------------------------" << endl;
            printTenFromN(arr, num, nonIgnore);
            
        }
        
        
    }
    
    return 0;
}