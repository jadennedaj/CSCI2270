#include "array_double.hpp"

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]){
    string line;
    ifstream ignore;
    ignore.open(ignoreWordFileName);
    int ignoreWordsCount = 0;
    if(ignore.is_open()){
        while(getline(ignore, line)){
            ignoreWords[ignoreWordsCount] = line;
            ignoreWordsCount++;
        }
    }else{
        std::cout << "Failed to open " << ignoreWordFileName << std::endl;
    }
}


bool isIgnoreWord(string word, string ignoreWords[], int length){
    for(int i = 0; i < length; i++){
        if(word == ignoreWords[i]){
            return true;
        }
        if(i == length - 1){
            return false;
        }
    }
}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){
    int totalUniqueWords = 0;
    for (int i = 0; i < length; i++){
        totalUniqueWords = distinctWords[i].count + totalUniqueWords;
    }
    return totalUniqueWords;
}


void sortArray(wordRecord distinctWords[], int length){
    wordRecord temp;
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(distinctWords[i].count == distinctWords[j].count){
                if(distinctWords[i].word > distinctWords[j].word){
                temp = distinctWords[i];
                distinctWords[i] = distinctWords[j];
                distinctWords[j] = temp;
                }
            }else if(distinctWords[i].count < distinctWords[j].count){
                temp = distinctWords[i];
                distinctWords[i] = distinctWords[j];
                distinctWords[j] = temp;
            }
        }
    }
}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
    for(int i = N; i < N+10; i++){
        float probability = (float) distinctWords[i].count / totalNumWords;
        cout << fixed << setprecision(5) <<  probability << " - " << distinctWords[i].word << endl;
    }
}

