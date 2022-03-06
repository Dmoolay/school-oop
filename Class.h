/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
//#include "Tutor.h"
//#include "Worker.h"
//#include "Person.h"
//#include "Teacher.h"
#include "Pupil.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


class Tutor;
class Class
{
protected:
	char layer_name;
	int num_class;
	vector <Pupil*> students;
	int class_size;
	Tutor* teacher;

public:
	Class();
	Class(char, int, vector <Pupil*>, int, Tutor*);
	~Class();

	void add_student(Pupil*);
	Pupil get_student(int);

	// get and set function.
	void set_layer(char A) { this->layer_name = A; }
	char get_layer() { return this->layer_name; }

	void set_num_class(int A) { this->num_class = A; }
	int get_num_class() { return this->num_class; }

	//void set_students(vector <Pupil*> A) { this->students = A; }
	vector <Pupil*> get_students() { return this->students; }
	void set_students(Pupil* A)
	{
		this->students.push_back(A);
		this->class_size++;
	}

	void set_class_size(int A) { this->class_size = A; }
	int get_class_size() { return this->class_size; }

	void set_teacher(Tutor* A) { this->teacher = A; }
	Tutor* get_teacher() { return this->teacher; }
};

//#endif