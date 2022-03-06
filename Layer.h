/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
#include "Class.h"
#include "Tutor.h"
#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include "Pupil.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class Layer
{
protected:
	char Layer_name;
	int Layer_size;
	vector <Class*> classes;

public:
	Layer();
	Layer(char, int, vector <Class*>);
	~Layer();

	Class get_class(int);

	// get and set function.
	void set_Layer_name(char A) { this->Layer_name = A; }
	char get_Layer_name() { return this->Layer_name; }

	void set_Layer_size(int A) { this->Layer_size = A; }
	int get_Layer_size() { return this->Layer_size; }
	//void set_students(Pupil* A) { this->students.push_back(A); }
	void set_classes(Class* A) { this->classes.push_back(A); }
	vector <Class*> get_classes() { return this->classes; }
};

