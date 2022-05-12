#include <gtest/gtest.h>
#include "test_helpers.hpp"
#include "../code_1/LinkedList.hpp"


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string readFileIntoString(std::string fileName){
	std::string line, out;
  	ifstream A;
  	A.open(fileName);
  	if(!A){throw std::runtime_error("could not open file: " + fileName);}
	while(getline(A,line)){
		out = out+line+"\n";
	}
	return out;
}


string test_helper_array(int testList[], int length)
{
    SLL s;
    for(int i=length-1; i>=0; i--){
        s.insertAtHead(testList[i]);
    }
    int* arrayOfEvens, evensCount=0;
    s.moveEvenToArray(arrayOfEvens, evensCount);
    testing::internal::CaptureStdout();
    cout << "Array of evens: ";
    printArray(arrayOfEvens, evensCount);
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_helper_linkedList(int testList[], int length)
{
    SLL s;
    for(int i=length-1; i>=0; i--){
        s.insertAtHead(testList[i]);
    }
    int* arrayOfEvens, evensCount=0;
    s.moveEvenToArray(arrayOfEvens, evensCount);
    testing::internal::CaptureStdout();
    // Linked List after removing evens:
    s.displayList();
    string output = testing::internal::GetCapturedStdout();
    return output;
}

void printArray(int arr[], int l){
    for(int i=0; i<l; i++){
        cout << arr[i] << " ";
    }
    if(l == 0)
        cout << "Empty array" << endl;
    else
        cout << "(length = "<< l << ")" << endl;
}



