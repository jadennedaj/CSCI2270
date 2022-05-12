#include "fundamentals_1.hpp"

int addToArrayDesc(float sortedArray[100], int numElements, float newValue){
    
    float temp = 0;
    sortedArray[numElements] = newValue;
    numElements++;
    for(int i = 0; i < numElements; i++){
        for(int j = i + 1; j < sortedArray[j]; j++){
            if(sortedArray[i] < sortedArray[j]){
                temp = sortedArray[i];
                sortedArray[i] = sortedArray[j];
                sortedArray[j] = temp;
            }
        }
    }
    return numElements;
}
    
