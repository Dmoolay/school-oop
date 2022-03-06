/* Assignment C++: 2
Author: DOR MOOLAY, ID: 205870637
Author: SNIR MOSCOVICH, ID: 206293128
*/
#pragma once
#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
using namespace std;

class Pupil: public Person
{
protected:
	vector <int> grades;
	char layer;
	int Class;

public:
	Pupil();
	Pupil(string, string, int, vector <int>, char Grade, int Cl);
	virtual ~Pupil();
	bool check_if_excel();
	float get_average();
	void print_details();

	// get and set function.
	void set_class(int A) { this->Class = A; }
	void set_grade(char A) { this->layer = A; }
	void set_grades(vector <int> A) { this->grades = A; }
	int get_class() { return this->Class; }
	char get_grade() { return this->layer; }
	vector<int> get_grades() { return this->grades; }
};
