#include "Pupil.h"
#pragma once
//#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;


Pupil::Pupil():Person()  // default constructor
{
	vector <int> v;
	this->Class = 0;
	this->layer = '-';
	this->grades = v;
}

Pupil::Pupil(string fn, string ln, int ID, vector <int> Grades, char Grade, int Cl):Person(fn, ln, ID)
{
	//  constructor
	this->grades = Grades;
	this->layer = Grade;
	this->Class = Cl;
}

Pupil::~Pupil()
{
	//
}

bool Pupil::check_if_excel()  // check if the pupil excel
{
	for (int x : this->grades)
	{
		if (x<65)
		{
			return false;
		}
	}
	if (this->get_average() < 85)
	{
		return false;
	}
	return true;
}

float Pupil::get_average()  // get pupil average function
{
	float sum = 0;
	for (int x : this->grades)
	{
		sum += x;
	}
	return (sum / this->grades.size());
}

void Pupil::print_details() // print all pupil detais function
{
	cout << "name: " << this->get_fname() << " " << this->get_lname() << endl;
	cout << "ID: " << this->id << endl;
	cout << "layer: " << this->layer << endl;
	cout << "class: " << this->Class << endl;
	cout << "grades: " << endl;
	for (int x : this->grades)
	{
		cout << x << "  " ;
	}
	cout << "" << endl;
	cout << "average: " << this->get_average() << endl;
	if (this->check_if_excel())
	{
		cout << "the student excels " << endl;
	}
	else
	{
		cout << "the student not excels" << endl;
	}
	cout << "" << endl;
}
