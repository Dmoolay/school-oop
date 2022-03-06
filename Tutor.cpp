#include "Tutor.h"
#include "Teacher.h"
#include "Worker.h"
#include "Person.h"
#include "Pupil.h"
#include "Class.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

Tutor::Tutor() :Teacher()  // default constructor
{
}

Tutor::Tutor(string fn, string ln, int ID, float m, float t, vector<string> Courses, int num, Class* PTR):Worker(fn, ln, ID, m, t),Teacher(fn, ln, ID, m, t, Courses, num)
{
	// default constructor
	this->ptr = PTR;
}

Tutor::~Tutor()
{
	//
}

float Tutor::get_salary() // get salary of tutor(teacher +1000)
{
	float a = 1 + this->num_courses;
	float n = basis * (a / 10);
	return (1000 + n + 300 * this->t_seniority);
}

bool Tutor::check_if_excel()   // check if excel by tutor terms
{
	int count = 0;
	for (Pupil* x : this->ptr->get_students())
	{
		if (x->check_if_excel())
		{
			count++;
		}
	}
	if (count >= float(this->ptr->get_class_size())/2)
	{
		return true;
	}
	return false;
	
}

void Tutor::print_details()   // print all teacher details(include his pupils detail)
{
	float average = 0;
	vector <string> excel_pupils;
	string full_name;
	cout << "A tutor: " << endl;
	cout << "name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "ID: " << this->id << endl;
	cout << "teaching seniority: " << this->t_seniority << endl;
	cout << "number of courses: " << this->num_courses << endl;
	this->print_courses();
	cout << "salary: " << this->get_salary() << endl;
	if (this->ptr)
	{
		cout << "grade name: " << this->ptr->get_layer() << endl;
		cout << "class number: " << this->ptr->get_num_class() << endl;
		cout << "number of students: " << this->ptr->get_class_size() << endl;
		cout << "students: " << endl;
		for (Pupil* x : this->ptr->get_students())
		{
			x->print_details();
			average = average + x->get_average();
			if (x->check_if_excel())
			{
				full_name = x->get_fname() + " " + x->get_lname();
				excel_pupils.push_back(full_name);
			}
		}
		if (this->ptr->get_class_size() > 0)
		{
			average = average / this->ptr->get_class_size();
			cout << "class average grades: " << average << endl;
		}
		cout << "excel pupils list:  " << endl;
		for (string x : excel_pupils)
		{
			cout << x << endl;
		}
		cout << "" << endl;
		if (this->check_if_excel())
		{
			cout << "the tutor excels. " << endl;
		}
		else
		{
			cout << "the tutor not excels. " << endl;
		}
	}
	else
	{
		cout << "tutor doesnt has a class!" << endl;
		cout << "" << endl;
	}
	
	cout << "" << endl;
	average = 0;
	excel_pupils.clear();
}
