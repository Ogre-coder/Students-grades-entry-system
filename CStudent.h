#pragma once

//#includ guards - check if the header file is already defined
#ifndef CSTUDENT_H_ 
#define CSTUDENT_H_

#include <string> // header file to use string 

using namespace std;

class CStudent
{
public:
	CStudent(void); //define a constructor
	~CStudent(void); //define a destructor

	//hold data of one student
	string student_number;
	float lab_grade = 0;
	float quiz_grade = 0;
	float midterm_grade = 0;
	float finalexam_grade = 0;
	float final_grade = 0;
};

#endif;