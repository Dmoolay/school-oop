#pragma once
#include "Class.h"
#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class Tutor:public Teacher
{
protected:
	Class *ptr;

public:
	Tutor();
	Tutor(string, string, int, float, float, vector<string>, int, Class*);
	virtual ~Tutor();

	float get_salary();
	bool check_if_excel();
	void print_details();

	// get and set function.
	void set_ptr(Class* A) { this->ptr = A; }
	Class* get_ptr() { return this->ptr; }
};

