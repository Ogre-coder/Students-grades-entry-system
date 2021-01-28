#pragma once

//#includ guards - check if the header file is already defined
#ifndef CCOURSE_H_
#define CCOURSE_H_

//include header files 
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>
#include "CStudent.h"

using namespace std;

class CCourse
{
public:
	CCourse(void); //constructor
	~CCourse(void); //destructor

	//define the methods used 
	int add_student();
	int edit_student();
	int print_menu();
	int print_grades();
	int delete_student();
	int save_student();
	int load_student();
	int quit();

	//variables that used in methods
	string option, str, file_name;
	int student_edit, d, student_delete, count = 0;
	static const size_t npos = -1;

private:
	vector<CStudent> total_students; //create a vector of class CStudent(contains all the data of a student) in private 
};

#endif

