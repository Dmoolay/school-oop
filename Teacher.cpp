#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

Teacher::Teacher():Worker()  // default constructor
{
	vector <string> v;
	this->courses = v;
	this->num_courses = 0;
}

Teacher::Teacher(string fn, string ln, int ID, float m, float t, vector<string> Courses, int num):Worker(fn, ln, ID, m, t)
{
	// constructor
	this->courses = Courses;
	this->num_courses = num;
}

Teacher::~Teacher()
{
	//
}

float Teacher::get_salary() 
{
	float a = 1 + this->num_courses;
	float n = basis*(a/10);
	return (n+300*this->t_seniority);
}

bool Teacher::check_if_excel() // check if excel by teachers terms
{
	if (this->num_courses >= 5)
	{
		return true;
	}
	return false;
}

void Teacher::print_courses() // print all teachers courses
{
	cout << "courses: " << endl;
	for (string x : this->courses)
	{
		cout << x << endl;
	}
	cout << "" << endl;
}

void Teacher::print_details() // print all teacher details
{
	cout << "A teacher: " << endl;
	cout << "name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "ID: " << this->id << endl;
	cout << "teaching seniority: " << this->t_seniority << endl;
	cout << "number of courses: " << this->num_courses << endl;
	this->print_courses();
	cout << "salary: " << this->get_salary() << endl;
	if (this->check_if_excel())
	{
		cout << "the teacher excels. "<< endl;
	}
	else
	{
		cout << "the teacher not excels. " << endl;
	}
	cout << "" << endl;
}

