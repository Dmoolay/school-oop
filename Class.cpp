/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
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

Class::Class()  // default constructor
{
	vector<Pupil*> v;
	this->layer_name = '-';
	this->num_class = 0;
	this->students = v;
	this->class_size = 0;
	this->teacher = NULL;
}

Class::Class(char L, int C, vector<Pupil*> v, int sizee, Tutor* pteacher)  //  constructor
{
	this->layer_name = L;
	this->num_class = C;
	this->students = v;
	this->class_size = sizee;
	this->teacher = pteacher;
}

Class::~Class()
{
	//
}

void Class::add_student(Pupil* stu) // add pupil to class and increase class size by one. 
{
	this->students.push_back(stu);
	this->class_size++;
}

Pupil Class::get_student(int number)  // get a specific pupil
{
	try
	{
		if (number >= this->class_size || number < 0)
		{
			throw  number;
		}
		int j = 0;
		for (auto i = this->students.begin(); i != this->students.end() && j < this->class_size; i++, j++)
		{
			if (j == number)
			{
				return **i;
			}
		}
	}
	catch (int number)
	{
		cout << "invalid input!" << endl;
	}
}
