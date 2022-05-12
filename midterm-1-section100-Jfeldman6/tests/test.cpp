// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code_1/LinkedList.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include "test_helpers.hpp"

using namespace std;

class test_x : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test_x::total_grade = 0;
double test_x::max_grade = 100;




/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test_x, TestMiddleEven){ 
    // Test with even key in the middle of list
    int length;
    string result, expected;

    length= 3;
    int list[]= {9, 2, 7};
    result = test_helper_array(list, length);
    expected = readFileIntoString("../tests/t0_array.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(20);
    result = test_helper_linkedList(list, length);
    expected = readFileIntoString("../tests/t0_linkedList.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(5); 

}

TEST_F(test_x, TestHeadEven){ 
    // Test with even key in the head of list
    int length;
    string result, expected;

    length= 4;
    int list[]= {4, 9, 3, 7};
    result = test_helper_array(list, length);
    expected = readFileIntoString("../tests/t2_array.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(20);
    result = test_helper_linkedList(list, length);
    expected = readFileIntoString("../tests/t2_linkedList.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(5); 

}

TEST_F(test_x, TestMultipleEvens){  
    // Test with multiple even keys in the list
    int length;
    string result, expected;
    
    length= 7;
    int list[]= {2, 2, 7, 0, 1, 0, 0};
    result = test_helper_array(list, length);
    expected = readFileIntoString("../tests/t1_array.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(20);
    result = test_helper_linkedList(list, length);
    expected = readFileIntoString("../tests/t1_linkedList.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(5); 
}


TEST_F(test_x, TestAllEvens){  
    // Test with all even keys in the list
    int length;
    string result, expected;
    
    length= 4;
    int list[]= {2, 4, 6, 8};
    result = test_helper_array(list, length);
    expected = readFileIntoString("../tests/t3_array.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(20);
    result = test_helper_linkedList(list, length);
    expected = readFileIntoString("../tests/t3_linkedList.txt");
    ASSERT_EQ(expected, result);
    add_points_to_grade(5); 
}
