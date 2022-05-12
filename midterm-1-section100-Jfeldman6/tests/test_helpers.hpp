#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
string test_helper_array(int testList[], int length);
string test_helper_linkedList(int testList[], int length);
void printArray(int arr[], int l);
#endif // TEST_H__