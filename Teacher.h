#pragma once
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


class Teacher:virtual public Worker
{
protected:
	vector <string> courses;
	int num_courses;

public:
	Teacher();
	Teacher(string, string, int,  float, float, vector<string>, int);
	virtual ~Teacher();

	virtual float get_salary();
	virtual bool check_if_excel();
	void print_courses();
	virtual void print_details();

	// get and set function.
	void set_courses(vector<string> A) { this->courses = A; }
	void set_num_courses(int A) { this->num_courses = A; }

	vector<string> get_courses() { return this->courses; }
	int get_num_courses() { return this->num_courses; }
};

